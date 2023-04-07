#pragma once
#include <iostream>
#include <string.h>
#include "Plant.h"

using namespace std;

class Plant;

class Sonchus : public Plant {

public:
	Sonchus(int x, int y, World* world, int birthTurn);
	void printing() const override;
	string getSpecies() const override;
	void action() override;
};