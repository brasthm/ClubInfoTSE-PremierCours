#include "utilities.h"
#include <random>


int random(int max)
{
    return random(0, max);    
}


int random(int min, int max)
{
    static std::random_device device;
    std::uniform_int_distribution<int> distrib(min, max);
    std::default_random_engine en(device());
    return distrib(en);
}