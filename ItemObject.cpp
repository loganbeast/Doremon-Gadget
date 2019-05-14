#include "pch.h"
#include "ItemObject.h"

ItemObject::ItemObject()
{
	num_x_pos_ = 0 + rand() % (10 + 1 - 0);
	num_img_ = 0 + rand() % (6 + 1 - 0);
	x_pos_ = item_pos_val[num_img_];
	y_pos_ = 0;
}
ItemObject::~ItemObject()
{
	BaseObject::Free();
}

bool ItemObject::LoadImage(std::string path, SDL_Renderer* screen)
{
	bool ret = BaseObject::LoadImage(path, screen);
	if(ret == true)
		return ret;

}

void ItemObject::Show(SDL_Renderer* des)
{

	LoadImage(item_object[num_img_], des);

	rect_.x = x_pos_;
	rect_.y = y_pos_;

	SDL_Rect renderQuad = { rect_.x,rect_.y,rect_.w,rect_.h };

	SDL_RenderCopy(des, p_object_, NULL, &renderQuad);

	
}
SDL_Rect ItemObject::GetRectFrameItem()
{
	SDL_Rect rect;
	rect.x = rect_.x;
	rect.y = rect_.y;
	rect.w = rect_.w;
	rect.h = rect_.h;
	return rect;
}
void ItemObject::ItemsFall()
{
	y_pos_ += ITEM_FALL_SPEED;
	if (y_pos_ > SCREEN_GROUND)
	{
		num_img_ = 0 + rand() % (6 + 1 - 0); //  1 -> 6 
		x_pos_ = item_pos_val[getNum_x_pos_()]; 
		y_pos_ = rand()%100 - 100;
	}
	
}