#include <getopt.h>
#include <iostream>

int size;
std::string file;
bool help_flag = true;
bool size_flag = true;
bool file_flag = true;

void ProcessArgs(int argc, char** argv)
{
    const char* const short_opts = "hs::f::";
    const option long_opts[] = {
            {"help", no_argument, NULL, 'h'},
            {"size", optional_argument, NULL, 's'},
            {"file", optional_argument, NULL, 'f'},
            {NULL, 0, NULL, 0}
    };

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (opt == -1)
            break;

        switch (opt)
        {
        case 'h':
	    if (help_flag)
		help_flag = false;
	    else
		break;
            std::cout << "Arg: Help " << std::endl;
            break;

        case 's':
	    if(size_flag)
		size_flag = false;
	    else
		break;
	    if (optarg!=NULL){
            	size = std::stoi(optarg);
            	std::cout << "Arg: Size equals " << size << std::endl;}
	    else
		std::cout << "Arg: Size without arguments " << std::endl;
            break;

        case 'f':
	    if (file_flag)
		file_flag = false;
	    else
		break;
	    if (optarg!=NULL){
            	file = std::string(optarg);
            	std::cout << "Arg: File equals " << file << std::endl;}
	    else
		std::cout << "Arg: File without arguments " << std::endl;
            break;

        case '?':
		std::cout << "Argument was not recognized" << std::endl;
        default:
            break;
        }
    }
}

int main(int argc, char **argv)
{
    ProcessArgs(argc, argv);
    return 0;
}
