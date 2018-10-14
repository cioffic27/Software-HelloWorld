#include <iostream>
#include <string>
using namespace std;

class item
{
    string name;
    location place;

    item(name n, location loc)
    {
        name = n;
        place = loc;
    }

    string getName() {return name;}
    location getPlace() {return place;}
    void setLocation(location loc) {place = loc;}
}

int main()
{
    cout <<"Welcome to the game.\n\n";

    string command;
    bool game = true;
    bool itemPU = move = false;
    bool cPaperGet = false, keyGet = false;
    bool lockA = lockB = drawLock = true, shelfFull = false;
    bool n = s = e = w = false, c = true;

    enum location {north, south, east, west, center, person};
    location playerPlace = center;

    item KeyA ("KEY A", center);
    item TestNote ("TESTNOTE", person);

    int capacity = 5;
    item inventory[capacity] = {TestNote};

    while(game)
    {        
        cout <<"What will you do? ";

        getline(cin, command);

        switch(toupper(command))
        {
            case "NORTH":
            case "SOUTH":
            case "EAST":
            case "WEST":
            case "CENTER":
                move = true;
                itemPU = false;
                break;

            case "MOVE": 
                cout <<"MOVE where? ";
                getline(cin, command);
                move = true;
                itemPU = false;
                break;

            case "DROP":
                cout <<"DROP what? ";
                getline(cin, command);
                move = false;
                itemPU = false;
                itemDrop(toupper(command));
                break;

            case "USE":
                cout <<"USE what? ";
                getline(cin, command);
                move false;
                itemPU = false;
                itemUse(toupper(command));
                break;
            
            case "PICKUP":
            case "PICK-UP":
                cout <<"PICK-UP what? "

                getline(cin, command);

                itemPU = true;
                move = false;
                break;

            case "ITEMS"
            case "INVENTORY":
                cout <<"This is what you have: \n"
                for(int x = 0, x < capacity; x++)
                {
                    if (inventory[x] != null)
                    {
                        cout <<inventory[x].getName() <<", ";
                    }
                }
                cout <<endl <<endl;
                move = itemPU = false;
                break;

            case "LOOK":
                if(playerPlace == north)
                {
                    cout <<"A bookshelf stands, organized into four shelves.\n";
                    cout <<"Red, yellow, blue and green books lines the shelves from top to bottom.\n";
                    
                    if(!shelfFull) 
                        {"There are spaces in the rows where books can fit.\n\n";}

                    else {cout <<endl;}
                }
                else if(playerPlace == south)
                {
                    cout <<"A steel door blocks your way.\n";

                    if(lockA && lockB) 
                        {cout <<"Two locks keep it firmly shut.\n\n";}
                   
                    else if (lockA || lockB) 
                        {cout <<"One lock keeps the door shut.\n\n";}

                    else {cout <<endl;}
                }
                else if(playerPlace == east)
                {
                    cout <<"There is a table in the corner with a vase of yellow flowers.\n";

                    if(drawLock)
                        {cout <<"The table's drawer has a lock on it.\n\n";}

                    else {cout <<endl;}
                }
                else if(playerPlace == west)
                {
                    cout <<"There is a painting on the wall of a man\n
                            in a top hat with a scar above his left eye.\n\n";
                }
                else if(playerPlace == center)
                {
                    cout <<"There is a table with several books on it.\n";
                    
                    if(!cPaperGet)
                        {cout <<"There is a piece of paper peeking out from underneath one book.\n\n";}

                    else {cout <<endl;}
                }

                move = false;
                itemPU = false;
                break;

            default:
                cout <<"Invalid command.\n\n";
                move = false;
                break;
        }

        if(itemPU)
        {
            switch(toupper(command))
            {
                case "KEYA":
                case "KEY A":
                case "KEY_A":
                    if(KeyA.getPlace() == playerPlace)
                    {
                        cout <<"You picked up " <<KeyA.getName() <<".\n\n";
                        KeyA.setLocation(person);
                        addItem(KeyA);
                    }

                    else {cout <<"That item isn't not near you.\n\n";}

                    break;

                default:
                    cout <<"That is not an available item.\n\n";            
            }
        }
        
        if(move)
        {
            switch(toupper(command))
            {                
                case "CENTER":
                    if(playerPlace != center)
                    {
                        cout <<"This is the Room CENTER.";
                        playerPlace = center;
                    }
                    else
                    {
                        cout <<"You are already in the CENTER."
                    }
                    break;

                case "NORTH":
                    if(playerPlace != north)
                    {
                        cout <<"This is the NORTH Wall.";
                        playerPlace = north;
                    }
                    else
                    {
                        cout <<"You cannot go any further NORTH."
                    }
                    break;

                case "SOUTH":
                    if(playerPlace != south)
                    {
                        cout <<"This is the SOUTH Wall.";
                        playerPlace = south;
                    }
                    else
                    {
                        cout <<"You cannot go any further SOUTH."
                    }
                    break;

                case "EAST":
                    if(playerPlace != east)
                    {
                        cout <<"This is the NORTH Wall.";
                        playerPlace = east;
                    }
                    else
                    {
                        cout <<"You cannot go any further EAST."
                    }
                    break;

                case "WEST":
                    if(playerPlace != west)
                    {
                        cout <<"This is the WEST Wall.";
                        playerPlace = west;
                    }
                    else
                    {
                        cout <<"You cannot go any further WEST."
                    }
                    break;

                default:
                    cout <<"That is not a direction to move to."
            }
        }

        void itemDrop(string iName)
        {
            bool drop = false;

            for(int x = 0; x < capacity; x++)
            {
                if(inventory[x].getName == iName)
                {
                    inventory[x].setLocation(playerPlace);
                    cout <<"You dropped " <<inventory[x].getName() <<endl <<endl;
                    inventory[x] = null;
                    drop = true;
                }
            }

            if(!drop){cout <<"That item was not in your inventory.\n\n";}
        }

        void itemUse(string iName)
        {
            bool usable = false

            for(int x = 0; x < capacity; x++)
            {
                if(inventory[x].getName == iName)
                {
                    usable = true;
                }
            }

            if(!usable) {cout <<"You do not have this item to use.\n\n";}

            else
            {
                switch (iName)
                {
                    case "TESTNOTE":
                        cout <<"Find your way out of the room.\n\n";
                        break;

                    case "KEYA":
                    case "KEY A":
                    case "KEY_A":
                        cout <<"This key does not seem to go to anything...\n\n";
                        break;
                    
                    default:
                        cout <<"That item cannot be used this way.\n\n";
                        break;
                }
            }
        }
    }

    cout <<"Congratulations! You Won!\n\nThanks for playing!\n";
}