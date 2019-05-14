#ifndef LIFE_OBJECT_H_
#define LIFE_OBJECT_H_

#include "CommonFunction.h"
#include "BaseObject.h"

class LifeObject : public BaseObject
{
public:
	LifeObject();
	~LifeObject();

	void Setnum_life_(const int& num) { num_life_ = num; };
	void Addx_pos_(const int& x);
	void Show(SDL_Renderer* des);
	void InitLife(SDL_Renderer* screen);

	void DecreaseLife();

private:
	int num_life_;
	std::vector<int> pos_list_;

};

#endif // !1
