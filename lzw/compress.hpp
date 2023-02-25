#ifndef _CM_LZW_COMPRESS_HPP_
#define _CM_LZW_COMPRESS_HPP_
#include"../common/fileutils.hpp"
#include<unordered_map>
#include<vector>

void compress(std::string& filename){
  std::cout << "Compressing file.. " << filename << std::endl;

    std::string fileContent = readfile(filename);
    std::unordered_map<std::string,uint16_t> dict;
    std::vector<uint16_t> encodedData;

    uint16_t code=256;

    std::string current="",next="";

    for (size_t i = 0; i < fileContent.length(); i++)
    {
            
    }
    
    
}

#endif