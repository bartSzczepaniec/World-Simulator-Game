#pragma once
#include <iostream>
#include <string.h>
#include "Plant.h"

using namespace std;

class Plant;

class Guarana : public Plant {

public:
	Guarana(int x, int y, World* world, int birthTurn);
	void printing() const override;
	string getSpecies() const override;
	void collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**>& actionOrganisms) override;
};