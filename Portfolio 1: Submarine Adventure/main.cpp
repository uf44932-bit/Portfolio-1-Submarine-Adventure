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

class Map
{
public:
    vector<string> level;
    
    Map()
    {
        level =
        {
            "###############",
            "~~~~~~~@~~~~~~~",
            "~~~~~~~ ~~~~~~",
            "~~~~~ ~~~~~~~",
            "~~~~~~ ~~~~~~~",
            "~~~~~~  ~~~~~~",
            "~~~~~  ~~~~~~",
            "~~~~~~ # ~~~~~~",
            "~~~~~ # ~~~~~~",
            "~~~~~ ## ~~~~",
            "~~~~ #  ~~~~",
            "~~~      ~~~~~",
            "~~~~~~  ~~~~~",
            "~~~ #  ~~~~",
            "~~~ *   $ ~~~~",
            "~~     #    ~~",
            "###############"
        };
    }
    
    bool isWall(int row, int col)
    {
        if(row < 0 || row >= level.size() || col < 0 || col >= level[0].size())
        {
            return true;
        }
        
        return level[row][col]=='#';
    }
    
    bool isSurface(int row, int col)
    {
        return level[row][col] == '~';
        
    }
    
    void printMap(Submarine& sub)
    {
        int startRow = sub.row - 2;
        int startCol = sub.col - 2;
        
        
        if (startRow < 0)
            startRow = 0;
        
        if (startCol < 0)
            startCol = 0;
        
        if (startRow + 5 > level.size())
            startRow = level.size() - 5;
        
        if (startCol + 5 > level[0].size())
            startCol = level[0].size() - 5;
        
        cout << endl;
        
        for (int r = startRow; r < startRow + 5; r++)
        {
            for (int c = startCol; c < startCol + 5; c++)
            {
                if (r == sub.row && c == sub.col)
                {
                    cout << "@";
                }
                else
                {
                    cout << level[r][c];
                }
            }
            cout << endl;
            
        }
        cout << endl;
        
    }
};


int main() {
    
    
    
    
    
    
    
    
    
    return EXIT_SUCCESS;
}
