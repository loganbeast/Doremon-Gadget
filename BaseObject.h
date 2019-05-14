//#pragma once
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFunction.h"

class BaseObject
{
public:
	BaseObject(); // constructor
	~BaseObject(); // destructor

	void SetRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; } // Thiết lập kích thước ảnh Rect
	SDL_Rect GetRect() const { return rect_; } // Lấy ra kích thước ảnh 

	SDL_Texture* GetObject() const { return p_object_; } // Lấy ra baseobject

	virtual bool LoadImage(std::string path, SDL_Renderer* screen); //  hàm load ảnh 
	void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL); // hàm render
	void Free(); // hàm giải phóng class

protected:
	SDL_Texture* p_object_; // hình ảnh
	SDL_Rect rect_; // kích thước ảnh

};


#endif // !BASE_OBJECT_H_

