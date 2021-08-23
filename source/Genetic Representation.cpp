#include "Genetic Representation.h"
#include "Fitness Function.h"
#include <vector>

// define a solution as a chromosome with a fitness value
Genetic_Representation::Genetic_Representation(std::vector<std::vector<int>> chromosome) {

	Fitness_Function f = Fitness_Function();

	this->chromosome = chromosome;
	fitness = f.calculate_fitness(chromosome);
}