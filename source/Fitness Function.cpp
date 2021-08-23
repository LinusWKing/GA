#include "Genes.h"
#include "Genetic Representation.h"
#include "Fitness Function.h"

// For each element in our solution that doesn't match the target, increment our fitness by 1
int Fitness_Function::calculate_fitness(std::vector<std::vector<int>> s) {

    fitness = 0;
    for (int i = 0; i < TARGET.size(); i++)
    {
        for (int j = 0; j < TARGET.size(); j++)
        {
            if (s[i][j] != TARGET[i][j])
                fitness++;
        }
    }
  
   return fitness;
}