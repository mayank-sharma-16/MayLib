#ifndef __DATA_INSTANCE__
#define __DATA_INSTANCE__

#include <string>
#include <vector>

template <class data_vectors>
class DataInstance
{

public:

    DataInstance(std::string p_descriptor);
    std::string get_descriptor();

private:

    std::string descriptor;
    std::vector<data_vectors> data;
};

#endif