#include "SerialConnector.h"
#include "SerialComConnector.h"

SerialComConnector sSerialComConnector;

void SerialConnector::Open(std::string serialComPort)
{
	sSerialComConnector.Open(serialComPort);
}

void SerialConnector::Close()
{
	sSerialComConnector.Close();
}

void SerialConnector::Communicate(std::string msg, std::string& response)
{
	sSerialComConnector.Communicate(msg, response);
}

const bool& SerialConnector::IsOpen()
{
	return sSerialComConnector.IsOpen();
}
