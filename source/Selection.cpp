#include "Selection.h"
#include "Genetic Representation.h"
#include "Random.h"
#include "Genes.h"
#include "Crossover.h"
#include <vector>

std::vector<Genetic_Representation> Selection::Elitism(std::vector<Genetic_Representation> p) {

    
    Crossover cv = Crossover();

    //Remove the previous generation
    next_generation.clear();

    // Select the fittest individual who rank in the top 10% through elitism
    int s = (10 * POPULATION_SIZE) / 100;
    for (int i = 0; i < s; i++)
        next_generation.push_back(p[i]);

    // Top 50% fittest individuals will be viable as parents
    s = (90 * POPULATION_SIZE) / 100;
    for (int i = 0; i < s; i++)
    {
        int random_number = Random::random_generator(0, 50);
        Genetic_Representation parent1 = p[random_number];
        random_number = Random::random_generator(0, 50);
        Genetic_Representation parent2 = p[random_number];
        Genetic_Representation offspring = cv.recombination(parent1, parent2);
        next_generation.push_back(offspring);
        
    }

    return next_generation;  
    
}