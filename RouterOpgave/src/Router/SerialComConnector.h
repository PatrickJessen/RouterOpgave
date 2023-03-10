#pragma once
#include <string>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

class SerialComConnector : public std::enable_shared_from_this<SerialComConnector>
{
public:
	SerialComConnector();
	~SerialComConnector();
public:
	void Open(std::string serialComPort);
	void Close();
	void Communicate(std::string msg, std::string& response);
	const bool& IsOpen();
private:
    void start_receive();

	void handle_receive();

private:
	io_service io;
	serial_port port;
	unsigned char buf[1024];
};