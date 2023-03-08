#pragma once
#include "../core/Vector.h"

class UI
{
public:
	virtual void Draw() = 0;
	Rect vec{};
	Color color{};
protected:
};