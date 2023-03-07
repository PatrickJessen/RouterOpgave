#pragma once
#include "../core/Vector.h"
#include <string>

enum class PortType { WAN, LAN, CONSOLE, USB };

class Port
{
public:
	Port(PortType type, Rect rect, const std::string& comPort);
	Port() = default;

public:
	const Rect& GetRect() { return rect; }
	const PortType& GetPortType() { return type; }
	const std::string& GetComPort() { return comPort; }
	void Communicate(const std::string msg, std::string& response);
private:
	PortType type = {};
	Rect rect = {};
	std::string comPort = {};
};