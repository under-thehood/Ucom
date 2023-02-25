#ifndef _CM_FILE_UTILS_HPP
#define _CM_FILE_UTILS_HPP
#include<iostream>
#include<fstream>
#include<sstream>

std::string readfile(std::string& filename){
    std::stringstream fileStream;
    std::fstream file(filename,std::ios::in);
    if(!file.is_open()){
        std::cout<<"Cannot open the file "<<filename<<std::endl;
        return "";
    }
    fileStream<<file.rdbuf();
   return fileStream.str();
}

#endif