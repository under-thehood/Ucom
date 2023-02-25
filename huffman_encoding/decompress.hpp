#ifndef _CM_HUFFMAN_DECOMPRESS_HPP
#define _CM_HUFFMAN_DECOMPRESS_HPP
#include<iostream>
#include"../common/fileutils.hpp"
#include"tree.hpp"

void decompress(std::string &filename) {
    std::string fileContent;
   
    std::cout<<"Decompressing file.. "<<filename<<std::endl;
    fileContent=readfile(filename);
   std::cout<<"File Content:"<<fileContent<<std::endl; 
}



#endif