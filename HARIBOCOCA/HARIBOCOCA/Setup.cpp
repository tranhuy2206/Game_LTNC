#include "Setup.h"

bool Cross_account::CheckTwoObj(const SDL_Rect &obj_1, const SDL_Rect &obj_2)
{
	int l_a = obj_1.x;
	int r_a = obj_1.x + obj_1.w;
	int t_a = obj_1.y;
	int b_a = obj_1.y + obj_1.h;

	int l_b = obj_2.x;
	int r_b = obj_2.x + obj_2.w; 
	int t_b = obj_2.y;
	int b_b = obj_2.y + obj_2.h;

	if (l_a > l_b && l_a < r_b)
	{
		if (t_a > t_b && t_a < b_b)
		{
			return true;
		}
	}

	if (l_a > l_b && l_a < r_b)
	{
		if (b_a > t_b && b_a < b_b)
		{
			return true;
		}
	}

	if (r_a > l_b && r_a < r_b)
	{
		if (t_a > t_b && t_a < b_b)
		{
			return true;
		}
	}

	if (r_a > l_b && r_a < r_b)
	{
		if (b_a > t_b && b_a < b_b)
		{
			return true;
		}
	}

	if (l_b > l_a && l_b < r_a)
	{
		if (t_b > t_a && t_b < b_a)
		{
			return true;
		}
	}

	if (l_b > l_a && l_b < r_a)
	{
		if (b_b > t_a && b_b < b_a)
		{
			return true;
		}
	}

	if (r_b > l_a && r_b < r_a)
	{
		if (t_b > t_a && t_b < b_a)
		{
			return true;
		}
	}

	if (r_b > l_a && r_b < r_a)
	{
		if (b_b > t_a && b_b < b_a)
		{
			return true;
		}
	}

	if (t_a == t_b && r_a == r_b && b_a == b_b)
	{
		return true;
	}

	return false;
}
