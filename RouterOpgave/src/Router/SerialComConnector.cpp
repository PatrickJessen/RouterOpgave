#include "SerialComConnector.h"
#include <iostream>

SerialComConnector::SerialComConnector()
	: port(io)
{
	
}

SerialComConnector::~SerialComConnector()
{
	
}

void SerialComConnector::Open(std::string serialComPort)
{
	try
	{

		// Configure the serial port settings
		port.open(serialComPort); // replace with the correct serial port name
		port.set_option(serial_port_base::baud_rate(9600));
		port.set_option(serial_port_base::character_size(8));
		port.set_option(serial_port_base::parity(serial_port_base::parity::none));
		port.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void SerialComConnector::Close()
{
	// Close the serial port
	port.close();
}

void SerialComConnector::Communicate(std::string msg, std::string& response)
{
	if (IsOpen()) {
		 //Send a command to the Cisco router
		write(port, buffer("show ip int brief\n"));
		Sleep(500);
		char c[1024];
		size_t n = read(port, buffer(c, sizeof(c)));
		response = std::string(c, n);
		//bool test = PurgeComm(port.native_handle(), 1);
		//std::cout << "flag: " << test << "\n";
	}
	else {
		std::cout << "Port closed\n";
	}
}

const bool& SerialComConnector::IsOpen()
{
	return port.is_open();
}

void SerialComConnector::start_receive()
{
	/*port.async_read_some(boost::asio::buffer(buf),
		boost::bind(&SerialComConnector::handle_receive,
			this, boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));*/
}

void SerialComConnector::handle_receive()
{
	auto self(shared_from_this());
	async_read(port, buffer(buf, 1024),
		[this, self](boost::system::error_code ec,
			std::size_t length) {
				if (!ec) {
					
				}
				else {
					// Handle read error
				}
		});
	handle_receive();
}
