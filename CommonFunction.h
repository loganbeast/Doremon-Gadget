#pragma once
#ifndef COMMON_FUNCTION_H
#define COMMON_FUCNTION_H

//#include<window.h>
#include<string>
#include <stdlib.h>
#include<ctime>
#include<windows.h>
#include <time.h>
#include<vector>
#include<fstream>
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

// screen
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 700;
const int SCREEN_GROUND = 485;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 255;
const int COLOR_KEY_G = 255;
const int COLOR_KEY_B = 255;

const int RAND_NUMBER = rand() % 100 - 100;
const int RAND_NUMBER_ITEM = rand() % 6;
const int RAND_NUMBER_THREAT = rand() % 10;

const int FRAME_NUMBER = 10;

const int RENDER_DRAW_COLOR = 0xff;

const int FRAME_PER_SECOND = 90;

#define TILE_SIZE 64

#define MAX_MAP_X 40
#define MAX_MAP_Y 10
typedef struct Input
{
	int left_;
	int right_;
	int up_;
	int down_;
	int jump_;

};

namespace SDLCommonFunction
{
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}
#endif

