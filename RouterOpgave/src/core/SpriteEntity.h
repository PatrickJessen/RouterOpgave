#pragma once
#include <string>
#include "Vector.h"

class SpriteEntity
{
public:
	SpriteEntity(const std::string& imgPath, Rect rect, int layer)
		: imgPath(imgPath), rect(rect), layer(layer)
	{}

	std::string imgPath{};
	Rect rect;
	int layer;
};