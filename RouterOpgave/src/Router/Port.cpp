#include "Port.h"

Port::Port(PortType type, Rect rect, const std::string& comPort)
	: type(type), rect(rect), comPort(comPort)
{
}

void Port::Communicate(const std::string msg, std::string& response)
{
	
}
