#pragma once
#ifndef ITEM_OBJECT_H_
#define ITEM_OBJECT_H_

#include "CommonFunction.h"
#include "BaseObject.h"

#define ITEM_FALL_SPEED 2

const std::string item_object[6] = { "img//item0.png" , "img//item1.png" , "img//item2.png" ,"img//item3.png" ,"img//item4.png" , "img//item5.png" };
const int item_pos_val[10] = { 0,50,100,150,200,250,300,350,400,450 };

class ItemObject : public BaseObject
{
public:
	ItemObject();
	~ItemObject();

	bool LoadImage(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void ItemsFall();
	int getNum_img_() { return num_img_; }
	int getNum_x_pos_() { return num_x_pos_; }
	SDL_Rect GetRectFrameItem();
	void Setx_pos_(float x_) { x_pos_ = x_; }
	void Sety_pos_(float y_) { y_pos_ = y_; }
private:
	int num_x_pos_;
	int num_img_;
	float x_pos_;
	float y_pos_;
	
};

#endif // !1
