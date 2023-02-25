#ifndef _CM_LZW_DECOMPRESS_HPP_
#define _CM_LZW_DECOMPRESS_HPP_
#include "../common/fileutils.hpp"



void decompress(std::string &filename)
{
    std::string fileContent;

    std::cout << "Decompressing file.. " << filename << std::endl;
    fileContent = readfile(filename);
    std::cout << "File Content:" << fileContent << std::endl;
}

#endif