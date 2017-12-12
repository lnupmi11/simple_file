void FileManager::help(const std::string &command) {

	
	switch (this->command(command)) {
	case 'rm':
		cout << 'file a - removes the file from the a directory';
		break;
	
	}
}