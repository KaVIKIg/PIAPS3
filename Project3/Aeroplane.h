#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <memory>
#include "People.h"
#include "Classes.h"
using namespace std;
class Aeroplane : public Unit
{
	
public:
    int total = 0;
    int maxWeight = 500;

    int getWeight( ) {

        for (int i = 0; i < c.size(); ++i)
            total += c[i]->getWeight();

      
        return total;
    }

    void addUnit(Unit* p) {
        c.push_back(p);
    }

    int correctWeight(int n) {

        int res= 0;
        int r = 0;
        if (total > maxWeight)
        {
             r = total - maxWeight;
            cout << "\nWEIGHT Aeroplane = " << total << ", OVERweight = " << r << endl << endl;
            cout << "CORRECT WEIGHT" << endl;
            for (int i = 0; i < c.size(); ++i)
                res += c[i]->correctWeight(r);

        }
        if (res == -1)
        {

            return -1;
        }

        else 
        {
            total = total - r;
            cout << "\nWEIGHT Aeroplane = " << total << endl;
            return 0;

        }

        return 0;
    }


    ~Aeroplane() { }
 
private:
    vector<Unit*> c;

};

Aeroplane* createAeroplane(Aeroplane* aeroplane, size_t pilot, size_t stewardess, size_t first, size_t bisiness, size_t econom)
{
    
    //Aeroplane* aeroplane = new Aeroplane;
    int maxWeight = 500;

    for (int i = 0; i < pilot; ++i)
        aeroplane->addUnit(new Pilot);
    
    for (int i = 0; i < stewardess; ++i)
        aeroplane->addUnit(new Stewardess);

       aeroplane-> addUnit(createFirst(first));
    
       aeroplane->addUnit(createBisiness(bisiness));

       aeroplane->addUnit(createEconom(econom));

       aeroplane->getWeight();

       int w = aeroplane->correctWeight(maxWeight);


       int people = first + bisiness + econom;
       if (people > 180)
       {

           cout << "The number of passengers is greater than the number of seats!";
       }


       /*if ( (first > 10) or (bisiness > 20) or (econom > 150))*/
         
       if ((w == -1) or (pilot < 2) or (stewardess < 6))
       {

           cout << "\nThe plane does not fly!" << endl;
       }
       else
       {

           cout << "Ready!!!" << endl;

           return aeroplane;
       }
}