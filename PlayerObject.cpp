#include "pch.h"
#include "PlayerObject.h"

PlayerObject::PlayerObject()
{
	frame_ = 0;
	x_pos_ = START_POS_X;
	y_pos_ = START_POS_Y;
	x_val_ = 0;
	y_val_ = 0;
	width_frame_ = 0;
	height_frame_ = 0;
	status_ = -1;
	input_type_.left_ = 0;
	input_type_.right_ = 0;
}
PlayerObject::~PlayerObject()
{
	BaseObject::Free();
}
bool PlayerObject::LoadImage(std::string path, SDL_Renderer* screen)
{
	bool ret = BaseObject::LoadImage(path, screen);

	if (ret == true) 
	{
		width_frame_ = rect_.w / FRAME_NUMBER;
		height_frame_ = rect_.h;
	
	}
	return ret;

}
SDL_Rect PlayerObject::GetRectFramePlayer()
{
	SDL_Rect rect;
	rect.x = rect_.x;
	rect.y = rect_.y;
	rect.w = width_frame_;
	rect.h = height_frame_;
	return rect;
}
void PlayerObject::SetClips()
{
	if (width_frame_ > 0 && height_frame_ > 0)
	{
		for (int i = 0; i < FRAME_NUMBER; i++)
		{
			frame_clip_[i].x = i*width_frame_;
			frame_clip_[i].y = 0;
			frame_clip_[i].w = width_frame_;
			frame_clip_[i].h = height_frame_;
		}
	}
}
void PlayerObject::Show(SDL_Renderer* des)
{
	if (status_ == WALK_LEFT)
	{
		LoadImage("img//playerleft.png", des);
	}
	else
	{
		LoadImage("img//playerright.png", des);
	}
	if (input_type_.left_ == 1 || input_type_.right_ == 1)
	{
		frame_++;
	}
	else
	{
		frame_ = 0;
	}
	
	if (frame_ >= FRAME_NUMBER)
	{
		frame_ = 0;
	}
	
	rect_.x = x_pos_;
	rect_.y = y_pos_; 
	

	SDL_Rect* current_clip = &frame_clip_[frame_];

	SDL_Rect renderQuad = { rect_.x,rect_.y,width_frame_,height_frame_ };

	SDL_RenderCopy(des, p_object_, current_clip, &renderQuad);
}
void PlayerObject::HandleEvent(SDL_Event events, SDL_Renderer* screen)
{
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_RIGHT:
		{
			status_ = WALK_RIGHT;
			input_type_.right_ = 1;
			input_type_.left_ = 0;
		}
		break;
		case SDLK_LEFT:
		{
			status_ = WALK_LEFT;
			input_type_.left_ = 1;
			input_type_.right_ = 0;
		}
		break;
		}
	}
	else if (events.type == SDL_KEYUP)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_RIGHT:
		{
			
			input_type_.right_ = 0;
		
		}
		break;
		case SDLK_LEFT:
		{
			input_type_.left_ = 0;
		}
		break;
		}
	}
}
void PlayerObject:: PlayerRun()
{
	
	if ( x_pos_ <= 0 )
	{
		if (input_type_.left_ == 1)
		{
			x_pos_ -= 0;
		}
		else if(input_type_.right_ == 1)
		{
			x_pos_ += PLAYER_SPEED;
		}
	}
	else if(  x_pos_ >= 450)
	{
		if (input_type_.left_ == 1)
		{
			x_pos_ -= PLAYER_SPEED;
		}
		else if (input_type_.right_ == 1)
		{
			x_pos_ += 0;
		}
	}
	else
	
	{
		if (input_type_.left_ == 1)
		{
			x_pos_ -= PLAYER_SPEED;
		}
		else if (input_type_.right_ == 1)
		{
			x_pos_ += PLAYER_SPEED;
		}
	}

}