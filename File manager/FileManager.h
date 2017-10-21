#pragma once
#include <string>
#include <vector>
class FileManager
{
private:
	std::vector<std::string> commands;
	void commandProcess(const std::string& command, const std::string& file, const std::string& initPath, const std::string& destinationPath);
	std::string input();
	void parse(const std::string& input, std::string& command, std::string& file, std::string& initPath, std::string& destinationPath);
	std::string split(const std::string& str, size_t& pos);
	int command(const std::string& command);
	void help();
	void help(const std::string& command);
	void copy(const std::string& file, const std::string& from, const std::string& to);
	void move(const std::string& file, const std::string& from, const std::string& to);
	void remove(const std::string& file, const std::string& from);
public:
	FileManager();
	void init();
};