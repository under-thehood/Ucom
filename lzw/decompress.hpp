#ifndef _CM_LZW_DECOMPRESS_HPP_
#define _CM_LZW_DECOMPRESS_HPP_
#include "../common/fileutils.hpp"

void decompress(std::string &filename)
{
    std::vector<uint16_t> encodedText;
    uint16_t encodedData;
    std::cout << "Decompressing file.. " << filename << std::endl;
    std::fstream file(filename, std::ios::in);
    if (!file.is_open())
    {
        std::cout << "Cannot open the file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    while (!file.eof())
    {
        file.read(reinterpret_cast<char *>(&encodedData), sizeof(encodedData));
        encodedText.push_back(encodedData);
    }
    encodedText.pop_back();
    std::cout<<"File data is:\n";
     std::cout<<"\n [";
    for (auto &&i : encodedText)
    {
        std::cout<<i<<"  ";
    }
    std::cout<<"]"<<std::endl;

   uint16_t dictSize = 256;
         std::unordered_map<uint16_t, std::string> dictionary;
         for (int i = 0; i < dictSize; i++) {
             dictionary[i]= std::string(1,char(i));
         }

           std::string characters = std::string(1,encodedText[0]);
           std::string result=characters;
           for (size_t i = 1; i < encodedText.size(); i++)
           {
             std::string entry=dictionary.count(encodedText[i])==1 ? dictionary[encodedText[i]]: characters + characters[0];
             result.append(entry);
              dictionary[dictSize++] = characters + entry[0];
              characters = entry;
           }

        std::cout<<"Decoded Data is:\n"<<result<<std::endl;
   
}

#endif