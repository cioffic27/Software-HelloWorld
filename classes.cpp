#include<iomanip>
#include<iostream>
#include<string>
#include <stdio.h>
#include <algorithm>
#include "classes.h"
using namespace std;

Node::Node(string x)
{
	data = x;
	next = nullptr;
}

LinkedList::LinkedList()
{
	head = nullptr;
}

void LinkedList::InsertAtFront(string x)
{
	Node* node = new Node(x);
	node->next = head;
	head = node;
}

int LinkedList::Search(string x)
{
	Node* temp = head;
	int pos = 1;

	while (temp != nullptr)
	{
		if (temp->data == x)
		{
			return pos;
		}
		else {
			temp = temp->next;
			pos++;
		}
	}
	return 0;
}

void LinkedList::DeleteByValue(string x)
{
	int pos = Search(x);
	if (pos == 0)
	{
		cout << "Value not found" << endl;
	}
	else
	{
		// DeleteAtPosistion(pos);
		Node* prev = nullptr;
		Node* temp = head;
		if (head == nullptr) { cout << "Nothing to delete" << endl; }
		else if (pos == 1)
		{
			if (head != nullptr)
			{
				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}
		else {
			for (int i = 1; i < pos; i++) {
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			delete temp;
		}
	}
}

void LinkedList::DeleteAtPosition(int pos)
{
	Node* prev = nullptr;
	Node* temp = head;
	if (head == nullptr) { cout << "Nothing to delete" << endl; }
	else if (pos == 1)
	{
		if (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	else {
		for (int i = 1; i < pos; i++) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		delete temp;
	}
}

void LinkedList::Print()
{
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " " << endl;
		temp = temp->next;
	}
	cout << endl;
}

Movement::Movement()
{
	north_des = "";
	south_des = "";
	east_des = "";
	west_des = "";
	center_des = "";
}

Movement::Movement(string n, string s, string e, string w, string c)
{
	north_des = n;
	south_des = s;
	east_des = e;
	west_des = w;
	center_des = c;
}

void Movement::Move()
{
	cout << "Where would you like to move? (north, south, east, west, center)" << endl;
	getline(cin, input);
	transform(input.begin(), input.end(), input.begin(), toupper);
	if (input == "NORTH")
		North();
	else if (input == "SOUTH")
		South();
	else if (input == "EAST")
		East();
	else if (input == "WEST")
		West();
	else if (input == "CENTER")
		Center();
	else
		cout << "That is not a valid area to move to." << endl;
}

void Movement::North()
{
	if (playerPlace == north)
		cout << "you are already in the north end of the room." << endl;
	else
	{
		turn++;
		cout << "You are in the north end of the room." << endl << endl;
		playerPlace = north;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << north_des << endl;
		else
			cout << endl;
	}
}

void Movement::South()
{
	if (playerPlace == south)
		cout << "you are already in the south end of the room." << endl;
	else
	{
		turn++;
		cout << "You are in the south end of the room." << endl << endl;
		playerPlace = south;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << south_des << endl;
	}

}

void Movement::East()
{
	if (playerPlace == east)
		cout << "you are already in the east end of the room." << endl;
	else
	{
		turn++;
		cout << "You are in the east end of the room." << endl << endl;
		playerPlace = east;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << east_des << endl;
	}

}

void Movement::West()
{
	if (playerPlace == west)
		cout << "you are already in the west end of the room." << endl;
	else
	{
		turn++;
		cout << "You are in the west end of the room." << endl << endl;
		playerPlace = west;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << west_des << endl;
	}

}

void Movement::Center()
{
	if (playerPlace == center)
		cout << "you are already in the center of the room." << endl;
	else
	{
		turn++;
		cout << "You are in the center of the room." << endl << endl;
		playerPlace = center;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << center_des << endl;
	}

}

Actions::Actions(string n, string s, string e, string w, string c)
{
	north_des = n;
	south_des = s;
	east_des = e;
	west_des = w;
	center_des = c;
}

void Actions::Pickup()
{
	cout << "What do you want to pick up?" << endl;
	getline(cin, command);
	transform(command.begin(), command.end(), command.begin(), toupper);
	if (room1_items == true)
	{
		if (command == "KEY")
		{
			if (playerPlace == east)
			{
				cout << "you picked up the key" << endl;
				list->InsertAtFront("key");
			}
		}
	}
	else if (room2_items == true)
	{
		if (command == "PAPER")
		{
			if (playerPlace == north)
			{
				cout << "you picked up the paper, on the back of it you see the numbers 6184." << endl;
				list->InsertAtFront("paper");
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "FIRE")
		{
			if (playerPlace == west)
			{
				cout << "You picked up the fire" << endl;
				cout << "You are now on fire!" << endl;
				cout << "You died.  Game Over." << endl;
				exit(20);
			}
			else
				cout << "This item is not here" << endl;
		}
		else if (command == "DISH")
		{
			if (playerPlace == south)
			{
				cout << "you pick up the dish and it's just a plain white dish, but as you move it you notice a candle lying behind it." << endl;
				list->InsertAtFront("dish");
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "CANDLE")
		{
			if (playerPlace == west)
			{
				cout << "you picked up the candle" << endl;
				list->InsertAtFront("candle1");
			}
			else if (playerPlace == east)
			{
				cout << "you picked up the candle" << endl;
				list->InsertAtFront("candle2");
			}
			else if (playerPlace == south)
			{
				cout << "You picked up the candle." << endl;
				list->InsertAtFront("candle3");
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "PAINTING")
		{
			if (playerPlace == east)
				cout << "you picked up the painting, there was a safe behind it" << endl;
		}
		else if (command == "TOOLS")
		{
			if (playerPlace == west)
			{
				cout << "you picked up the tools" << endl;
				list->InsertAtFront("tools");
			}
		}
		else
			cout << "this item is not here" << endl;
	}
	else if (room3_items == true)
	{
		if (command == "YELLOW VIAL")
		{
			if (playerPlace == center)
			{
				cout << "you picked up the yellow vial" << endl;
				list->InsertAtFront("yellow vial");
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "RED VIAL")
		{
			if (playerPlace == east)
			{
				cout << "you picked up the red vial" << endl;
				list->InsertAtFront("red vial");
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "BLUE VIAL")
		{
			if (playerPlace == east)
			{
				cout << "you picked up the blue vial" << endl;
				list->InsertAtFront("blue vial");
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "ORANGE VIAL")
		{
			if (playerPlace == east)
			{
				cout << "you picked up the orange vial" << endl;
				list->InsertAtFront("orange vial");
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "BOOK")
		{
			if (playerPlace == south)
			{
				cout << "you picked up the Neuroscience book, inside it you see an incubator key." << endl;
				list->InsertAtFront("neuroscience book");
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "INCUBATOR KEY")
		{
			if (playerPlace == south)
			{
				cout << "you picked up the Incubator Key" << endl;
				list->InsertAtFront("incubator key");
			}
			else
				cout << "this item is not here" << endl;
		}
	}
	else if (room4_items == true)
	{
		if (command == "SHOVEL")
		{
			if (playerPlace == west)
			{
				cout << "you picked up the shovel" << endl;
				list->InsertAtFront("shovel");
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "CORKSCREW")
		{
			if (playerPlace == west)
			{
				cout << "you picked up the corkscrew" << endl;
				list->InsertAtFront("corkscrew");
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "BATTERY")
		{
			if (playerPlace == center)
			{
				cout << "you picked up the battery" << endl;
				list->InsertAtFront("battery");
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "WHITE ZINFINDEL")
		{
			if (playerPlace == south)
			{
				cout << "you picked up the white zinfindel" << endl;
				white_zin = true;
			}
			else
				cout << "this item is not here" << endl;
		}
		else if (command == "KEY")
		{
			{
				cout << "you picked up the key" << endl;
				list->InsertAtFront("key");
			}
		}
	}
}

void Actions::Use()
{
	cout << "What do you want to use?" << endl;
	getline(cin, command);
	transform(command.begin(), command.end(), command.begin(), tolower);

	if (command == "safe")
	{
		if (playerPlace == east)
		{
			cout << "What is the code to open the safe?" << endl;
			cin >> code_guess;
			if (code_guess == code_correct)
			{
				cout << "you successfully opened the safe.  Inside there is a candle." << endl;
				getline(cin, command);
				transform(command.begin(), command.end(), command.begin(), toupper);
				turn++;
			}
			else if (code_guess != code_correct)
			{
				cout << "you didn't enter the correct code." << endl;
				getline(cin, command);
				transform(command.begin(), command.end(), command.begin(), toupper);
				turn++;
			}
		}
		else if (playerPlace != east)
		{
			cout << "the safe is not in this area" << endl;
			getline(cin, command);
			transform(command.begin(), command.end(), command.begin(), toupper);
		}
	}
	else
	{
		int pos = list->Search(command);
		if (pos == 0)
		{
			cout << "You do not have that item" << endl;
		}
		else if (pos != 0)
		{
			if (room1_items == true)
			{
				if (command == "key")
				{
					if (playerPlace == south)
					{
						turn++;
						list->DeleteByValue(command);
						cout << "The door unlocks and you open it, heading into another room" << endl << endl;
						room1_finished = true;
						room1_items = false;
					}
					else if (playerPlace != south)
					{
						cout << "This key does not seem to work with anything here." << endl;
					}
				}
			}
			else if (room2_items == true)
			{
				if (command == "paper")
				{
					cout << "You have used the " << command << ", on it is the code 6184." << endl;
					turn++;
				}
				else if (command == "candle1")
				{
					if (playerPlace == center)
					{
						cout << "you placed the first candle in the candlestick" << endl;
						candle1_used = true;
						turn++;
						list->DeleteByValue(command);
						if (candle1_used == true && candle2_used == true && candle3_used == true)
						{
							cout << "As you place the last candle you hear a clicking sound.  Suddenly the table and floor move, revealing a secret passageway which you walk down." << endl;
							room2_finished = true;
							room2_items = false;
						}
					}
					else
						cout << "you cannot use that here." << endl;
				}
				else if (command == "candle2")
				{
					if (playerPlace == center)
					{
						cout << "you placed the second candle in the candlestick" << endl;
						candle2_used = true;
						turn++;
						list->DeleteByValue(command);
						if (candle1_used == true && candle2_used == true && candle3_used == true)
						{
							cout << "As you place the last candle you hear a clicking sound.  Suddenly the table and floor move, revealing a secret passageway which you walk down." << endl;
							room2_finished = true;
							room2_items = false;
						}
					}
					else
						cout << "you cannot use that here." << endl;
				}
				else if (command == "candle3")
				{
					if (playerPlace == center)
					{
						cout << "you placed the third candle in the candlestick" << endl;
						candle3_used = true;
						turn++;
						list->DeleteByValue(command);
						if (candle1_used == true && candle2_used == true && candle3_used == true)
						{
							cout << "As you place the last candle you hear a clicking sound.  Suddenly the table and floor move, revealing a secret passageway which you walk down." << endl;
							room2_finished = true;
							room2_items = false;
						}
					}
					else
						cout << "you cannot use that here." << endl;
				}
				else if (command == "tools")
				{
					if (playerPlace == west)
					{
						cout << "you used the fireplace tools to remove the ash from the fireplace, you can now see a candle laying inside the fireplace" << endl;
						turn++;
					}
				}
			}
			else if (room3_items == true)
			{
				if (command == "incubator key")
				{
					if (playerPlace == east)
					{
						cout << "You used the incubator key to open both incubators, you can now see an orange vial, a blue vial and a red vial" << endl;
						list->DeleteByValue(command);
						turn++;
					}
				}
				else if (command == "red vial")
				{
					if (playerPlace == west)
					{
						cout << "one of the four bars has melted" << endl;
						bar1 = 0;
						list->DeleteByValue(command);
						turn++;
						if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
						{
							cout << "all four bars are melted, you were able to open the door and escape" << endl;
							room3_finished = true;
							room3_items = false;
						}
					}
					else if(playerPlace!=west)
					{
						cout << "As soon as the liquid hits the floor it turns to gas" << endl;
						cout << "You begin to choke on the gas" << endl;
						cout << "You died! Game Over.";
						exit(20);
					}
				}
				else if (command == "orange vial")
				{
					if (playerPlace == west)
					{
						cout << "one of the four bars has melted" << endl;
						bar2 = 0;
						list->DeleteByValue(command);
						turn++;
						if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
						{
							cout << "all four bars are melted, you were able to open the door and escape" << endl;
							room3_finished = true;
							room3_items = false;
						}
					}
					else if(playerPlace!=west)
					{
						cout << "As soon as the liquid hits the floor it turns to gas" << endl;
						cout << "You begin to choke on the gas" << endl;
						cout << "You died! Game Over.";
						exit(20);
					}
				}
				else if (command == "yellow vial")
				{
					if (playerPlace == west)
					{
						cout << "One of the four bars has melted" << endl;
						bar3 = 0;
						list->DeleteByValue(command);
						turn++;
						if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
						{
							cout << "all four bars are melted, you were able to open the door and escape" << endl;
							room3_finished = true;
							room3_items = false;
						}
					}
					else if(playerPlace!=west)
					{
						cout << "As soon as the liquid hits the floor it turns to gas" << endl;
						cout << "You begin to choke on the gas" << endl;
						cout << "You died! Game Over.";
						exit(20);
					}
				}
				else if (command == "blue vial")
				{
					if (playerPlace == west)
					{
						cout << "One of the four bars has melted" << endl;
						bar4 = 0;
						list->DeleteByValue(command);
						turn++;
						if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
						{
							cout << "all four bars are melted, you were able to open the door and escape" << endl;
							room3_finished = true;
							room3_items = false;
						}
					}
					else if(playerPlace!=west)
					{
						cout << "As soon as the liquid hits the floor it turns to gas" << endl;
						cout << "You begin to choke on the gas" << endl;
						cout << "You died! Game Over.";
						exit(20);
					}
				}
			}
			else if(room4_items==true)
			{
			if (command == "corkscrew")
			{
				if (white_zin == true)
				{
					cout << "You have used the corkscrew inside the bottle was a key." << endl;
					list->DeleteByValue(command);
					turn++;
				}
				else
				{
					cout << "You must have a wine bottle to use the corkscrew." << endl;
				}
			}
			else if (command == "shovel")
			{
				if (playerPlace == center)
				{
					cout << "You dug up a battery." << endl;
					list->DeleteByValue(command);
					turn++;
				}
				else
					cout << "you cannot use that here." << endl;
			}
			else if (command == "white zinfindel")
			{
				int pos = list->Search("corkscrew");
				if (pos != 0)
				{
					cout << "You have used the corkscrew inside the bottle was a key." << endl;
					list->DeleteByValue("corkscrew");
					turn++;
				}
				else
				cout << "Uh oh! You need something that can open this wine bottle." << endl;
				list->DeleteByValue(command);
			}
			else if (command == "key")
			{
				if (playerPlace == east)
				{
					cout << "You have used the key on the door.";
					cellar_key_used = true;
					turn++;
					if (battery_used == false)
						cout << "  But you still need a power supply for the motorized door." << endl;
					list->DeleteByValue(command);
					if (cellar_key_used == true && battery_used == true)
					{
						cout << "As power is restored to the door and the key is turned, a bright light appears through the cracks." << endl;
						room4_finished = true;
						room4_items = false;
					}
				}
				else
					cout << "you cannot use that here." << endl;
			}
			else if (command == "battery")
			{
				if (playerPlace == east)
				{
					cout << "You have used the battery to power the motorized door.";
					battery_used = true;
					turn++;
					if (cellar_key_used == false)
						cout << "  But you still need a key for the lock" << endl;
					list->DeleteByValue(command);
					if (cellar_key_used == true && battery_used == true)
					{
						cout << "As power is restored to the door and the key is turned, a bright light appears through the cracks." << endl;
						room4_finished = true;
						room4_items = false;
					}
				}
				else
					cout << "you cannot use that here." << endl;
			}
		}
		}
	}
}

void Actions::Inventory()
{
	cout << "Your inventory is: " << endl;
	list->Print();
	cout << endl;
}

void Actions::Commands()
{
	cout << "These are the possible commands:" << endl;
	cout << "move, pickup/pick up, use, inventory/items, commands, quit/exit" << endl << endl;
}

