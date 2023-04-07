#pragma once
#include<string>
#include<vector>

using namespace std;

class World;

class Organism {

protected:
	int strength;
	int initiative;
	int x;
	int y;
	int birthTurn;
	World* world;

public:
//	Organism();
	virtual void action() {};
	virtual void collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**> &actionOrganisms);
	int getX() const;
	int getY() const;
	int getStrength() const;
	int getInitiative() const;
	int getBirth() const;
	World* getWorld() const;
	virtual string getSpecies() const = 0;
	void setX(int x);
	void setY(int y);
	void setStrength(int strength);
	virtual void printing() const {};
};