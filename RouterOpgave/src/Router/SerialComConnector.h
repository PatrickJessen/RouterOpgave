#pragma once
#include <string>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

class SerialComConnector
{
public:
	SerialComConnector();
public:
	void Open(std::string serialComPort);
	void Close();
	void Communicate(std::string msg, std::string& response);
	const bool& IsOpen();

private:
	io_service io;
	serial_port port;
};