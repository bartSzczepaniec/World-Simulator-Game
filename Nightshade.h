#pragma once
#include <iostream>
#include "Plant.h"
#include <string.h>

using namespace std;

class Plant;

class Nightshade : public Plant {

public:
	Nightshade(int x, int y, World* world, int birthTurn);
	void printing() const override;
	string getSpecies() const override;
};