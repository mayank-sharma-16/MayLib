
#include <vector>
#include <random>
#include <cmath>
#include <iostream>
#include "RandomDataGen.hpp"

// global variables
// sets default amount of random numbers generated; must be above 0 to pass unit testing
int DEFAULT_RANDOM_DATA_SIZE = 100;
// sets default mean for distributions
double DEFAULT_RANDOM_DISTRIBUTION_MEAN = 0.0;
// sets default SD for distributions
double DEFAULT_RANDOM_DISTRIBUTION_STD = 0.3;


std::vector<std::vector<double>> RANDOM::Sinusoidal(int size){

    std::vector<double> random_X_data(size, 0.0);
    std::vector<double> random_Y_data(size, 0.0);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> u_dist(0,1);
    std::normal_distribution<double> n_dist(0,0.3);

    for(int i = 0; i < size; i++){

        double random_X = u_dist(gen);

        random_X_data[i] = random_X;
        random_Y_data[i] = sin(2*M_PI*random_X) + n_dist(gen);
    }

    return std::vector<std::vector<double>>{random_X_data, random_Y_data};
}

std::vector<double> RANDOM::Gaussian(int size, double mean, double STD){

    std::vector<double> random_X_data(size, 0.0);
    std::vector<double> random_Y_data(size, 0.0);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> n_dist(mean, STD);

    for(int i = 0; i < size; i++){

        random_X_data[i] = n_dist(gen);
    }

    return random_X_data;

}