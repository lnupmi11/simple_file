#include "FileManager.h"
#include "invalid_command.h"
#include <direct.h>
#include <windows.h>
#include <experimental/filesystem>

FileManager::FileManager()
{
	this->commands.push_back("copy");
	this->commands.push_back("remove");
	this->commands.push_back("move");
	this->commands.push_back("rmdir");
	this->commands.push_back("mkdir");
	this->commands.push_back("cd");
	this->commands.push_back("--help");
	this->commands.push_back("exit");
	this->commands.push_back("clear");
}
void FileManager::init()
{
	while (true)
	{
		try
		{
			std::string command = "";
			std::string file = "";
			std::string initPath = "";
			std::string destinationPath = "";
			std::string inp = this->input();
			std::cout << "\n  Input = [" << inp << "]\n";
			this->parse(inp, command, file, initPath, destinationPath);
			this->commandProcess(command, file, initPath, destinationPath);
		}
		catch (invalid_command& exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}
}
void FileManager::commandProcess(const std::string& command, const std::string& file, const std::string& initPath, const std::string& destinationPath)
{
	switch (this->command(command))
	{
	case 1:
		this->copy(file, initPath, destinationPath);
		break;
	case 2:
		this->remove(file, initPath);
		break;
	case 3:
		this->move(file, initPath, destinationPath);
		break;
	case 4:
		_rmdir(file.c_str());
		break;
	case 5:
		_mkdir(file.c_str());
		break;
	case 6:
		_chdir(file.c_str());
		break;
	case 7:
		this->help();
		break;
	case 8:
		return;
		break;
	case 9:
		system("cls");

	default:
		std::cerr << "Invalid command '" << command << "'\n";
		break;
	}
}
std::string FileManager::input()
{
	std::string command;
	while (true)
	{
		std::cout << std::experimental::filesystem::current_path() << "> ";
		getline(std::cin, command);
		if (command != "\0")
		{
			break;
		}
	}
	return command;
}
std::string FileManager::split(const std::string& str, size_t& pos)
{
	std::string result = "";
	size_t i;
	for (i = pos; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			pos += i + 1;
			return result;
		}
		result += str[i];
	}
	pos += i + 1;
	return result;
}
void FileManager::parse(const std::string& input, std::string& command, std::string& file, std::string& initPath, std::string& destinationPath)
{
	size_t pos = 0;
	command = this->split(input, pos);
	switch (this->command(command))
	{
	case 1:
		file = this->split(input, pos);
		initPath = this->split(input, pos);
		destinationPath = this->split(input, pos);
		break;
	case 2:
		file = this->split(input, pos);
		initPath = this->split(input, pos);
		break;
	case 3:
		file = this->split(input, pos);
		initPath = this->split(input, pos);
		destinationPath = this->split(input, pos);
		break;
	case 4:
		file = this->split(input, pos);
		break;
	case 5:
		file = this->split(input, pos);
		break;
	case 6:
		file = this->split(input, pos);
		break;
	default:
		break;
	}
}
int FileManager::command(const std::string& command)
{
	for (size_t i = 0; i < this->commands.size(); i++)
	{
		if (this->commands[i] == command)
		{
			return i + 1;
		}
	}
	throw invalid_command("Invalid command '" + command + "'.");
}
void FileManager::help()
{
	std::cout << "   [HELP]\n\n";
	for (size_t i = 0; i < this->commands.size(); i++)
	{
		std::cout << " " << i + 1 << " - " << this->commands[i] << "\n";
	}
	std::cout << "\n";
}
void FileManager::help(const std::string& command)
{

}
void FileManager::copy(const std::string& file, const std::string& from, const std::string& to)
{

}
void FileManager::move(const std::string& file, const std::string& from, const std::string& to)
{

}
void FileManager::remove(const std::string& file, const std::string& from)
{

}
