/*
 We're going to make a game about exploring the ocean in a submarine! We will be expanding this project for portfolios 2 and 3, so make sure your code is well organized and extensible.

 Here's the rough outline:
 The submarine starts on the surface of the ocean and descends
 The submarine has a limited supply of oxygen, which depletes as it explores
 The submarine can find interesting things underwater, such as treasures
 The submarine eventually can return to the surface, where it will restore its oxygen before another adventure

 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Treasure
{
public:
    string name;
    int value;
    
    Treasure(string n, int v)
    {
        name = n;
        value = v;
        
    }
};

class Submarine
{
public:
    int row;
    int col;
    
    int oxygen;
    int maxOxygen;
    
    vector<Treasure>treasures;
    
    Submarine()
    {
        row = 1;
        col = 7;
        
        maxOxygen = 50;
        oxygen = maxOxygen;
    }
    
    void refillOxygen()
    {
        oxygen = maxOxygen;
    }
    
    void addtreasure(Treasure treasure)
    {
        treasures.push_back(treasure);
    }
    
    int diveEarning()
    {
        int total = 0;
        
        for(Treasure treasure : treasures)
        {
            total += treasure.value;
        }
        return total;
    }
};



int main() {
    
    
    
    
    
    
    
    
    
    return EXIT_SUCCESS;
}
