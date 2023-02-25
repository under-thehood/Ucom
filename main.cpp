#include <iostream>
#include <vector>
#include"lzw/compress.hpp"
#include"lzw/decompress.hpp"

void displayHelp()
{
    std::cout << "Usage: cm [options] file " << std::endl;
    std::cout << "Options:    " << std::endl;
    std::cout << "   -c       Compress the file" << std::endl;
    std::cout << "   -d       Decompress the file" << std::endl;
    exit(1);
}


void parseCommandLine(std::vector<std::string> &arguments)
{
    size_t argumentsLen = arguments.size();
    for (size_t i = 0; i < argumentsLen; i++)
    {
        if (arguments[i] == "-c")
        {
            if(++i == argumentsLen){
                std::cout<<"Insufficient argument! Please provide filename!"<<std::endl;
                displayHelp();
            }
            compress(arguments[i]);
        }
        else if (arguments[i] == "-d")
        {
             if(++i == argumentsLen){
                std::cout<<"Insufficient argument! Please provide filename!"<<std::endl;
                displayHelp();
            }
            decompress(arguments[i]);
            
        }
        else
        {
            std::cout << "Unknown option: " << arguments[i] << std::endl;
            displayHelp();
        }
    }
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> commandArgument;

    if (argc < 2)
    {
        std::cout << argv[0]<<": Invalid Option!!" << std::endl;
        displayHelp();
    }

    for (size_t i = 1; i < argc; i++)
    {
        commandArgument.push_back(argv[i]);
    }
    parseCommandLine(commandArgument);

    return 0;
}
