/*
This implementation has been inspired by
the contributions of Atul Kumar found at
https://www.geeksforgeeks.org/genetic-algorithms/
*/

#include"Genetic Representation.h"
#include"Fitness Function.h"
#include"Initialization.h"
#include"Selection.h"
#include<algorithm>
#include<iostream>
#include<chrono>
#include<thread>

//Overloading < operator
bool operator<(const Genetic_Representation& g1, const Genetic_Representation& g2)
{
    return g1.fitness < g2.fitness;
}


void print_vector(std::vector<std::vector<int>> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i][j] == 0)
            {
                std::cout << "  ";
            }
            else
            {
                std::cout << v[i][j] <<" ";
            }        
       
        }

        std::cout << std::endl;
        
    }
}

void print_solution(std::vector<Genetic_Representation>population, int gen) {

        std::cout << "Generation: " << gen << "\t\n";
        print_vector(population[0].chromosome);
        std::cout << "Fitness: " << population[0].fitness << "\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << std::flush;
    
}


int main()
{
    
    //seed random generator
    srand((unsigned)(time(0)));

    //initialize classes required
    Initialization init = Initialization();
    Selection select = Selection();
    Fitness_Function fc = Fitness_Function();
   
    //define variables
    std::vector< Genetic_Representation> starting_problem;
    std::vector< Genetic_Representation> new_gen;
    std::vector< Genetic_Representation> population;

    bool found = false;
    int count = 0;
    int gen = select.generation;

  
    // create initial population
    population = init.population_initialization();

    //define  and print starting problem
    starting_problem.push_back(population.back());
    std::cout << "Starting Problem is:\n\n";
    print_vector(starting_problem[0].chromosome);
    std::cout <<"\nFitness: "<< starting_problem[0].fitness;
    std::cout << std::endl<< std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));



    while (!found)
    {

        // terminate after 100 generations
        if (gen == 99) {
           
            std::cout << "Global optimal solution not found\n\n";
            print_solution(population, gen);
            std::cin.get();
            exit(0);
        }
            

        // sort the population in increasing order of fitness score
        std::sort(population.begin(), population.end());

        // terminate after an individual with fitness score = 0 is found
        if (population[0].fitness <= 0)
        {
            found = true;
            break;
        }

        //Perform selection and store the new generation
        new_gen = select.Elitism(population);

        //assign the new generation as our population for the next iteration
        population = new_gen;

        print_solution(population, gen);

        gen++;
    }

    // print if a global optimal solution is found
    std::cout << "Global optimal solution found\n\n";
    print_solution(population, gen);
    std::cin.get();

}
