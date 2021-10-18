#pragma once

#include "Plane.h"

class IDrawableObject
{
public:
	virtual void Draw(Plane& plane) = 0;
};

