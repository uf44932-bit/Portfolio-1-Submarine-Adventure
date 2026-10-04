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

class Game
{
private:
    Map map;
    Submarine submarine;
    
    int totalEarnings;
    
public:
    
    Game()
    {
        totalEarnings = 0;
        
    }
    
    bool moveSubmarine(char direction)
    {
        int newRow = submarine.row;
        int newCol = submarine.col;
        
        if (direction == 'w')
        {
            newRow--;
            
        }
        else if (direction == 's')
        {
            newRow++;
            
        }
        else if (direction == 'a')
        {
            newCol--;
            
        }
        else if (direction == 'd')
        {
            newCol++;
        }
        
        if (map.isWall(newRow, newCol))
        {
            cout << "You cant move into the wall! Try Again!" << endl;
            return false;
        }
        
        submarine.row = newRow;
        submarine.col = newCol;
        
        submarine.oxygen--;
        
        return true;
    }
    
    void inspect()
    {
        bool foundSomething = false;
        
        int directions[4][2] =
        {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
    
        for (int i = 0; i < 4; i ++)
        {
            int r = submarine.row + directions[i][0];
            int c = submarine.col + directions[i][1];
            
            if (r < 0 || r >= map.level.size() || c < 0 || c >= map.level[0].size())
            {
                continue;
            }
            
            char object = map.level[r][c];
            
            if (object == '$')
            {
                cout << "you found a pouch of gold coins! (value: $7)" << endl;
                
                submarine.addtreasure(Treasure("Gold coins", 7));
                
                map.level[r][c] = ' ';
                
                foundSomething = true;
            }
            
            else if (object == '*')
            {
                cout << " you found a Copper Sword!(value: $50)" << endl;
                
                submarine.addtreasure(Treasure("Copper Sword", 50));
                
                map.level[r][c] = ' ';
                
                foundSomething = true;
            }
            
            else if (object == 'S')
            {
                cout << "You found an skeletion!" << endl;
                foundSomething = true;
            }
            
            else if (object == 'P')
            {
                cout << " you found a piece of seaweed." << endl;
                foundSomething = true;
            }
        }
        
        if (!foundSomething)
        {
            cout << "you didnt find anything interesting nearby." << endl;
            
        }
    }
    
    bool reachedSurface()
    {
        return
        map.isSurface(submarine.row, submarine.col);
    }
    
    
    void finishDive()
    {
        int earnings = submarine.diveEarning();
        
        cout << endl;
        cout << "you reached the surface!" << endl;
        cout << "Oxygen refilled." << endl;
        
        if(submarine.treasures.empty())
        {
            cout << "You didnt find any treasure this dive. :(" << endl;
            
        }
        else {
            cout << "Treasure collected: " << endl;
            
            for (Treasure treasure : submarine.treasures)
            {
                cout << treasure.name << ":+$" << treasure.value << endl;
                
            }
            
            cout << "Earning this descent: $" << earnings << endl;
            
            totalEarnings += earnings;

        }
        
        submarine.treasures.clear();
        
        submarine.refillOxygen();
        
        cout << "total Earnings: $" << totalEarnings << endl;
        
        cout << "Oxygen: " << submarine.oxygen << "/" << submarine.maxOxygen << endl;
        
    }
    
    void startGame()
    {
        submarine = Submarine();
        map = Map();
        
        bool playing = true;
        
        while (playing)
        {
            map.printMap(submarine);
            
            cout << "Oxygen: " << submarine.oxygen << "/" << submarine.maxOxygen << endl;
            
            cout << endl;
            cout << "Enter a move (W/A/S/D) or inspect: ";
            
            string input;
            cin >> input;
            
            if (input == "inspect" || input == "Inspect" || input == "INSPECT")
            {
                inspect();
                continue;
            }
            
            if (input.length() != 1)
            {
                cout << "invalid input! Enter W, A, S, D, or inspect." << endl;
                continue;
            }
            
            char move = input[0];
            
            
            if (move >= 'A' && move <= 'Z')
            {
                move = move + 32;
            }
            
            if (move != 'w' && move != 'a' && move != 's' && move!= 'd')
            {
                cout << "invalid input! Enter W, A, S, D, or inspect." << endl;
                continue;
            }
            
            bool moved = moveSubmarine(move);
            
            if(!moved)
            {
                continue;
            }
            
            if (submarine.oxygen <= 0)
            {
                cout << endl;
                cout << "you ran out of oxygen!" << endl;
                
                cout << "Game Over!" << endl;
                
                playing = false;
                continue;
            }
            
            if (reachedSurface())
            {
                finishDive();
            }
        }
    }
    
}


int main() {
    
    
    
    
    
    
    
    
    
    return EXIT_SUCCESS;
}
