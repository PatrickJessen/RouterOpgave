#pragma once
#include <string>
#include <vector>
#include <thread>
#include "../core/Vector.h"
#include "Port.h"
#include "SerialConnector.h"

class Router
{
public:
	Router(const std::string& router, Rect rect, int portAmount);
	~Router();

public:
	void Connect(const std::string& comPort);
	void Close();
	const std::string& GetAssetPath() { return routerPath; }
	const Rect& GetRect() { return routerRect; }
	const std::vector<Port*>& GetPorts() { return ports; }
	void Communicate(const std::string& message, std::string& response);
	const bool& GetPower() { return power; }

private:
	void InitializePorts();
	void IsCommunicationOpen();

private:
	std::string routerPath = {};
	Rect routerRect = {};
	std::vector<Port*> ports = {};
	int portAmount = 0;
	bool power = false;
	SerialConnector serialConnector;
	std::thread t;
};