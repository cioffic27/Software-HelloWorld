#include<iomanip>
#include<iostream>
#include<string>
#include <stdio.h>
#include <algorithm>
#include "classes.h"
using namespace std;

int turn;
int turn_cap;
int total_turns;

int main()
{
	//testing
	//descriptions for room 1
	string n1 = "A bookshelf stands, organized into four shelves.  Books line the shelves from top to bottom, you cannot pick them up.";
	string s1 = "A steel door with a lock blocks you way.";
	string e1 = "There is a table in the corner with a key and a vase of yellow flowers.";
	string w1 = "There is a painting on the wall of a man in a top hat with a scar above his left eye.";
	string c1 = "There is a small table with several books on it.";

	//descriptions for room 2
	string n2 = "You see the door you came through previously, and a blank piece of paper on the ground.";
	string s2 = "You see a china cabinet with a see-through case.  Inside you see a red cup, a blue cup, a bowl with a flower design and a dish.";
	string e2 = "You see a painting of the Last Supper hanging on the wall.  It looks crooked, like it has just been moved.";
	string w2 = "You see a large brick fireplace with sculptures on the mantle and a set of fireplace tools off to the side.  It seems as though there is something hidden under the pile of ash residue inside the fireplace, but you can't make out what it is.";
	string c2 = "You see a large dining room table with ten chairs.  On the table are three candlesticks but they do not have candles inside them.";

	//descriptions for room 3
	string n3 = "You see a table of microscopes with different assorted items laid out; however, none of them seem to be useful to escaping the room.";
	string s3 = "You see a table with multiple books laying out closed: One book on thermodynamics, one book on physics, and one book on Neuroscience.  One of these books contains a key.";
	string e3 = "You see 2 incubators in between them is a computer running simulations.";
	string w3 = " You see a iron bar door which has locked from the outside.  There are four bars colored red, blue, yellow and orange. Above the door reads a sign : EMERGENCY LOCK-IN PROCEDURE: Rely On Your Brains.";
	string c3 = "You find yourself in a laboratory in front of you is a table with beakers and burners and a yellow vial of chemicals in the middle.";

	//descriptions for room 4
	string n4 = "You have entered here. There is nothing else but the door.";
	string s4 = "You see a wine rack here: A bottle of Merlot, Pinot Noir, Pink Moscato, and White Zinfindel. The bottle of White Zinfindel holds a key inside.";
	string e4 = "You see a cellar door with a mechanically powered lock and bar holding it shut. You will need a key and something to power the door to open the lock.";
	string w4 = " You see a decorated Bar with several glasses and alcohol behind. On the bar is a corkscrew and a shovel leans against the front.";
	string c4 = "You see an upturned patch of dirt as if someone has just burried something here.";

	string command;
	bool playing = true;
	bool difficulty = true;

	Actions room1(n1, s1, e1, w1, c1);
	//Actions room2(n2, s2, e2, w2, c2);
	//Actions room3(n3, s3, e3, w3, c3);
	//Actions room4(n4, s4, e4, w4, c4);


	cout << "Welcome to Escape the Room, would you like to play?" << endl;
	getline(cin, command);
	transform(command.begin(), command.end(), command.begin(), toupper);
	if (command == "YES")
	{
		while (playing == true)
		{
			cout << endl;
			cout << "In this game you will be required to move around, pickup and use items in order to escape a room." << endl;
			cout << "Each time you move around the room or successfully use an object counts as a turn." << endl;
			cout << "Depending on the difficulty you select, you will have a set amount of turns to escape all four rooms before you lose." << endl << endl;
			while (difficulty == true)
			{
				cout << "What difficulty do you want to play:  Easy (65 turns), Medium (45 turns), or Hard (35 turns)?" << endl;
				getline(cin, command);
				transform(command.begin(), command.end(), command.begin(), toupper);
				if (command == "EASY")
				{
					turn_cap = 65;
					difficulty = false;
				}
				else if (command == "MEDIUM")
				{
					turn_cap = 45;
					difficulty = false;
				}
				else if (command == "HARD")
				{
					turn_cap = 35;
					difficulty = false;
				}
				else
					cout << endl<<"That is not a valid difficulty level" << endl<<endl;
			}
			cout << endl;
			cout << "Here is the list of possible commands:" << endl;
			cout << "move:  select an area that you want to move to." << endl;
			cout << "pickup/pick up:  choose to pick up an item and if required, the item will be placed in your inventory." << endl;
			cout << "use:  select an item to be used." << endl;
			cout << "inventory/items:  shows a list of current items in your inventory." << endl;
			cout << "commands:  prints the list of commands." << endl;
			cout << "look:  prints the description of the current location you are in." << endl;
			cout << "Turns:  displays how many turns you have taken, and the amount of turns remaining." << endl;
			cout << "quit/exit:  quits the game." << endl << endl;
			room1.SetDescriptions(n1, s1, e1, w1, c1);
			while (room1.room1_finished != true)
			{
				total_turns = room1.turn;
				if (turn_cap - total_turns - 1 == 0)
				{
					cout << endl << "You were not able to escape the house quickly enough and are now trapped forever." << endl << endl;
					room1.restart = true;
					break;
				}
				else if (room1.restart == true)
					break;
				else
				{
					cout << "What do you want to do?" << endl;
					getline(cin, command);
					transform(command.begin(), command.end(), command.begin(), toupper);
					if (command == "MOVE")
					{
						cout << endl;
						room1.Move();
					}
					else if (command == "PICKUP" || command == "PICK UP")
					{
						cout << endl;
						room1.Pickup();
					}
					else if (command == "USE")
					{
						cout << endl;
						room1.Use();
					}
					else if (command == "INVENTORY" || command == "ITEMS")
					{
						cout << endl;
						room1.Inventory();
					}
					else if (command == "COMMANDS")
					{
						cout << endl;
						room1.Commands();
					}
					else if (command == "LOOK")
					{
						cout << endl;
						room1.Look();
					}
					else if (command == "QUIT" || command == "EXIT")
						exit(20);
					else if (command == "TURNS")
					{
						cout << "It is currently turn " << total_turns+1 << endl;
						cout << "You have " << turn_cap - total_turns << " turns remaining." << endl << endl;
					}
					else
						cout << endl << "That is not a valid command." << endl << endl;
				}
			}
			cout << "You have " << turn_cap - total_turns - 1 << " turns remaining." << endl << endl;
			room1.room1_items = false;
			room1.room2_items = true;
			cout << "Welcome to the second room.\n";
			room1.SetDescriptions(n2,s2,e2,w2,c2);
			while (room1.room2_finished != true)
			{
				total_turns = room1.turn;
				if (turn_cap - total_turns - 1 == 0)
				{
					cout << endl << "You were not able to escape the house quickly enough and are now trapped forever." << endl << endl;
					room1.restart = true;
					break;
				}
				else if (room1.restart == true)
					break;
				else
				{
					cout << "What do you want to do?" << endl;
					getline(cin, command);
					transform(command.begin(), command.end(), command.begin(), toupper);
					if (command == "MOVE")
					{
						cout << endl;
						room1.Move();
					}
					else if (command == "PICKUP" || command == "PICK UP")
					{
						cout << endl;
						room1.Pickup();
					}
					else if (command == "USE")
					{
						cout << endl;
						room1.Use();
					}
					else if (command == "INVENTORY" || command == "ITEMS")
					{
						cout << endl;
						room1.Inventory();
					}
					else if (command == "COMMANDS")
					{
						cout << endl;
						room1.Commands();
					}
					else if (command == "LOOK")
					{
						cout << endl;
						room1.Look();
					}
					else if (command == "QUIT" || command == "EXIT")
						exit(20);
					else if (command == "TURNS")
					{
						cout << "It is currently turn " << total_turns+1 << endl;
						cout << "You have " << turn_cap - total_turns << " turns remaining." << endl << endl;
					}
					else
						cout << endl << "That is not a valid command." << endl << endl;
				}
			}
			if (room1.restart != true)
			{
				cout << "You have " << turn_cap - total_turns - 1 << " turns remaining." << endl << endl;
				room1.room1_items = false;
				room1.room2_items = false;
				room1.room3_items = true;
				cout << "Welcome to the Third room. \n";
				room1.SetDescriptions(n3, s3, e3, w3, c3);
				while (room1.room3_finished != true)
				{
					total_turns = room1.turn;
					if (turn_cap - total_turns - 1 == 0)
					{
						cout << endl << "You were not able to escape the house quickly enough and are now trapped forever." << endl << endl;
						room1.restart = true;
						break;
					}
					else if (room1.restart == true)
						break;
					else
					{
						cout << "What do you want to do?" << endl;
						getline(cin, command);
						transform(command.begin(), command.end(), command.begin(), toupper);
						if (command == "MOVE")
						{
							cout << endl;
							room1.Move();
						}
						else if (command == "PICKUP" || command == "PICK UP")
						{
							cout << endl;
							room1.Pickup();
						}
						else if (command == "USE")
						{
							cout << endl;
							room1.Use();
						}
						else if (command == "INVENTORY" || command == "ITEMS")
						{
							cout << endl;
							room1.Inventory();
						}
						else if (command == "COMMANDS")
						{
							cout << endl;
							room1.Commands();
						}
						else if (command == "LOOK")
						{
							cout << endl;
							room1.Look();
						}
						else if (command == "QUIT" || command == "EXIT")
							exit(20);
						else if (command == "TURNS")
						{
							cout << "It is currently turn " << total_turns+1 << endl;
							cout << "You have " << turn_cap - total_turns << " turns remaining." << endl << endl;
						}
						else
							cout << endl << "That is not a valid command." << endl << endl;
					}
				}
				if (room1.restart != true)
				{
					cout << "You have " << turn_cap - total_turns - 1 << " turns remaining." << endl << endl;
					room1.room1_items = false;
					room1.room2_items = false;
					room1.room3_items = false;
					room1.room4_items = true;
					cout << "Welcome to the Fourth room! \n";
					room1.SetDescriptions(n4, s4, e4, w4, c4);
					while (room1.room4_finished != true)
					{
						total_turns = room1.turn;
						if (turn_cap - total_turns - 1 == 0)
						{
							cout << endl << "You were not able to escape the house quickly enough and are now trapped forever." << endl << endl;
							room1.restart = true;
							break;
						}
						else if (room1.restart == true)
							break;
						else
						{
							cout << "What do you want to do?" << endl;
							getline(cin, command);
							transform(command.begin(), command.end(), command.begin(), toupper);
							if (command == "MOVE")
							{
								cout << endl;
								room1.Move();
							}
							else if (command == "PICKUP" || command == "PICK UP")
							{
								cout << endl;
								room1.Pickup();
							}
							else if (command == "USE")
							{
								cout << endl;
								room1.Use();
							}
							else if (command == "INVENTORY" || command == "ITEMS")
							{
								cout << endl;
								room1.Inventory();
							}
							else if (command == "COMMANDS")
							{
								cout << endl;
								room1.Commands();
							}
							else if (command == "LOOK")
							{
								cout << endl;
								room1.Look();
							}
							else if (command == "QUIT" || command == "EXIT")
								exit(20);
							else if (command == "TURNS")
							{
								cout << "It is currently turn " << total_turns+1 << endl;
								cout << "You have " << turn_cap - total_turns << " turns remaining." << endl << endl;
							}
							else
								cout << endl << "That is not a valid command." << endl << endl;
						}
					}
					if (room1.restart != true)
					{
						cout << endl << "You walk through the door and enter a dark hallway.  You see a faint light in the distance and carefully make your way towards the light. " << endl;
						cout << "When you reach the end of the hallway you see the outline of trees and realize you are outside and have been able to finally escape the house." << endl << endl << endl;
						cout << "Congratulations you were able to complete the game in " << total_turns << " turns!" << endl << endl;
					}
				}
			}
				cout << "Would you like to play again?" << endl;
				getline(cin, command);
				transform(command.begin(), command.end(), command.begin(), toupper);
				if (command == "YES")
				{
					difficulty = true;
							room1.Restart();
				}
				else if (command == "NO")
					exit(20);
		}
	}
	else if (command == "NO")
		exit(20);
	else
	{
		cout << "That is not a valid command." << endl;
		cin >> command;
	}
	return 0;

}