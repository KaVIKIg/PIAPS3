#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <memory>
#include <algorithm>
#include "People.h"

using namespace std;

class CompositeFirstClass : public Unit
{
public:
    int maxWeight = 4300;
    int* weight;
    int total = 0;
    
    CompositeFirstClass()
    {
        cout << "\nFirstClass: \n";
    }

    int getWeight() {

        weight = new int[c.size()];
        

        cout << "\nFirstClass : " << endl;
        total = 0;
        for (int i = 0; i < c.size(); ++i)
        {
            weight[i] = c[i]->getWeight();
            total += weight[i];
        }
   
        for (int i = 0; i < c.size(); i++)
        {
            cout << i + 1 << "   Passenger, weight = " << weight[i] << endl;

        }

        cout << "weight FirstClass = " << total << endl <<endl;
        return total;
    }



    void addUnit(Unit* p) {
        c.push_back(p);
    }

    int correctWeight(int r)
    {

        cout << "\nFirstClass : " << endl;

        for (int i = 0; i < c.size(); i++)
        {
            cout << i + 1 << "   Passenger weight = " << weight[i] <<  endl;

        }
        cout << "weight FirstClass = " << total << endl << endl;
        return 0;
    }

    ~CompositeFirstClass() {
        for (int i = 0; i < c.size(); ++i)
            delete c[i];
    }

private:
    vector<Unit*> c;
    
	
};


CompositeFirstClass* createFirst(size_t p)
{
    
    CompositeFirstClass* first = new CompositeFirstClass;
    
    for (int i = 0; i < p; ++i)
        first->addUnit(new Passenger);
       

    return first;
}

class CompositeEconomClass : public Unit
{
public:

    int maxWeight = 35;
    int total;
    int* weight;
    int* over;
    CompositeEconomClass()
    {
        cout << "\nEconomClass: \n";
    } 

    int getWeight() {
        
       
        total = 0;
        /*int over = 0;*/
        weight = new int[c.size()];
        over = new int[c.size()];
        for (int i = 0; i < c.size(); ++i) {

            weight[i] = c[i]->getWeight();
            total += weight[i];
            if (weight[i] > maxWeight)
            {
                 over[i] = weight[i] - maxWeight ;
                 weight[i] = weight[i] - over[i];
            }
            else {
            
                over[i] = 0;
            }

            
        }

        cout << "EconomClass : " << endl;
        for (int i =0; i < c.size(); i++)
        {
            cout << i+1 << "   Passenger, weight = " << weight[i] << "  +  overweight = " << over[i] << endl;

        }

        cout << "EconomClass weight = " << total << endl << endl;
        return total;
    }

    void addUnit(Unit* p) 
    {
        c.push_back(p);
    }

   

   


    int correctWeight(int r)
    {
        int res = total - r;

        if (res < 0)
            return -1;
        else
        {

            for (int i = 0; i < c.size(); i++)
            {
                if (r < over[i])
                {

                    over[i] = over[i] - r;
                    r = 0;
                    break;
                }

                else
                {

                    r = r - over[i];
                    over[i] = 0;
                }


                if (r == 0)
                    break;


            }


            for (int i = c.size() - 1; i > 0; i--)
            {
                if (r < weight[i])
                {

                    weight[i] = weight[i] - r;
                    r = 0;
                    break;
                }
                else {

                    r = r - weight[i];
                    weight[i] = 0;

                }

                if (r == 0)
                    break;


            }

            // cout << "correctweight EconomClass, taken off the flight weight = " << r << endl;

            cout << "\nEconomClass : " << endl;

            for (int i = 0; i < c.size(); i++)
            {
                cout << i + 1 << "   Passenger weight = " << weight[i] << "    +   overweight = " << over[i] << endl;

            }


             cout << "taken off the flight weight = " << (total-res) << endl;
            cout << "EconomClass  correctweight = " << res << endl << endl;


            return 1;
        }
    }


        ~CompositeEconomClass() {
            for (int i = 0; i < c.size(); ++i)
                delete c[i];
        }

    
private:
    vector<Unit*> c;
    map<int, int> w;
    map<int, int> ::iterator itrCode;
    
};

CompositeEconomClass* createEconom(size_t p)
{
    
    CompositeEconomClass* econom = new CompositeEconomClass;
    
    for (int i = 0; i < p; ++i)
        econom->addUnit(new Passenger);
        //econom->getWeight();
    return econom;
}






class CompositeBusinessClass : public Unit
{
public:
    int* weight;
    int* over;
    int maxWeight = 35;
    int total = 0;
    CompositeBusinessClass()
    {
        cout << "\nBusinessClass: \n";
    }

    int getWeight() {

        weight = new int[c.size()];
        over = new int[c.size()];

        cout << "BusinessClass weight : " << endl;
       
        for (int i = 0; i < c.size(); ++i)
        {
            weight[i] = c[i]->getWeight();
            total += weight[i];


            if (weight[i] > maxWeight)
            {
                over[i] = weight[i] - maxWeight;
                weight[i] = weight[i] - over[i];
            }
            else {

                over[i] = 0;
            }

        }

        for (int i = 0; i < c.size(); i++)
        {
            cout << i + 1 << "   Passenger, weight = " << weight[i] << "  +  overweight = " << over[i] << endl;

        }
        cout << "weight BusinessClass = " << total << endl << endl;
        return total;
    }
    void addUnit(Unit* p) {
        c.push_back(p);
    }

    int correctWeight(int r)
    {

        cout << "\nBusinessClass : " << endl;

        for (int i = 0; i < c.size(); i++)
        {
            cout << i + 1 << "   Passenger weight = " << weight[i] << "    +   overweight = " << over[i] << endl;

        }

        cout << "weight BusinessClass = " << total << endl << endl;
        return 0;
    }

    ~CompositeBusinessClass() {
        for (int i = 0; i < c.size(); ++i)
            delete c[i];
    }

private:
    vector<Unit*> c;
};




CompositeBusinessClass* createBisiness(size_t p)
{
    
    CompositeBusinessClass* bisiness = new CompositeBusinessClass;
   
    for (int i = 0; i < p; ++i)
        bisiness->addUnit(new Passenger);
    //bisiness->getWeight();

    return bisiness;
}