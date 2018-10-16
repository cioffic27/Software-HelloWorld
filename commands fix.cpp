#include<iomanip>
#include <iostream>
#include <string>

using namespace std;
//create an item class that has their names and locations-implement later
class item
{
public:
	string name;
	string location;

	item(string n, string loc)
	{
		name = n;
		location = loc;
	}

	string getName() { return name; }
	string getPlace() { return location; }
};

int main()
{
	cout << "Welcome to the game.\n\n";

	string command;														//string value for what user enters
	bool game = true;													//was the game completed or not
	bool itemPU = false;												//pick up item function
	bool move = false;													//move function
	bool cPaperGet = false;												//not used at the moment
	bool keyGet = false;												//did you get the key
	bool lockA = false;													//not used at the moment
	bool lockB = false;													//not used at the moment
	bool drawLock = true;												//not used at the moment
	bool shelfFull = false;												//is the bookshelf full or not
	//bool n, s, e, w = false;
	bool c = true;//idk
	item key("key", "2");												//set the required key to be named key and set in the east
	string inventory[10];												//inventory array

	enum location { north, south, east, west, center, person };			 //possible player locations
	location playerPlace = center;										 //set player starting location

	//display possible commands
	cout << "These are the allowed commands: " << endl;
	cout << "commands, north, south, east, \n west, center, move, look, \n pick up, drop, use, items/inventory, \n quit" << endl << endl;

	//item KeyA("KEY A", center);
	//item TestNote("TESTNOTE", person);

	//int capacity = 5;
	//item inventory[capacity] = { TestNote };

	//main game loop-repeats until game is completed
	while (game)
	{
		cout << "What will you do? " << endl;

		getline(cin, command);
		move = false;

		//commands functions
		if (command == "Commands" || command == "COMMANDS" || command == "command")
			cout << "commands, north, south, east, \n west, center, move, look, \n pick up, drop, use, items/inventory, \n quit" << endl << endl;

		//movement functions
		else if (command == "North" || command == "NORTH" || command == "north")
		{
			move = true;
			itemPU = false;
		}
		else if (command == "South" || command == "SOUTH" || command == "south")
		{
			move = true;
			itemPU = false;
		}
		else if (command == "East" || command == "EAST" || command == "east")
		{
			move = true;
			itemPU = false;
		}
		else if (command == "West" || command == "WEST" || command == "west")
		{
			move = true;
			itemPU = false;
		}
		else if (command == "center" || command == "CENTER" || command == "Center")
		{
			move = true;
			itemPU = false;
		}
		else if (command == "MOVE" || command == "Move" || command == "move")
		{
			cout << "Move where? ";
			getline(cin, command);
			move = true;
			itemPU = false;
		}
		if (move)
		{
			if (command == "North" || command == "NORTH" || command == "north")
			{
				if (playerPlace != north)
				{
					cout << "This is the north wall. " << endl << endl;
					playerPlace = north;
					continue;
				}
				else if (playerPlace == north)
				{
					cout << "You cannot go any further north. " << endl << endl;
					continue;
				}
			}
			if (command == "SOUTH" || command == "south" || command == "South")
			{
				if (playerPlace != south)
				{
					cout << "This is the south wall. " << endl << endl;
					playerPlace = south;
					continue;
				}
				else if (playerPlace == south)
				{
					cout << "You cannot go any further south. " << endl << endl;
					continue;
				}
			}
			if (command == "EAST" || command == "East" || command == "east")
			{
				if (playerPlace != east)
				{
					cout << "This is the east wall. " << endl << endl;
					playerPlace = east;
					continue;
				}
				else if (playerPlace == east)
				{
					cout << "You cannot go any further east. " << endl << endl;
					continue;
				}
			}

			if (command == "WEST" || command == "West" || command == "west")
			{
				if (playerPlace != west)
				{
					cout << "This is the west wall. " << endl << endl;
					playerPlace = west;
					continue;
				}
				else if (playerPlace == west)
				{
					cout << "You cannot go any further west. " << endl << endl;
					continue;
				}
			}
			if (command == "CENTER" || command == "center" || command == "Center")
			{
				if (playerPlace != center)
				{
					cout << "This is the center of the room. " << endl << endl;
					playerPlace = center;
					continue;
				}
				else if (playerPlace == center)
				{
					cout << "You are already in the center. " << endl << endl;
					continue;
				}
			}
		}

		//look function-displays description of current player position
		else if (command == "LOOK" || command == "look" || command == "Look")
		{
			if (playerPlace == north)
			{
				cout << "A bookshelf stands, organized into four shelves.\n";
				cout << "Red, yellow, blue and green books lines the shelves from top to bottom.\n";

				if (!shelfFull)
				{
					"There are spaces in the rows where books can fit.\n\n";
				}

				cout << endl;
			}
			else if (playerPlace == south)
			{
				cout << "A steel door with a lock blocks your way.\n";

				/*if (lockA && lockB)
				{
					cout << "Two locks keep it firmly shut.\n\n";
				}

				else if (lockA || lockB)
				{
					cout << "One lock keeps the door shut.\n\n";
				}*/

				cout << endl;
			}
			else if (playerPlace == east)
			{
				cout << "There is a table in the corner with a key and a vase of yellow flowers.\n" << endl;

				/*if (drawLock)
				{
					cout << "The table's drawer has a lock on it.\n\n";
				}*/

				//else { cout << endl; }
			}
			else if (playerPlace == west)
			{
				cout << "There is a painting on the wall of a man "
					"in a top hat with a scar above his left eye.\n" << endl;
			}
			else if (playerPlace == center)
			{
				cout << "There is a table with several books on it.\n" << endl;

				/*if (!cPaperGet)
				{
					cout << "There is a piece of paper peeking out from underneath one book.\n\n";
				}*/

				//else { cout << endl; }
			}
			move = false;
			itemPU = false;
			continue;
		}

		//item functions
		//pick up item
		else if (command == "PICKUP" || command == "Pickup" || command == "pickup" || command == "pick up" || command == "PICK UP" || command == "Pick Up" || command == "PICK-UP")
		{
			cout << "Pick up what? ";
			getline(cin, command);
			move = false;
			itemPU = true;
		}

		//drop item
		else if (command == "DROP" || command == "Drop" || command == "drop")
		{
			cout << "Drop what? ";
			getline(cin, command);
			move = false;
			itemPU = false;
			for (int x = 0;x <= 10;x++)
			{
				if (inventory[x] == command)
				{
					cout << "You dropped the " << inventory[x] << endl << endl;
					inventory[x] = inventory[x + 1];
					for (int y = x;y <= 10;y++)
					{
						inventory[y] = inventory[y];
					}

				}
			}
			continue;
		}

		//use item
		else if (command == "USE" || command == "Use" || command == "use")
		{
			cout << "Use what? ";
			getline(cin, command);
			move = false;
			itemPU = false;
			bool usable = false;
			for (int x = 0;x <= 10;x++)
			{
				if (inventory[x] == command)
				{
					usable = true;
				}
			}
			if (!usable)
				cout << "This item will not work." << endl;
			else
			{
				if (command == "key")
				{
					if (playerPlace == south)
					{
						cout << "Congratulations you unlocked the door and escaped!" << endl;
						game = false;
						continue;
					}
					else if (playerPlace != south)
					{
						cout << "This key does not seem to work with anything here." << endl;
						continue;
					}
				}
			}
		}

		//display current held items
		else if (command == "Items" || command == "ITEMS" || command == "items" || command == "INVENTORY" || command == "Inventory" || command == "inventory")
		{
			cout << "This is what you have: \n";
			cout << inventory[0] << endl << endl;
			move = false;
			itemPU = false;
			continue;
		}

		//main pick up item function
		if (itemPU)
		{
			if (command == "KEY" || command == "Key" || command == "key")//for simple use-only one object is used-key
			{
				if (key.getPlace() == to_string(playerPlace))
				{
					cout << "You picked up the key." << endl << endl;
					inventory[0] = command;      //fix this part for later use in game
					keyGet = true;
					continue;
				}

				else { cout << "That item is not near you.\n\n"; }
			}

			else
				cout << "That is not an available item.\n\n";
		}

		//quit function
		else if (command == "QUIT" || command == "quit" || command == "Quit")
		{
			game = false;
			continue;
		}

		//display error if invalid commands entered
		else
		{
			cout << "Invalid command." << endl;
		}


	}
	return 0;
}