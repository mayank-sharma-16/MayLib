#include <string>
#include <fstream>
#include <iostream>
#include "utility.hpp"

void UTIL::print_file(std::string filename){
    std::ifstream title_file;
    title_file.open(filename);

    if(title_file.is_open()){

        std::string line;

        while( getline(title_file, line) ){
            std::cout << line << std::endl;
        }
        
        title_file.close();
    }
}
