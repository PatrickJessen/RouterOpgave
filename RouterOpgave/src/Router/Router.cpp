#include "Router.h"


Router::Router(const std::string& router, Rect rect, int portAmount)
	: routerPath(router), routerRect(rect), portAmount(portAmount)
{
	InitializePorts();
	t = std::thread(&Router::IsCommunicationOpen, this);
}

Router::~Router()
{
	for (int i = 0; i < portAmount; i++) {
		delete ports[i];
	}
	t.join();
}

void Router::Connect(const std::string& comPort)
{
	serialConnector.Open(comPort);
}

void Router::Close()
{
	serialConnector.Close();
}

void Router::IsCommunicationOpen()
{
	while (true)
	{
		if (serialConnector.IsOpen()) {
			power = true;
		}
		else {
			power = false;
		}
	}
}

void Router::Communicate(const std::string& message, std::string& response)
{
	try
	{
		serialConnector.Communicate(message, response);
	}
	catch (std::exception e)
	{
		response = e.what();
	}
}

void Router::InitializePorts()
{
	int space = 0;
	int nextLine = 0;
	for (int i = 0; i < portAmount; i++) {
		if (i == portAmount / 2) {
			nextLine = 60;
			space = 0;
		}
		Rect r = { routerRect.X + (routerRect.W / 2 - 50) + space, routerRect.Y + 50 + nextLine, 40, 40 };
		std::string s = "COM";
		s.append(std::to_string(i));
		ports.push_back(new Port(PortType::CONSOLE, r, s));
		space += 50;
	}
}
