#include "SerialComConnector.h"
#include <iostream>

SerialComConnector::SerialComConnector()
	: port(io)
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
	// Send a command to the Cisco router
	write(port, buffer("show ip int brief"));
	char c[1024];
	size_t n = read(port, buffer(c, sizeof(c)));
	response = std::string(c, n);
}

const bool& SerialComConnector::IsOpen()
{
	return port.is_open();
}
