#pragma once
#include <vector>


class MathHelpers
{
public:
	MathHelpers();
	~MathHelpers();

	static float RandFloatIn(float a, float b)
	{
		return ((b - a) * ((float)rand() / RAND_MAX)) + a;
	}
};

