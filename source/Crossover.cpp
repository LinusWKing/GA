#include "Crossover.h"
#include "Genetic Representation.h"
#include "Mutation.h"
#include "Genes.h"
#include "Random.h"
#include <vector>

Genetic_Representation Crossover::recombination(Genetic_Representation parent1,Genetic_Representation parent2) {
    // chromosome for offspring
    std::vector<std::vector<int>> offspring(10, std::vector<int>(10, 0));
    

    int len = parent1.chromosome[0].size();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            // get random value to represent a probability
            float p = Random::random_generator (0, 100) / 100;

            // if probability is less than 0.45, get gene from parent 1
            if (p < 0.45)
                offspring[i][j] = parent1.chromosome[i][j];

            // if probability is less than 0.90 , get gene from parent 2
            else if (p < 0.90)
                offspring[i][j] = parent2.chromosome[i][j];

            // else mutate by inserting a random gene
            else
                offspring[i][j] = Mutation::mutated_genes(GENES);
        }
    }

    //return the new offspring
    return Genetic_Representation(offspring);
};
