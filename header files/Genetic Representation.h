#pragma once
#include <vector>

// Describe the genetic representation of the individuals in a population.
class Genetic_Representation
{
public:
	std::vector<std::vector<int>> chromosome;
	int fitness;
	Genetic_Representation(std::vector<std::vector<int>> chromosome);
		
};




