#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <unistd.h>

inline bool exists(const std::string& name)
{
	std::ifstream f(name.c_str());
	return f.good();
}

const std::vector<std::string> parsefile(const std::string& name) {
	std::ifstream f(name);
	std::string current;
	std::vector<std::string> s;
	while (true) {
		f >> current;
		if (f.eof())
			break;
		else
			s.push_back(current);	
	}
	return s;
}	

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "rotwal: bad usage" << std::endl;
		return -1;
	}
	if (!exists("rotwal.conf")) {
		std::cout << "rotwal: no config file could be found" << std::endl;
		return -1;
	}
	if (argv[1] == "0") {
		std::cout << "rotwal: arg cannot be 0" << std::endl;
		return -1;
	}
	if (atoi(argv[1]) == 0) {
		std::cout << "rotwal: arg must be an integral number" << std::endl;
		return -1;
	}	

	if (argv[1] == "-h" || argv[1] == "--help") {
		std::cout << "usage: \"rotwal [SECONDS]\n\tSECONDS between rotating wallpapers\n\trotwal.conf should have the path of each desired wallpaper separated by a newline\n" << std::endl;
		return 0;
	}

	std::vector<std::string> pictures = parsefile("rotwal.conf");
	for (auto& i : pictures) {
		if (!exists("/home/" + static_cast<std::string>(getenv("USER")) + "/" + i)) {
			std::cout << "rotwal: \"" << i << "\" does not exist" << std::endl;
			return -1;
		}
	}

	std::string com;
	srand(time(NULL));
	while (true) {
		com = "wal -i /home/" + static_cast<std::string>(getenv("USER")) + "/" + pictures.at(rand() % pictures.size());
		system(com.c_str());
		usleep(atoi(argv[1]) * 10000000);
	}

	return 0;	
}	
