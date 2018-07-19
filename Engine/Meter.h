#pragma once
#include "Graphics.h"

class Meter 
{
public:
	Meter(int in_x, int in_y) : 
		x(in_x), 
		y(in_y)
	{}
	void IncreaseLevel() 
	{
		++level;
	}
	int GetLevel() const 
	{
		return level;
	}
	void Draw(Graphics& gfx) 
	{
		gfx.DrawRectDim(x, y, level * scale, girth, c);
	}
private:
	static constexpr Color c = Colors::Blue;
	static constexpr int girth = 12;
	static constexpr int scale = 4;
	int x;
	int y;
	int level = 0;
	
};