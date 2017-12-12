
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
	int command(const std::string& command);
	void help(const std::string& command);
	void copy();
	void move(const std::string& file, const std::string& from, const std::string& to);
	void removeFile();
public:
	FileManager();

	void init();
	void help();
};
