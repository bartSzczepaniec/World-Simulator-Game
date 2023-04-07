#pragma once
#include <iostream>
#include <string.h>
#include "Animal.h"

using namespace std;

class Animal;

class Antelope : public Animal {

public:
	Antelope(int x, int y, World* world, int birthTurn);
	void printing() const override;
	string getSpecies() const override;
	void action() override;
	void collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**>& actionOrganisms) override;
};