#pragma once
#include "Organism.h"
#include <string.h>
using namespace std;

class Organism;

class Animal : public Organism {

public:
	void collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**>& ActionOrganisms) override;
	virtual string getSpecies() const = 0;
	void action() override;
};