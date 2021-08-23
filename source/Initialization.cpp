#include <vector>
#include "Initialization.h"
#include "Genetic Representation.h"
#include "Genes.h"
#include "Mutation.h"


// Create a chromosome from random genes. 
std::vector<std::vector<int>> Initialization::chromosome_initialization(std::vector<std::vector<int>> TARGET) {

    std::vector<std::vector<int>> chromosome(10, std::vector<int>(10, 0));
    for (int i = 0; i < TARGET.size(); i++)
    {
        for (int j = 0; j < TARGET.size(); j++)
        {
            chromosome[i][j] = Mutation::mutated_genes(GENES);
        }
    }

    return chromosome;


}

// Initialize population using randomly generated chromosomes.
std::vector<Genetic_Representation> Initialization::population_initialization() {

    for (int i = 0; i < POPULATION_SIZE; i++)
    {        
        std::vector<std::vector<int>> chromosome = chromosome_initialization(TARGET);
        population.push_back(Genetic_Representation(chromosome));
    }
    return population;
}

