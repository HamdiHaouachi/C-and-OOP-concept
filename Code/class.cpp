#include <iostream>
#include <cmath.h>
#include "class.h"

using namespace std;

// Modularité
vector::vector(int s):elem{new double[s]}, sz{s}
{
    // Initialization
    for(int i = 0; i !=s, ++i) elem[i] = 0;
}

vector::~vector()
{
    delete[] elem;
}

double& vector::operator[](int i)
{
    return elem[i];
}

int vector::size()
{
    return sz;
}


