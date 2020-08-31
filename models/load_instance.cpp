
#include <sstream>

namespace {

    void option_sin(std::istringstream* flags){
        
    }

}


void command_load_instance(std::istringstream* inputs){
    
    std::string option;

    if(*inputs >> option){

        if(option.compare("sin") == 0){
            option_sin(inputs);
        }
    }
}