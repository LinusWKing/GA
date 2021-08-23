#pragma once
#include <vector>

// Class representing individual in population
class Individual
{
public:
    vector<vector<int>> chromosome;
    int fitness;
    Individual(vector<vector<int>> chromosome);
    Individual mate(Individual parent2);
    int cal_fitness();
};

Individual::Individual(vector<vector<>> chromosome)
{
    this->chromosome = chromosome;
    fitness = cal_fitness();
};

// Perform mating and produce new offspring
Individual Individual::mate(Individual par2)
{
    // chromosome for offspring
    vector<vector<>> child_chromosome(10, vector<>(10, 0));

    int len = chromosome[0].size();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            // random probability
            float p = random_num(0, 100) / 100;

            // if prob is less than 0.45, insert gene
            // from parent 1
            if (p < 0.45)
                child_chromosome[i][j] = chromosome[i][j];

            // if prob is between 0.45 and 0.90, insert
            // gene from parent 2
            else if (p < 0.90)
                child_chromosome[i][j] = par2.chromosome[i][j];

            // otherwise insert random gene(mutate),
            // for maintaining diversity
            else
                child_chromosome[i][j] = mutated_genes();
        }
    }

    // create new Individual(offspring) using
    // generated chromosome for offspring
    return Individual(child_chromosome);
};

// Calculate fittness score, it is the number of
// characters in string which differ from target
// string.
int Individual::cal_fitness()
{
    int len = TARGET[0].size();
    int fitness = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (chromosome[i][j] != TARGET[i][j])
                fitness++;
        }
    }
    return fitness;
};

// // Overloading < operator
bool operator<(const Individual& ind1, const Individual& ind2)
{
    return ind1.fitness < ind2.fitness;
}