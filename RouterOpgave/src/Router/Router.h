#pragma once
#include <string>
#include <vector>
#include "../core/Vector.h"
#include "Port.h"

class Router
{
public:
	Router(const std::string& router, Rect rect, int portAmount);
	~Router();

public:
	const std::string& GetAssetPath() { return routerPath; }
	const Rect& GetRect() { return routerRect; }
	const std::vector<Port*>& GetPorts() { return ports; }

private:
	void InitializePorts();

private:
	std::string routerPath = {};
	Rect routerRect = {};
	std::vector<Port*> ports = {};
	int portAmount = 0;
};