#pragma once
#ifndef TEXT_OBJET_H_
#define TEXT_OBJECT_H_

#include "CommonFunction.h"

class TextObject
{
public:

		TextObject();
		~TextObject();
		enum TextColor
		{
			RED_TEXT = 0,
			WHITE_TEXT = 1,
			BLACK_TEXT = 2,
		};
		bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
		void Free();

		void SetColor(Uint8 red, Uint8 green, Uint8 blue);
		void SetColor(int type);

		void RenderText(SDL_Renderer* screen, 
						int x_pos_, int y_pos_, 
						SDL_Rect* clip = NULL, 
						double angle = 0.0,
						SDL_Point* center = NULL,
						SDL_RendererFlip flip = SDL_FLIP_NONE);

		int GetWidth() const { return width_; }
		int GetHeight() const { return height_; }

		void SetText(const std::string& text) {str_ = text; }
		std::string GetText() const { return str_; };

private:

	std::string str_;
	SDL_Color text_color_;
	SDL_Texture* texture_;
	int width_;
	int height_;


};

#endif