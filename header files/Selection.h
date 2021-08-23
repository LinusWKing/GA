#pragma once
#include"Genetic Representation.h"
#include <vector>

class Selection
{
public:
	std::vector<Genetic_Representation> Elitism(std::vector<Genetic_Representation >p);
	int generation = 0;

private:
	std::vector<Genetic_Representation> next_generation;
	
};

