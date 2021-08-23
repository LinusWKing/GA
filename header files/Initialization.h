#pragma once
#include <vector>
#include "Genetic Representation.h"
class Initialization
{
public:
	std::vector<std::vector<int>> chromosome_initialization(std::vector<std::vector<int>> Target);
	std::vector<Genetic_Representation> population_initialization();
	std::vector<Genetic_Representation> population;

};



