#include"pch.h"
#include"LifeObject.h"

LifeObject::LifeObject()
{
	num_life_ = 0;
	

}
LifeObject::~LifeObject()
{

}
 void LifeObject::Addx_pos_(const int& x)
{
	pos_list_.push_back(x);
}
 void LifeObject::InitLife(SDL_Renderer* screen)
 {
	 num_life_ = 3;
	 bool ret = LoadImage("img//blueheart.png", screen);

	 if (pos_list_.size() > 0)
	 {
		 pos_list_.clear();
	 }
		 Addx_pos_(20);
		 Addx_pos_(41);
		 Addx_pos_(62);
		 Addx_pos_(83);
	 
	 
 }
 void LifeObject::Show(SDL_Renderer* screen)
 {
	 for (int i = 0; i < pos_list_.size(); i++)
	 {
		 rect_.x = pos_list_.at(i);
		 rect_.y = 20;
		 Render(screen);
	 }
 }
 void LifeObject::DecreaseLife()
 {
	 num_life_--;
	 pos_list_.pop_back();

 }
