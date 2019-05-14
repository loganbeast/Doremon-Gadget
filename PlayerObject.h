#pragma once
#ifndef PLAYER_OBJECT_H_
#define  PLAYER_OBJECT_H_

#include "CommonFunction.h"
#include "BaseObject.h"

#define PLAYER_SPEED 3
#define START_POS_X 50
#define START_POS_Y 475

class PlayerObject : public BaseObject
{
public:
	PlayerObject();
	~PlayerObject();

	enum WalkType
	{
		WALK_RIGHT = 0,
		WALK_LEFT = 1,
		

	};

	bool LoadImage(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void HandleEvent(SDL_Event events, SDL_Renderer* screen);
	void SetClips();
	void PlayerRun();
	SDL_Rect GetRectFramePlayer();

private:
	// tăng 1 lượn bao nhiêu khi ấn sang phải , trái
	float x_val_;
	float y_val_;
	// vị  trí hiện tại
	float x_pos_;
	float y_pos_;
	// kich thước 1 frame
	int width_frame_;
	int height_frame_;

	SDL_Rect frame_clip_[10];
	Input input_type_;
	int frame_;
	int status_;
};




#endif 

