#pragma once
#pragma once
#include <iostream>
#include "Animal.h"
#include <string.h>
using namespace std;

class Animal;

class Fox : public Animal {

public:
	Fox(int x, int y, World* world, int birthTurn);
	void printing() const override;
	string getSpecies() const override;
	void action() override;
};