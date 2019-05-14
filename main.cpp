// DemoStickyRun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include"CommonFunction.h"
#include "BaseObject.h"
#include"PlayerObject.h"
#include"SettingFps.h"
#include "ThreatObject.h"
#include "ItemObject.h"
#include "TextObject.h"
#include "LifeObject.h"

BaseObject g_background;
TTF_Font* font_time = NULL;


bool InitData()
{
	// khởi tạo flag
	bool success = true;
	// hàm khởi tạo chế độ SDL
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0)
		return false;
	// set kích thước chuẩn hco màn hình
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	// khởi tạo cửa sổ 
	g_window = SDL_CreateWindow("Sticky Run CPP SDL", SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								SCREEN_WIDTH, SCREEN_HEIGHT,
								SDL_WINDOW_SHOWN);
	if (g_window == NULL) {
		success = false;
	}
	else {
		// Khởi tạo renderer cho window
		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if (g_screen == NULL) {
			success = false;
		}
		else 
		{
			// thiết lập màu sắc cho phần renderer
			SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR); 
			// khởi tạo PNG
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags)) {
				success = false;
			}

		}
		if (TTF_Init() == -1)
		{
			success = false;

		}
		font_time = TTF_OpenFont("font/Roboto-Bold.ttf", 20);
		if (font_time == NULL)
		{
			success = false;
		}
	}
	return success;
		 
}

bool LoadBackGround()
{
	bool ret = g_background.LoadImage("img/aaaaaaaaaaaaaaaaa.jpg", g_screen);
	if(ret == false)
		return false;

	return true;
}

void close()
{
	g_background.Free();

	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;

	SDL_DestroyWindow(g_window);
	g_window = NULL;

	IMG_Quit();
	SDL_Quit();
}

std::vector<ThreatObject*> MakeThreadList()
{
	std::vector<ThreatObject*> list_threats;

	ThreatObject* threats_object = new ThreatObject[10];

	for (int i = 0; i < 10; i++)
	{
		ThreatObject* p_threat = threats_object + i;
		if (p_threat != NULL)
		{
			p_threat->LoadImage("img//threatobject.png", g_screen);
			p_threat->SetClips();
			list_threats.push_back(p_threat);
		}
	}
	

	return list_threats;
}

std::vector<ItemObject*> MakeItemList()
{
	std::vector<ItemObject*> list_items;

	ItemObject* items_object = new ItemObject[6];

	for (int i = 0; i < 6; i++)
	{
		ItemObject* p_item = items_object + i;
		if (p_item != NULL)
		{
			p_item->LoadImage(item_object[p_item->getNum_img_()], g_screen);

			list_items.push_back(p_item);
		}
	}
	return list_items;
}


int main(int argc, char* argv[])
{

	srand((int)time(0));

	SetTime fps_time;
	//bool checkk = InitData();
	if (InitData() == false)
		return -1;

	bool start = true;
	while (start)
	{
		g_background.LoadImage("img//menu.png", g_screen);
		while (SDL_PollEvent(&g_event) != 0)
		{
			if (g_event.type == SDL_KEYDOWN)
			{
				start = false;
			}
			SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
			SDL_RenderClear(g_screen);
			g_background.Render(g_screen, NULL);
			SDL_RenderPresent(g_screen);

		}
	}


	if (LoadBackGround() == false)
		return -1;

	PlayerObject p_player;
	p_player.LoadImage("img//playerright.png", g_screen);
	p_player.SetClips();

	LifeObject p_life;
	p_life.InitLife(g_screen);


	std::vector<ThreatObject*> threats_list = MakeThreadList();
	std::vector<ItemObject*> items_list = MakeItemList();

	//ItemObject item_;

	// Mark
	TextObject p_mark;
	p_mark.SetColor(TextObject::WHITE_TEXT);

	UINT mark_val = 0;

	int die_num_ = 0;

	bool is_quit = false;

	while (!is_quit)
	{
		fps_time.start();

		while (SDL_PollEvent(&g_event) != 0)
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
			}
			p_player.HandleEvent(g_event, g_screen);
			
		}
		SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
		SDL_RenderClear(g_screen);
		g_background.Render(g_screen, NULL);
		
		p_player.PlayerRun();
		p_player.Show(g_screen);
		
		p_life.Show(g_screen);

		for (int i = 0; i < threats_list.size(); i++)
		{	
			ThreatObject* p_threat = threats_list.at(i);

			if (p_threat != NULL)
			{
				bool check1 = false;

				p_threat->ThreatsFall();
				p_threat->Show(g_screen);
					
				SDL_Rect rect_threat = p_threat->GetRectFrameThreat();
				SDL_Rect rect_player = p_player.GetRectFramePlayer();

				check1 = SDLCommonFunction::CheckCollision(rect_player, rect_threat);

				if (check1 == true)
				{
					die_num_++;
		
					
					p_life.DecreaseLife();
					p_life.Render(g_screen);
				

					p_threat->Setx_pos_(threat_pos_val[RAND_NUMBER_THREAT]);
					p_threat->Sety_pos_(RAND_NUMBER);

					if (die_num_ > 3)
					{
						
						if (MessageBox(NULL, L"Game Over", L"Notice", MB_OK | MB_ICONSTOP) == IDOK)
						{
							p_life.Render(g_screen);
							die_num_ = 0;
							mark_val = 0;
							p_life.InitLife(g_screen);
							
						}
					}
				}
					
			}
		}
		for (int i = 0; i < items_list.size(); i++)
		{
			ItemObject* p_item = items_list.at(i);

			if (p_item != NULL)
			{
				bool check2 = false;

				p_item->ItemsFall(); // Xu ly roi 
				p_item->Show(g_screen); // show 

				SDL_Rect rect_player = p_player.GetRectFramePlayer();
				SDL_Rect rect_item = p_item->GetRectFrameItem();

				check2 = SDLCommonFunction::CheckCollision(rect_player, rect_item); // check va cham
				if (check2)
				{
					p_item->Setx_pos_(item_pos_val[RAND_NUMBER_ITEM]);
					p_item->Sety_pos_(RAND_NUMBER);
					mark_val++;
				}
				
			}
		}
		//Show mark
		std::string str_mark_val = std::to_string(mark_val);
		std::string str_Mark("Score: ");
		std::string mark_ = str_Mark += str_mark_val;
		p_mark.SetText(mark_);
		p_mark.LoadFromRenderText(font_time, g_screen);
		p_mark.RenderText(g_screen, SCREEN_WIDTH - 100, 20);
		
		SDL_RenderPresent(g_screen);

		// FPS
		int real_one_frame = fps_time.get_ticks();
		int theory_one_frame = 1000 / FRAME_PER_SECOND;
		if (real_one_frame < theory_one_frame)
		{
			int delay_time = theory_one_frame - real_one_frame;
			SDL_Delay(delay_time);

		}
	}
	close();
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
