#include <iostream>
#include "Aeroplane.h"
using namespace std;

int main()
{
	Aeroplane* aeroplane = new Aeroplane;  //max Weight 4300
	int pilot = 2;  //2
	int stewardess = 6;  //6 
	int first = 2; //10
	int bisiness = 6;   //20
	int econom = 10;  //150


	aeroplane->addUnit(createAeroplane(aeroplane, pilot, stewardess, first, bisiness, econom));

	delete aeroplane;
	system("pause");
	return 0;
}