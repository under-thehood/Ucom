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

    std::string foundChars="";
   // add the entry from 0 to 255 the initial ascii character

    for (uint16_t i = 0; i < code; i++)
    {
     dict[std::string(1, char(i))]=i;
    }

   //loop through the content of the file 
    for (auto character : fileContent) {

         
            std::string charsToAdd = foundChars + character;

            // if we find the entry for the character we make found character 
            if (dict.count(charsToAdd)==1) {
                foundChars = charsToAdd;
            } else {
                encodedData.push_back(dict[foundChars]);
                dict[charsToAdd]= code++;
                foundChars = std::string(1,character);
            }
        }
        // for last character 
        if (!foundChars.empty()) {
            encodedData.push_back(dict[foundChars]);
        }

        std::fstream output("output.txt",std::ios::out| std::ios::binary);
        if(!output.is_open()){
          std::cout<<"Cannot open file"<<std::endl;
        }

        //printing encoded code

        std::cout<<"\n [";
        for (auto &&i : encodedData)
        {
          output.write(reinterpret_cast<char*>(&i),sizeof(i));
          std::cout<<i<<"  ";
        }
        std::cout<<"]"<<std::endl;
        
    
}

#endif