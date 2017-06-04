#include <mutex>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "unistd.h"
#include <sys/stat.h>

void write_to_file (const std::string & message) {
    // mutex to protect file access (shared across threads)
    static std::mutex mutex;

    // lock mutex before accessing file
    std::lock_guard<std::mutex> lock(mutex);

    // try to open file
    std::ofstream file("example.txt");
    if (!file.is_open())
        throw std::runtime_error("unable to open file");

    // write message to file
    file << message << std::endl;

    // file will be closed 1st when leaving scope (regardless of exception)
    // mutex will be unlocked 2nd (from lock destructor) when leaving
    // scope (regardless of exception)
}

void create_to_file (std::string dir_name)
{
	if(0 != access(dir_name.c_str(), 0))
	{
		std::cout << dir_name << " no exist!" << std::endl;
		mkdir(dir_name.c_str(), 0775);
	}
}

int main()
{
	write_to_file("成功打开文件～");
	//const char* dir_name = "./dir";
	create_to_file("/data/lootingdata");

	return 0;
}
