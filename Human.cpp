#include <iostream>
#include <conio.h>
#include "Human.h"
#include "World.h"
#include "Organism.h"

#define ARROW 224
#define TOP 72
#define BOTTOM 80
#define LEFT 75
#define RIGHT 77
#define ABILITY 117 // klawisz "U"

using namespace std;

Human::Human(int x, int y, World* world, int birthTurn)
{
	this->strength = 5;
	this->basestrength = 5;
	this->initiative = 4;
	this->activatedability = false;
	this->waiting = false;
	this->waitingTime = 0;
	this->x = x;
	this->y = y;
	this->world = world;
	this->birthTurn = birthTurn;
}

void Human::printing() const
{
	cout << "C";
}

string Human::getSpecies() const
{
	return "Czlowiek";
}

void Human::action()
{
	cout << "=======MAPA==PRZED==RUCHEM==CZLOWIEKA===========" << endl;
	this->getWorld()->printWorld();
	cout << "====WYKONAJ====RUCH=============================" << endl;
	cout << "====UZYJ====STRZALEK============================" << endl;
	cout << "====KLIKNIJ====U==ABY===UZYC==UMIEJETNOSCI======" << endl;
	cout << "Twoja sila to : " << strength << endl;
	while (true)
	{
		int command = _getch();
		if (command == ARROW)
		{
			switch (_getch()) // wybor ruchu strzalkami, w strony ktore sa mozliwe
			{
			case TOP:
				if (this->getY() > 0)
				{
					this->setY(this->getY() - 1);
					return;
				}
				else
					cout << "Nie da sie ruszyc w ta strone" << endl;

				break;
			case BOTTOM:
				if (this->getY() < this->world->getN() - 1)
				{
					this->setY(this->getY() + 1);
					return;
				}
				else
					cout << "Nie da sie ruszyc w ta strone" << endl;

				break;
			case LEFT:
				if (this->getX() > 0)
				{
					this->setX(this->getX() - 1);
					return;
				}
				else
					cout << "Nie da sie ruszyc w ta strone" << endl;

				break;
			case RIGHT:
				if (this->getX() < this->world->getM() - 1)
				{
					this->setX(this->getX() + 1);
					return;
				}
				else
					cout << "Nie da sie ruszyc w ta strone" << endl;
				break;
			default:
				cout << "Zly klawisz" << endl;
				break;

			}
		}
		else if (command == ABILITY)
		{
			if (!activatedability && this->strength < 10 && !waiting) // jesli umiejetnosc nie jest aktywna i czas oczekiwania wynosi 0 to mo¿na jej uzyc
				this->ability();
			else
				cout << "NIE MOZNA UZYC UMIEJETNOSCI" << endl;
		}
		else
			cout << "Zly klawisz" << endl;
	}
}

void Human::ability()
{
	cout << "Czlowiek uzyl umiejetnosci (jego sila wynosi 10)" << endl;
	this->basestrength = this->strength;
	this->strength = 10;
	this->activatedability = true;
}

void Human::deactivate()
{
	this->activatedability = false;
	this->waiting = true;
	this->waitingTime = 5;
}
bool Human::isAbilityActivated() const
{
	return this->activatedability;
}

int Human::getBaseStrength() const
{
	return this->basestrength;
}
int Human::getWaitingTime() const
{
	return this->waitingTime;
}

void Human::setWaitingTime(int czas)
{
	this->waitingTime = czas;
}

void Human::letUseAbility()
{
	this->waiting = false;
}

bool Human::isWaiting() const
{
	return this->waiting;
}