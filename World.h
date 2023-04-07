#pragma once
#include <string.h>
#include "Organism.h"
#include "Animal.h"
#include "Fox.h"
#include "Antelope.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Plant.h"
#include "Sonchus.h"
#include "Grass.h"
#include "Guarana.h"
#include "Nightshade.h"
#include "SosnowskyHogweed.h"
#include "Human.h"

class World {
	int n; // rozmiar n
	int m; // rozmiar m
	Organism*** organismsMap;
	int turn;

public:
	int getN() const;
	int getM() const;
	int getTurn() const;
	World(int n, int m);
	void printWorld() const;
	void printInterface() const;
	void doTurn();
	void removeOrganism(int x, int y);
	void replaceOrganism(int x, int y, int replacedX, int replacedY);
	void swapOrganism(int attackerX, int attackerY, int escapingX, int escapingY, int targetX, int targetY);
	void putOrganism(Organism* organism, int x, int y);
	void createAnimal(Organism* organism, int x, int y);
	Organism* getOrganism(int x, int y) const;
	Organism** getPointerOnOrganism(int x, int y) const;
	~World();
};