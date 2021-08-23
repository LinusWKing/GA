#pragma once
#include <vector>

//Valid genes for the chromosome
const std::vector<int> GENES = { 0,1 };

// Targeted output
 const std::vector<std::vector<int>> TARGET = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

};

const int POPULATION_SIZE =  100;