#pragma once
#include <iostream>
#include "Plant.h"
#include <string.h>

using namespace std;

class Plant;

class Grass : public Plant {

public:
	Grass(int x, int y, World* world, int birthTurn);
	void printing() const override;
	string getSpecies() const override;
};