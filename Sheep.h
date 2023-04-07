#pragma once
#include <iostream>
#include <string.h>
#include "Animal.h"

using namespace std;

class Animal;

class Sheep : public Animal {

public:
	Sheep(int x, int y, World* world, int birthTurn);
	void printing() const override;
	string getSpecies() const override;
	~Sheep();
};