#include <iostream>
#include "FileManager.h"
using namespace std;

void FileManager::help(const std::string &command) {

	if (command == "")
	{
		this->help();
	}
	else
	{
		switch (this->command(command)) {
		case 1:
			cout << "cp file a b - copies the specified file from the 'a' in the directory 'b'\n";
			break;

		case 2:
			cout << "rm filename - removes the file 'filename' from a directory\n";
			break;

		case 3:
			cout << "mv file a - moves the file to the a directory\n";
			break;

		case 4:
			cout << "rmdir name - removes directory 'name'\n";
			break;

		case 5:
			cout << "mkdir name - creates a directory, and calls it 'name'\n";
			break;

		case 6:
			cout << "cd folder or cd - the first command goes into a folder named 'folder', the second goes to the level above\n";
			break;

		case 7:
			cout << "help or help command - first lists all available commands, second, as You can see, explains how specific command works\n";
			break;

		case 8:
			cout << "exit - closes the console\n";
			break;

		case 9:
			cout << "clear - clears the console\n";
			break;

		case 10:
			cout << "pwd - displays the name of the current directory\n";
			break;
		case 11:
			cout << "ls - displays everything that the current directory contains  - the names of folders and files, along with file extensions\n";
			break;
		}
	}
}