#pragma once
#ifndef THREAT_OBJECT_H_
#define THREAT_OBJECT_H_

#include "CommonFunction.h"
#include "BaseObject.h"

#define THREAT_FRAME_NUM 10
#define THREAT_FALL_SPEED 4

const int threat_pos_val[10] = { 0,50,100,150,200,250,300,350,400,450 };

class ThreatObject : public BaseObject
{
public:
	ThreatObject();
	~ThreatObject();

	bool LoadImage(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void SetClips();
	void ThreatsFall();
	//int ThreatSpeedUp();

	
	SDL_Rect GetRectFrameThreat();
	void Setx_pos_(float x_) { x_pos_ = x_; }
	void Sety_pos_(float y_) { y_pos_ = y_; }
private:
	int frame_;
	int width_frame_;
	int height_frame_;
	SDL_Rect frame_clip_[THREAT_FRAME_NUM];
	
	float x_pos_;
	float y_pos_;

	//int threat_speed;


};
#endif // !1
