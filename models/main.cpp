
#include "RandomDataGen/RandomDataGen.hpp"
#include "display.hpp"
#include <iostream>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sstream>
#include <string>

int command_quit() {
    char* line = readline("Quitting will delete all unsaved calculations. Are you sure you're done? [y/n] \n(maylib) > ");
    if(line && ((std::string)line).compare("y") == 0) return 0;
        return 1;
}

int main(){

    char* line;

    while(true) {

        // prompt and read line from user
        line = readline("(maylib) > ");
        if(!line) break;
        if(*line) add_history(line);

        // turn input into a string stream
        std::istringstream inputs(line);
        std::string command;

        
        if(inputs >> command){
            // quit
            if(command.compare("quit") == 0) {
                if(command_quit() == 0){
                    free(line);
                    exit(0);
                }
            }
            // display
            else if(command.compare("display") == 0) {
                command_display(&inputs);
            }
        }
        else {
            std::cout << "ERROR: unknown command entered" << std::endl;
        }
        free(line);
    }
}