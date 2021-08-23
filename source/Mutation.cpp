#include "Mutation.h"
#include <vector>

// return random genes from the defined valid genes
int Mutation::mutated_genes(std::vector<int> g) {

	int random = rand() % 2;
	return g[random];
}