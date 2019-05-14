#pragma once
#ifndef SETTING_FPS_H_

#define SETTING_FPS_H_

class SetTime
{
public:
	SetTime();
	~SetTime();

	void start();
	void stop();
	void paused();
	void unpaused();

	int get_ticks();
	bool is_paused();
	bool is_started();

private:
	// thời điểm bắt đầu chạy
	int start_ticks_;
	// thời điểm tạm dừng
	int paused_ticks_;
	
	// kiểm tra 
	bool is_paused_;
	bool is_started_;

};






#endif // !1
