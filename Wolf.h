#pragma once
#include <iostream>
#include "Animal.h"
#include "World.h"
#include "Organism.h"
#include <string.h>

using namespace std;

class Animal;

class Wolf : public Animal {

public:
	Wolf(int x, int y, World* world, int birthTurn);
	void printing() const override;
	string getSpecies() const override;
};