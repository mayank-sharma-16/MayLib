
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>
#include <fstream>
#include <sstream>
#include "Extra/utility.hpp"

// anonymous namespace to keep private from other files
namespace {
    
    void option_about_me(std::istringstream* flags){
        UTIL::print_file("docs/title.txt");
    }

    void option_random_data_gen(std::istringstream* flags){
        UTIL::print_file("docs/RandomDataGen.txt");
    }

    void option_random_sin(std::istringstream* flags){
        UTIL::print_file("docs/RandomSinusoidal.txt");
    }
    void option_random_gaussian(std::istringstream* flags){
        UTIL::print_file("docs/RandomGaussian.txt");
    }
}

// the only function that needs to be referenced by another file
void command_display(std::istringstream* inputs) {

    std::string option;

    if(*inputs >> option){

        if(option.compare("about-me") == 0){
            option_about_me(inputs);
        }
        else if(option.compare("RandomDataGen") == 0){
            option_random_data_gen(inputs);
        }
        else if(option.compare("RandomSin") == 0){
            option_random_sin(inputs);
        }
        else if(option.compare("RandomGaussian") == 0){
            option_random_gaussian(inputs);
        }
        else {
            std::cout << "ERROR: unrecognized option '" << option <<  "' for 'display' command" << std::endl;
        }
    }
    
    else{
        std::cout << "[insert default for display]" << std::endl;
    }
}