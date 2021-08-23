#include "Random.h"
#include <stdlib.h>
#include <iostream>

//Generate randome values given a range
int Random::random_generator(int start, int end) {
    int range = (end - start) + 1;
    int random_int = start + (rand() % range);
    return random_int;
}