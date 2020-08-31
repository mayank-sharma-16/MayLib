// #define NDEBUG

#include "RandomDataGen.hpp"
#include "../Extra/CustomAssert.hpp"
#include <assert.h>
#include <iostream>
#include <vector>

void test_sin_two_vectors_returned(){

    ASSERT(RANDOM::Sinusoidal().size() == 2, "function RANDOM::Sinusoidal should return two vectors but is instead returning " + std::to_string(RANDOM::Sinusoidal().size()));
}

void test_default_sin_data_sizes(){

    std::vector<std::vector<double>> random_data = RANDOM::Sinusoidal();
    std::vector<double> random_X_data = random_data[0];
    std::vector<double> random_Y_data = random_data[1];

    ASSERT(random_X_data.size()==DEFAULT_RANDOM_DATA_SIZE, "default X array does not have predefined default size " + 
        std::to_string(DEFAULT_RANDOM_DATA_SIZE) + ", instead has " + std::to_string(random_X_data.size()));

    ASSERT(random_Y_data.size()==DEFAULT_RANDOM_DATA_SIZE, "default Y array does not have predefined default size " + 
        std::to_string(DEFAULT_RANDOM_DATA_SIZE) + ", instead has " + std::to_string(random_Y_data.size()));
}

void test_default_sin_data_range(){

    std::vector<std::vector<double>> random_data = RANDOM::Sinusoidal();
    std::vector<double> random_X_data = random_data[0];
    std::vector<double> random_Y_data = random_data[1];

    for(int i = 0; i < random_data.size(); i++){
        ASSERT(random_X_data[i] <= 1 && random_X_data[i] >= 0, "found X value out of range: " + std::to_string(random_X_data[i]));
    }
}

void test_default_norm_data_sizes(){

    int actual_size = RANDOM::Gaussian().size();

    ASSERT(RANDOM::Gaussian().size() == DEFAULT_RANDOM_DATA_SIZE, "default array does not have predefined default size " +
        std::to_string(DEFAULT_RANDOM_DATA_SIZE) + ", instead has " + std::to_string(actual_size));
}

int main(int argc, char *argv[]){

    // unit tests
    // Sinusoidal
    test_sin_two_vectors_returned();
    test_default_sin_data_sizes();
    test_default_sin_data_range();
    // Gaussian
    test_default_norm_data_sizes();

    std::cout << "============================" << std::endl;
    std::cout << "All tests completed" << std::endl;
    std::cout << "============================" << std::endl;

    // show results if "--show-data" option is specified
    if(argc > 1 && ((std::string) argv[1]).compare("--show-data")==0){

        char** index = &argv[0];

        bool sin_printed = false;
        bool gaussian_printed = false;
        
        while(*index != nullptr){      

            std::string arg = *index;

            // show sin data
            if( arg.compare("--sin")==0 && sin_printed == false){

                sin_printed = true;

                std::vector<std::vector<double>> random_data = RANDOM::Sinusoidal(10);
                std::vector<double> random_X_data = random_data[0];
                std::vector<double> random_Y_data = random_data[1];

                std::cout << std::endl;

                std::cout << "============================" << std::endl;
                std::cout << "SINUSOIDAL DATA" << std::endl;
                std::cout << "============================" << std::endl;

                for(int i = 0; i < random_X_data.size(); i++){
                    std::cout << random_X_data[i] << " " << random_Y_data[i] << std::endl;
                }
            }

            // show gaussian data
            else if( arg.compare("--gaussian")==0 && gaussian_printed == false){

                gaussian_printed = true;

                std::vector<double> random_data = RANDOM::Gaussian(10);

                std::cout << std::endl;

                std::cout << "============================" << std::endl;
                std::cout << "GAUSSIAN DATA" << std::endl;
                std::cout << "============================" << std::endl;
                
                for(int i = 0; i < random_data.size(); i++){
                    std::cout << random_data[i] << std::endl;
                }
            }

            index++;
        }
    }
}