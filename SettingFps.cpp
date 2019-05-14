#include"pch.h"
#include "SettingFps.h"
#include "CommonFunction.h"

SetTime::SetTime()
{
	start_ticks_ = 0;
	paused_ticks_ = 0;
	is_paused_ = false;
	is_started_ = false;

}
SetTime::~SetTime()
{

}
void SetTime::start()
{
	is_started_ = true;
	is_paused_ = false;
	start_ticks_ = SDL_GetTicks();
	
}
void SetTime::stop()
{
	is_paused_ = false;
	is_started_ = false;

}
void SetTime::paused()
{
	if (is_started_ == true && is_paused_ == false)
	{
		is_paused_ = true;
		paused_ticks_ = SDL_GetTicks() - start_ticks_;
	}
}
void SetTime::unpaused()
{
	if (is_paused_ == true)
	{
		is_paused_ = false;
		start_ticks_ = SDL_GetTicks() - paused_ticks_;
		paused_ticks_ = 0;

	}
}
int SetTime::get_ticks()
{
	if (is_started_ == true)
	{
		if (is_paused_ == true)
		{
			return paused_ticks_;
		}
		else 
		{
			return SDL_GetTicks() - start_ticks_; 
		}
	}
	return 0;
}
bool SetTime::is_started()
{
	return is_started_;
}
bool SetTime::is_paused()
{
	return is_paused_;
}