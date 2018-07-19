#pragma once

#include "Graphics.h"
#include "Dude.h"

class Goal 
{
public:
	Goal(int in_x, int in_y)
		:
		x(in_x),
		y(in_y)
	{}
	void Draw(Graphics& gfx) const
	{
		gfx.DrawRectDim(x, y, dimension, dimension, c);
	}
	bool TestCollision(const Dude& dude) const 
	{
		return
			x <= dude.GetX() + dude.GetWidth() &&
			y <= dude.GetY() + dude.GetHeight() &&
			x + dimension >= dude.GetX() &&
			y + dimension >= dude.GetY();
	}
	void Respawn(int in_x, int in_y) 
	{
		x = in_x;
		y = in_y;
	}
	void UpdateColor() 
	{
		if (colorIncreasing)
		{
			if (c.GetR() >= 253) 
			{
				colorIncreasing = false;
			}
			else
			{
				c = Color(c.GetR() + 2, c.GetG() + 4, c.GetB() + 4);
			}
		}
		else
		{
			if (c.GetR() <= 127)
			{
				colorIncreasing = true;
			}
			else
			{
				c = Color(c.GetR() - 2, c.GetG() - 4, c.GetB() - 4);
			}
		}
	}

private:
	static constexpr int dimension = 20;
	Color c = { 127, 0, 0 };
	bool colorIncreasing = true;
	int x;
	int y;
};