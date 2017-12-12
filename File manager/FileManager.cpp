#include "FileManager.h"
#include "invalid_command.h"
#include <direct.h>
#include <windows.h>
#include <experimental/filesystem>
#include <cstdio>

#if defined(WIN32) || defined(WIN64)

#include <direct.h>

#define getcwd _getcwd
#define chdir _chdir
#else
#include <unistd.h>
#endif

using namespace std;
namespace fs = experimental::filesystem;

FileManager::FileManager() {
	this->commands.emplace_back("cp");
	this->commands.emplace_back("rm");
	this->commands.emplace_back("mv");
	this->commands.emplace_back("rmdir");
	this->commands.emplace_back("mkdir");
	this->commands.emplace_back("cd");
	this->commands.emplace_back("help");
	this->commands.emplace_back("exit");
	this->commands.emplace_back("clear");
	this->commands.emplace_back("pwd");
	this->commands.emplace_back("ls");
}

string getCurrentDir() {
	char currentPath[FILENAME_MAX];
	getcwd(currentPath, sizeof(currentPath));
	return string(currentPath);
}

void FileManager::init() {
	bool to_exit = false;
	while (!to_exit) {
		try {
			std::string command,
				file,
				initPath,
				destinationPath,
				inp = this->input();
			//std::cout << "\n  Input = [" << inp << "]\n";
			this->parse(inp, command, file, initPath, destinationPath);
			this->commandProcess(command, file, initPath, destinationPath);
		}
		catch (invalid_command &exc) {
			std::cout << exc.what() << std::endl;
		}
	}
}

void FileManager::commandProcess(const std::string &command, const std::string &file, const std::string &initPath,
	const std::string &destinationPath) {

	//TODO change intergers to enum
	switch (this->command(command)) {
	case 1:
		this->copy(file, initPath, destinationPath);
		break;
	case 2:
		this->removeFile(file, initPath);
		break;
	case 3:
		this->move(file, destinationPath);
		break;
	case 4:
		_rmdir(file.c_str());
		break;
	case 5:
		_mkdir(file.c_str());
		break;
	case 6:
		if (chdir(file.c_str()) != 0) {
			cout << "Incorect dicectory \"" << file << '"' << endl;
		}
		break;
	case 7:
		this->help(file);
		break;
	case 8:
		exit(0);
		break;
	case 9:
		system("cls");
		break;
	case 10:
		cout << getCurrentDir() << endl;
		break;
	case 11:
		listDirectory();
		break;
	default:
		std::cerr << "Invalid command '" << command << "'\n";
		break;
	}
}

std::string FileManager::input() {
	std::string command;
	while (true) {
		std::cout << getCurrentDir() << " > ";
		getline(std::cin, command);
		if (!command.empty()) {
			break;
		}
	}
	return command;
}

vector<string> split(const string& delim, const string& toSplit)
{
	vector<string> result = vector<string>();
	unsigned long start = 0;
	unsigned long end = toSplit.find(delim, start);
	while (end != -1)
	{
		result.emplace_back(toSplit, start, end - start);
		start = end + delim.size();
		end = toSplit.find(delim, start);
	}
	result.emplace_back(toSplit, start, toSplit.size() - start);
	return result;
}

void FileManager::parse(const std::string &input, std::string &command, std::string &file, std::string &initPath,
	std::string &destinationPath) {
	size_t pos = 0;
	auto splitted = split(" ", input);
	command = splitted[0];
	switch (this->command(command)) {
	case 1:
		file = splitted[1];
		initPath = splitted[2];
		destinationPath = splitted[3];
		break;
	case 2:
		file = splitted[1];
		break;
	case 3:
		file = splitted[1];
		destinationPath = splitted[2];
		break;
	case 4:
		file = splitted[1];
		break;
	case 5:
		file = splitted[1];
		break;
	case 6:
		file = splitted[1];
		break; 
        case 7:
		file = splitted[1];
                break;
	default:
		break;
	}
}

int FileManager::command(const std::string &command) {
	for (size_t i = 0; i < this->commands.size(); i++) {
		if (this->commands[i] == command) {
			return i + 1;
		}
	}
	throw invalid_command("Invalid command '" + command + "'.");
}

void FileManager::help() {
	std::cout << "   [HELP]\n\n";
	for (size_t i = 0; i < this->commands.size(); i++) {
		std::cout << " " << i + 1 << " - " << this->commands[i] << "\n";
	}
	std::cout << "\n";
}

void FileManager::help(const std::string &command) {

}

void FileManager::copy(const std::string &file, const std::string &from, const std::string &to) {

}

void FileManager::move(const std::string &file, const std::string &to) {
	if (rename(file.c_str(), to.c_str()) != 0)
		cerr << "Error moving file: \"" << file << '"' << endl;
	else
		cout << "File \"" << file << "\" successfully moved" << endl;
}


void FileManager::listDirectory() {
	auto path = getCurrentDir();
	for (auto &p : fs::directory_iterator(path)) {
	std::cout << p.path().filename() << std::endl;
	}
}

void FileManager::removeFile(const string &file, const string &from) {
	if (remove(file.c_str()) != 0)
		cerr << "Error deleting file: \"" << file << '"' << endl;
	else
		cout << "File \"" << file << "\" successfully deleted" << endl;

}
