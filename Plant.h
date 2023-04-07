#pragma once
#include "Organism.h"
#include <string.h>
using namespace std;

class Organism;

class Plant : public Organism {

public:
	void collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**>& actionOrganisms) override;
	virtual string getSpecies() const = 0;
	void action() override;
	bool randomisePlanting();
};