#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "World.h"

#define ENTER 13
#define ENDING 27

using namespace std;

int main()
{
	World* s = nullptr;
	int n = 20 , m = 20;
	int command = ENTER;
	s = new World(n, m);
	cout << "Autor: Bartlomiej Szczepaniec 184751" << endl;
	cout << "Kliknij ENTER aby Rozpoczac symulacje" << endl;
	command = _getch();
	while(command!=ENTER)
		command = _getch();
	s->printWorld();
	s->printInterface();
	while (command!=ENDING) // poki nie kliknie sie ESC, to mozna grac dalej
	{
		command = _getch();
		if (command == ENTER)
		{
			system("CLS");
			s->doTurn();
			s->printWorld();
			s->printInterface();
		}
	}
	
	delete s;
	return 0;
}