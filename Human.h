#pragma once
#include <iostream>
#include <string.h>
#include "Animal.h"
#include "Organism.h"
#include "World.h"
using namespace std;

class Animal;

class Human : public Animal {
	int basestrength;
	bool activatedability;
	bool waiting;
	int waitingTime;
public:
	Human(int x, int y, World* world, int birthTurn);
	void printing() const override;
	string getSpecies() const override;
	void action() override;
	void ability();
	void deactivate();
	bool isAbilityActivated() const;
	bool isWaiting() const;
	int getBaseStrength() const;
	int getWaitingTime() const;
	void setWaitingTime(int time);
	void letUseAbility();
};