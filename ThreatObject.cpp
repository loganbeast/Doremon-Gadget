#include "pch.h"
#include "ThreatObject.h"


ThreatObject::ThreatObject()
{

	 frame_ = 0 + rand() % (9 + 1 - 0); 
	 width_frame_=0;
	 height_frame_ = 0;
	 x_pos_ = threat_pos_val[frame_];
	 y_pos_ = rand() % (100) - 100 ;
	// threat_speed = 4;

}
ThreatObject::~ThreatObject()
{
	BaseObject::Free();
}

bool ThreatObject::LoadImage(std::string path, SDL_Renderer* screen)
{
	bool ret = BaseObject::LoadImage(path, screen);
	if (ret)
	{
		width_frame_ = rect_.w / THREAT_FRAME_NUM;
		height_frame_ = rect_.h;
	}
	return ret;
}
SDL_Rect ThreatObject::GetRectFrameThreat()
{
	SDL_Rect rect;
	rect.x = rect_.x;
	rect.y = rect_.y;
	rect.w = width_frame_;
	rect.h = height_frame_;
	return rect;
}
void ThreatObject::SetClips()
{
	if (width_frame_ > 0 && height_frame_ > 0)
	{
		for (int i = 0; i < THREAT_FRAME_NUM; i++)
		{
			frame_clip_[i].x = i * width_frame_;
			frame_clip_[i].y = 0;
			frame_clip_[i].w = width_frame_;
			frame_clip_[i].h = height_frame_;
		}
	}
}
void ThreatObject::Show(SDL_Renderer* des)
{
	
		LoadImage("img//threatobject.png", des);
	
		rect_.x = x_pos_;
		rect_.y = y_pos_;


	SDL_Rect* current_clip = &frame_clip_[frame_];

	SDL_Rect renderQuad = { rect_.x,rect_.y,width_frame_,height_frame_ };

	SDL_RenderCopy(des, p_object_, current_clip, &renderQuad);
}
void ThreatObject::ThreatsFall()
{
	
	y_pos_ += THREAT_FALL_SPEED;
	if (y_pos_ > SCREEN_GROUND)
	{
		frame_ = 0 + rand() % (9 + 1 - 0);
		width_frame_ = 0;
		height_frame_ = 0;
		x_pos_ = threat_pos_val[frame_];
		y_pos_ = rand() % (100) - 100;
		
	}
}



