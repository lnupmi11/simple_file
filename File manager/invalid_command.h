#pragma once
#include <iostream>
#include <string>
class invalid_command : public std::exception
{
private:
	char* err_msg;
public:
	invalid_command(const std::string& err_msg);
	char* what();
};


invalid_command::invalid_command(const std::string& err_msg)
{
	size_t err_msg_size = err_msg.size();
	this->err_msg = new char[err_msg_size];
	for (size_t i = 0; i < err_msg_size; i++)
	{
		this->err_msg[i] = err_msg[i];
	}
}
char* invalid_command::what()
{
	return this->err_msg;
}