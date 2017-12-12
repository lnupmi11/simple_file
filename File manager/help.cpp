void FileManager::help(const std::string &command) {

	
	switch (this->command(command)) {
	case 1:
		cout « 'cp file a b - copies the specified file from the "a" in the directory "b';
		break;

	case 2:
		cout « 'rm filename - removes the file "filename" from a directory';
		break;

	case 3:
		cout « 'mv file a - moves the file to the a directory';
		break;

	case 4:
		cout « 'rmdir name - removes directory "name"';
		break;
	
	case 5:
		cout « 'mkdir name - creates a directory, and calls it "name"';
		break;

	case 6:
		cout « 'cd folder or cd - the first command goes into a folder named "folder", the second goes to the level above';
		break;

	case 7:
		cout « 'exit - closes the console';
		break;

	case 8:
		cout « 'clear - clears the console';
		break;

	case 9:
		cout « 'pwd - displays the name of the current directory';
		break;

	case 10:
		cout « 'ls - displays everything that the current directory contains  - the names of folders and files, along with file extensions';
		break;
	}
}