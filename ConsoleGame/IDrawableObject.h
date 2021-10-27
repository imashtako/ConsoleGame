#pragma once

#include "Plane.h"

class IDrawableObject
{
public:
	virtual void Draw(Plane& plane) = 0;
	const int layer;
protected:
	IDrawableObject(int _layer) : layer(_layer) {};
};

