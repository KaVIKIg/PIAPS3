#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <memory>
#include <cassert>
using namespace std;
typedef unsigned int uint;
//Component
class Unit
{
protected:
	
public:
	virtual int getWeight() = 0;
	virtual void addUnit(Unit* p) {}
	virtual int correctWeight(int r) = 0;
	virtual ~Unit() {}
};

//Primitives
class Passenger : public Unit
{
public:

	

	Passenger()
	{
		cout << "Passenger is added.\n";
	} 

	 int getWeight() {
		 int weight = 5 + rand() % (60 - 5 + 1);
		/* if (weight > maxWeight)
		 {
			 int r = weight - maxWeight;
			 cout << "weight = " << weight << ", overweight = " << r << endl;
		 }
		 else
		 cout << "weight = " << weight << endl;*/
		return weight;
	}

	 int correctWeight(int r)
	 {
		 return 0;
	 }

	 ;
};

class Pilot : public Unit
{
public:
	
	Pilot() 
	{ 
		cout << "Pilot is added.\n"; 
	}

	int getWeight() {
		return 0;
	}

	int correctWeight(int r)
	{
		return 0;
	}
};

class Stewardess : public Unit
{
public:
	
	Stewardess() 
	{ 

		cout << "Stewardess is added\n";
	}
	
	int getWeight() {
		return 0;
	}

	int correctWeight(int r)
	{
		return 0;
	}
};
