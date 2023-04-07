#pragma once
#include <iostream>
#include "Animal.h"
#include <string.h>
using namespace std;

class Animal;

class Turtle : public Animal {

public:
	Turtle(int x, int y, World* world, int birthTurn);
	void printing() const override;
	string getSpecies() const override;
	void action() override;
	void collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**>& actionOrganisms) override;
};