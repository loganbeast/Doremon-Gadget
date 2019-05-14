#include "pch.h"
#include "CommonFunction.h"
#include "BaseObject.h"

BaseObject::BaseObject()
{
	p_object_ = NULL;
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
}

BaseObject::~BaseObject()
{
	Free();
}

bool BaseObject::LoadImage(std::string path, SDL_Renderer* screen)
{	
	SDL_DestroyTexture(p_object_);
	// khởi tạo 1 texture để lưu ảnh từ surface
	SDL_Texture* new_texture = NULL;
	// load ảnh vào surface từ Ram
	SDL_Surface* load_surface = IMG_Load(path.c_str());
	if (load_surface != NULL)
	{
		//colourkey xóa nền của object nhân vật
		//SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B)); 
		//tạo texture từ surface 
		new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
		if (new_texture != NULL)
		{
			// lưu kích thước thực của tấm ảnh vào rect 
			rect_.w = load_surface->w;
			rect_.h = load_surface->h;
		}
		//giải phóng surface khi đã sử dụng xong
		SDL_FreeSurface(load_surface);

	}
	// lưu texture quá p_object_
	p_object_ = new_texture;
	return p_object_ != NULL;
}

// Hàm vẽ texture ra màn hình
void BaseObject::Render(SDL_Renderer* des, const SDL_Rect* clip)
{
	// hàm lưu kích thước của Texture
	SDL_Rect renderquad = { rect_.x, rect_.y, rect_.w, rect_.h };
	// hàm đẩy toàn bộ texture p_object_ với kích thước lưu trọng renderquad vào renderer des để vẽ ra màn hình 
	SDL_RenderCopy(des, p_object_, clip, &renderquad);

}
// Hàm giải phóng cho destructor
void BaseObject::Free()
{
	if (p_object_ != NULL)
	{
		SDL_DestroyTexture(p_object_);
		p_object_ = NULL;
		rect_.w = 0;
		rect_.h = 0;
	}
}















