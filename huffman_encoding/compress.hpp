#ifndef _CM_HUFFMAN_COMPRESS_HPP
#define _CM_HUFFMAN_COMPRESS_HPP
#include <iostream>
#include <cstdint>
#include"tree.hpp"
#include "../common/fileutils.hpp"

void tmpdecompress(std::vector<uint16_t>& encodedData,node* root){
std::string uncompressData="";
node* ptr=root;
std::bitset<16> bitMan;
    for (size_t i = 0; i < encodedData.size(); i++)
    {
         bitMan=encodedData[i];
       
        for (int bitRead = 15; bitRead >= 0 ; bitRead--)
        {
            if(ptr->left==nullptr && ptr->right==nullptr){
                uncompressData += ptr->_data;
                ptr=root;
            }
          
            if(bitMan.test(bitRead)){
                ptr=ptr->right;
            }else{
                ptr=ptr->left;
            }
        }
        
    }
    std::cout<<"The uncompressed data is :\n";
    std::cout<<uncompressData<<"\n";
}


void compress(std::string &filename)
{
    std::unordered_map<uint8_t, std::string> codes;
    std::vector<uint16_t> encodedData;
    std::bitset<16> bitMan;

    std::string fileContent, code;

    std::cout << "Compressing file.. " << filename << std::endl;

    fileContent = readfile(filename);

    std::cout<<"File content:"<<fileContent<<std::endl;

    std::vector<node *> data = getFrequency(fileContent);

    auto tree = buildTheTree(data);

    printCodes(tree, code, codes);

    for (auto &&i : codes)
    {
        std::cout << i.first << ": " << i.second << "\n";
    }

    int bitWritten = 15;
    for (int fileDataIndex = 0; fileDataIndex < fileContent.length();)
    {
        std::string cod = codes[fileContent[fileDataIndex]];

            for (size_t j = 0; j < cod.length(); j++)
            {
                if (bitWritten >= 0)
                {
                    bitMan[bitWritten] = cod[j] - '0';
                    bitWritten--;
                }else{
                    encodedData.push_back(bitMan.to_ulong());
                    bitMan.reset();
                    bitWritten=15;
                    bitMan[bitWritten] = cod[j] - '0';
                    bitWritten--;
                }
            }

        fileDataIndex++;
    }
     encodedData.push_back(bitMan.to_ulong());
    std::cout<<"Encoded data is:\n";
    std::fstream outputfile("output.bin",std::ios::in|std::ios::binary);
   
    for (auto i : encodedData)
    {
       std::cout<<i<<'\t'; 
       outputfile.write(reinterpret_cast<const char *>(&i),sizeof(i));
    //    bitMan=i;
    //    outputfile<<bitMan;

    }

    tmpdecompress(encodedData,tree);
    
}

#endif