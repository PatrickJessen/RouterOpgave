#pragma once
#include <string>

class SerialConnector
{
public:
	SerialConnector() = default;
	~SerialConnector() = default;

public:
	void Open(std::string serialComPort);
	void Close();
	void Communicate(std::string msg, std::string& response);
	const bool& IsOpen();
};