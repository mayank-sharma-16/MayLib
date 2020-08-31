#ifndef __RANDOM_DATA_GEN__
#define __RANDOM_DATA_GEN__

#include <vector>
#include <ctime>

extern int DEFAULT_RANDOM_DATA_SIZE;
extern double DEFAULT_RANDOM_DISTRIBUTION_MEAN;
extern double DEFAULT_RANDOM_DISTRIBUTION_STD;

namespace RANDOM {

std::vector<std::vector<double>> Sinusoidal(int size = DEFAULT_RANDOM_DATA_SIZE);
std::vector<double> Gaussian(int size = DEFAULT_RANDOM_DATA_SIZE, double mean = DEFAULT_RANDOM_DISTRIBUTION_MEAN, double STD = DEFAULT_RANDOM_DISTRIBUTION_STD);

}

#endif