#pragma once
#include <thread>
#include "Router/Router.h"
#include "SDL.h"

class RouterManager
{
public:
	RouterManager();
	~RouterManager();

public:
	Router* GetRouter() { return router; }
	void CommunicateThroughPort(const std::string& command, std::string& response);
private:
	void OnPortClick();

private:
	Router* router = nullptr;
	Port* activePort = nullptr;
	std::thread t;
};