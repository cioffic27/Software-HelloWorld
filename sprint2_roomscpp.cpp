#include<iomanip>
#include<iostream>
#include<string>
#include <stdio.h>
#include <algorithm>
#include "classes.h"
using namespace std;

int main()
{
	//testing
	//descriptions for room 1
	string n1 = "A bookshelf stands, organized into four shelves.  Red, yellow, blue and green books line the shelves from top to bottom.";
	string s1 = "A steel door with a lock blocks your way.";
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
	string n3 = "You see a table of microscopes with different assorted items laid out.";
	string s3 = "You see a table with multiple books laying out closed: One book on thermodynamics, one book on physics, and one book on Neuroscience";
	string e3 = "You see 2 incubators in between them is a computer running simulations.";
	string w3 = " You see a iron bar door which has locked from the outside. Above the door reads a sign : EMERGENCY LOCK-IN PROCEDURE: Rely On Your Brains";
	string c3 = "You find yourself in a laboratory in front of you is a table with beakers and burners and a yellow vial of chemicals in the middle.";

	string command;

	Actions room1(n1, s1, e1, w1, c1);
	Actions room2(n2, s2, e2, w2, c2);
	Actions room3(n3, s3, e3, w3, c3);


	cout << "Welcome to Escape the Room, would you like to play" << endl;
	getline(cin, command);
	transform(command.begin(), command.end(), command.begin(), toupper);
	if (command == "YES")
	{
		cout << "Here is the list of possible commands:" << endl;
		cout << "move, pickup/pick up, use, inventory/items, commands, quit/exit" << endl;
		while (room1.room1_finished != true)
		{
			cout << "What do you want to do" << endl;
			getline(cin, command);
			transform(command.begin(), command.end(), command.begin(), toupper);
			if (command == "MOVE")
				room1.Move();
			else if (command == "PICKUP" || command == "PICK UP")
				room1.Pickup();
			else if (command == "USE")
				room1.Use();
			else if (command == "INVENTORY" || command == "ITEMS")
				room1.Inventory();
			else if (command == "QUIT" || command == "EXIT")
				exit;
			else
				cout << "That is not a valid command" << endl;
		}
		room2.room1_items = false;
		room2.room2_items = true;
		cout << "Welcome to the second room \n";
		while (room2.room2_finished != true)
		{
			cout << "What do you want to do" << endl;
			getline(cin, command);
			transform(command.begin(), command.end(), command.begin(), toupper);
			if (command == "MOVE")
				room2.Move();
			else if (command == "PICKUP" || command == "PICK UP")
				room2.Pickup();
			else if (command == "USE")
				room2.Use();
			else if (command == "INVENTORY" || command == "ITEMS")
				room2.Inventory();
			else if (command == "QUIT" || command == "EXIT")
				exit;
			else
				cout << "That is not a valid command" << endl;
		}
		room3.room1_items = false;
		room3.room2_items = false;
		room3.room3_items = true;
		cout << "Welcome to the Third room \n";
		while (room3.room3_finished != true)
		{
			cout << "What do you want to do" << endl;
			getline(cin, command);
			transform(command.begin(), command.end(), command.begin(), toupper);
			if (command == "MOVE")
				room3.Move();
			else if (command == "PICKUP" || command == "PICK UP")
				room3.Pickup();
			else if (command == "USE")
				room3.Use();
			else if (command == "INVENTORY" || command == "ITEMS")
				room3.Inventory();
			else if (command == "QUIT" || command == "EXIT")
				exit;
			else
				cout << "That is not a valid command" << endl;
		}
		if (room1.room1_finished == true && room2.room2_finished == true && room3.room3_finished == true)
			cout << "Congratulations, you escaped all three rooms!" << endl;
		cin >> command;
	}
	else if (command == "NO")
		cin >> command;
	else
	{
		cout << "that is not a valid command" << endl;
		cin >> command;
	}
	return 0;

}