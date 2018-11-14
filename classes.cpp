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
		cout << "Value not found." << endl;
	}
	else
	{
		// DeleteAtPosistion(pos);
		Node* prev = nullptr;
		Node* temp = head;
		if (head == nullptr) { cout << "Nothing to delete." << endl; }
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
	if (head == nullptr) { cout << "Nothing to delete." << endl; }
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
	{
		cout << endl;
		cout << "That is not a valid area to move to." << endl;
	}
}

void Movement::North()
{
	if (playerPlace == north)
	{
		cout << endl;
		cout << "You are already in the north end of the room." << endl << endl;
	}
	else
	{
		turn++;
		cout << endl<<"You are in the north end of the room." << endl << endl;
		playerPlace = north;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << endl<<north_des << endl;
		else
			cout << endl;
	}
}

void Movement::South()
{
	if (playerPlace == south)
	{
		cout << endl;
		cout << "You are already in the south end of the room." << endl<<endl;
	}
	else
	{
		turn++;
		cout << endl<<"You are in the south end of the room." << endl << endl;
		playerPlace = south;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << endl<<south_des << endl<<endl;
		else
			cout << endl;
	}

}

void Movement::East()
{
	if (playerPlace == east)
	{
		cout << endl;
		cout << "You are already in the east end of the room." << endl<<endl;
	}
	else
	{
		turn++;
		cout << endl<<"You are in the east end of the room." << endl << endl;
		playerPlace = east;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << endl<<east_des << endl<<endl;
		else
			cout << endl;
	}

}

void Movement::West()
{
	if (playerPlace == west)
	{
		cout << endl;
		cout << "You are already in the west end of the room." << endl<<endl;
	}
	else
	{
		turn++;
		cout << endl<<"You are in the west end of the room." << endl << endl;
		playerPlace = west;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << endl<<west_des << endl<<endl;
		else
			cout << endl;
	}

}

void Movement::Center()
{
	if (playerPlace == center)
	{
		cout << endl;
		cout << "You are already in the center of the room." <<endl<< endl;
	}
	else
	{
		turn++;
		cout << endl<<"You are in the center of the room." << endl << endl;
		playerPlace = center;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << endl<<center_des << endl<<endl;
		else
			cout << endl;
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
	transform(command.begin(), command.end(), command.begin(), tolower);
	int pos = list->Search(command);
	if (pos != 0)
	{
		cout << endl<<"You already picked up this item." << endl<<endl;
	}
	else if (pos == 0)
	{
		transform(command.begin(), command.end(), command.begin(), toupper);
		if (room1_items == true)
		{
			if (command == "KEY")
			{
				if (playerPlace == east)
				{
					cout << endl<<"You picked up the key." <<endl<< endl;
					list->InsertAtFront("key");
				}
				else
					cout << endl<<"That item is not here." << endl<<endl;
			}
			else
				cout << endl<<"You can't pick that up." <<endl<<endl;
		}
		else if (room2_items == true)
		{
			if (command == "PAPER")
			{
				if (playerPlace == north)
				{
					cout << endl<<"You picked up the paper, on the back of it you see the numbers 6184." << endl<<endl;
					list->InsertAtFront("paper");
				}
				else
					cout << endl<<"This item is not here." << endl<<endl;
			}
			else if (command == "FIRE")
			{
				if (playerPlace == west)
				{
					cout << endl<<"You picked up the fire." << endl;
					cout << "You are now on fire!" << endl;
					cout << "You died.  Game Over." << endl;
					exit(20);
				}
				else
					cout <<endl<< "This item is not here." << endl<<endl;
			}
			else if (command == "DISH")
			{
				if (playerPlace == south)
				{
					cout << endl<<"You pick up the dish and it's just a plain white dish, but as you move it you notice a candle lying behind it." << endl<<endl;
					dish_pickup = true;
				}
				else
					cout << endl<< "This item is not here." << endl<<endl;
			}
			else if (command == "CANDLE")
			{
				if (playerPlace == west)
				{
					if (tools_used == true)
					{
						cout << endl<<"You picked up the candle." << endl<<endl;
						list->InsertAtFront("candle1");
					}
					else
						cout <<endl<< "You don't see a candle here yet." << endl<<endl;
				}
				else if (playerPlace == east)
				{
					if (safe_cracked == true)
					{
						cout << endl<<"You picked up the candle." <<endl<< endl;
						list->InsertAtFront("candle2");
					}
					else
						cout << endl<<"You don't see a candle here yet." << endl<<endl;
				}
				else if (playerPlace == south)
				{
					if (dish_pickup == true)
					{
						cout << endl<<"You picked up the candle." << endl<<endl;
						list->InsertAtFront("candle3");
					}
					else
						cout << endl<<"You don't see a candle here yet." << endl<<endl;
				}
				else
					cout <<endl<< "this item is not here" << endl<<endl;
			}
			else if (command == "PAINTING")
			{
				if (playerPlace == east)
				{
					cout << endl<<"You picked up the painting, there was a safe behind it." << endl<<endl;
					painting_moved = true;
				}
				else
					cout << endl<<"That item is not here." << endl<<endl;
			}
			else if (command == "TOOLS")
			{
				if (playerPlace == west)
				{
					cout << endl<<"You picked up the tools." << endl<<endl;
					list->InsertAtFront("tools");
				}
				else
					cout << endl<<"That item is not here." << endl<<endl;
			}
			else
				cout << endl<<"That item cannot be picked up." <<endl<< endl;
		}
		else if (room3_items == true)
		{
			if (command == "YELLOW VIAL")
			{
				if (playerPlace == center)
				{
					cout << endl<<"You picked up the yellow vial." << endl<<endl;
					list->InsertAtFront("yellow vial");
				}
				else
					cout << endl<<"This item is not here." <<endl<< endl;
			}
			else if (command == "RED VIAL")
			{
				if (playerPlace == east)
				{
					if (key_used == true)
					{
						cout << endl<<"You picked up the red vial." << endl<<endl;
						list->InsertAtFront("red vial");
					}
					else
						cout <<endl<< "You can't reach this object yet." << endl<<endl;
				}
				else
					cout << endl<<"This item is not here." <<endl<< endl;
			}
			else if (command == "BLUE VIAL")
			{
				if (playerPlace == east)
				{
					if (key_used == true)
					{
						cout << endl<<"You picked up the blue vial." << endl<<endl;
						list->InsertAtFront("blue vial");
					}
					else
						cout << endl<<"You can't reach this object yet." <<endl<< endl;
				}
				else
					cout <<endl<< "This item is not here." <<endl<< endl;
			}
			else if (command == "ORANGE VIAL")
			{
				if (playerPlace == east)
				{
					if (key_used == true)
					{
						cout << endl<<"You picked up the orange vial." <<endl<< endl;
						list->InsertAtFront("orange vial");
					}
					else
						cout << endl<<"You can't reach this object yet." << endl<<endl;
				}
				else
					cout << endl<<"This item is not here." << endl<<endl;
			}
			else if (command == "BOOK")
			{
				if (playerPlace == south)
				{
					cout << endl<<"You picked up the Neuroscience book; inside it you see an incubator key." << endl<<endl;
					list->InsertAtFront("neuroscience book");
					book_pickup = true;
				}
				else
					cout <<endl<< "This item is not here." << endl<<endl;
			}
			else if (command == "INCUBATOR KEY")
			{
				if (playerPlace == south)
				{
					if (book_pickup == true)
					{
						cout << endl<<"You picked up the Incubator Key." << endl<<endl;
						list->InsertAtFront("incubator key");
					}
					else
						cout << endl<<"You don't see a key here" << endl<<endl;
				}
				else
					cout << endl<<"This item is not here." << endl<<endl;
			}
			else
				cout << endl<<"That item cannot be picked up." << endl<<endl;
		}
		else if (room4_items == true)
		{
			if (command == "SHOVEL")
			{
				if (playerPlace == west)
				{
					cout << endl<<"You picked up the shovel." << endl<<endl;
					list->InsertAtFront("shovel");
				}
				else
					cout << endl<<"This item is not here." << endl<<endl;
			}
			else if (command == "CORKSCREW")
			{
				if (playerPlace == west)
				{
					cout << endl<<"You picked up the corkscrew." << endl<<endl;
					list->InsertAtFront("corkscrew");
				}
				else
					cout << endl<<"This item is not here." << endl<<endl;
			}
			else if (command == "BATTERY")
			{
				if (playerPlace == center)
				{
					if (shovel_used == true)
					{
						cout << endl<<"You picked up the battery." << endl<<endl;
						list->InsertAtFront("battery");
					}
					else
						cout <<endl<< "You don't see a battery here." << endl<<endl;
				}
				else
					cout <<endl<< "This item is not here." << endl<<endl;
			}
			else if (command == "WHITE ZINFINDEL")
			{
				if (playerPlace == south)
				{
					cout << endl<<"You picked up the white zinfindel." << endl<<endl;
					list->InsertAtFront("white zinfindel");
					white_zin = true;
				}
				else
					cout << endl<<"This item is not here." <<endl<< endl;
			}
			else if (command == "KEY")
			{
				if (playerPlace == south)
				{
					if (bottle_opened == true)
					{
						cout <<endl<< "You picked up the key." <<endl<< endl;
						list->InsertAtFront("key");
					}
					else
						cout <<endl<< "You can't get the key out yet." << endl<<endl;
				}
				else
					cout << endl<<"That item is not here." << endl<<endl;
			}
			else
				cout << endl<<"That item cannot be picked up." << endl<<endl;
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
			if (painting_moved == true)
			{
				cout << endl<<"What is the code to open the safe?" << endl;
				cin >> code_guess;
				if (code_guess == code_correct)
				{
					cout << endl<<"You successfully opened the safe.  Inside there is a candle." << endl<<endl;
					getline(cin, command);
					transform(command.begin(), command.end(), command.begin(), toupper);
					turn++;
					safe_cracked = true;
				}
				else if (code_guess != code_correct)
				{
					cout << endl<<"You didn't enter the correct code." << endl<<endl;
					getline(cin, command);
					transform(command.begin(), command.end(), command.begin(), toupper);
					turn++;
				}
			}
			else
				cout << endl<<"You don't see a safe here." << endl<<endl;
		}
		else if (playerPlace != east)
		{
			cout << endl<<"The safe is not in this area." <<endl<< endl;
			getline(cin, command);
			transform(command.begin(), command.end(), command.begin(), toupper);
		}
	}
	else
	{
		int pos = list->Search(command);
		if (pos == 0)
		{
			cout << endl<<"You do not have that item." << endl<<endl;
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
						cout << endl<<"The door unlocks and you open it, heading into another room." << endl << endl;
						room1_finished = true;
						room1_items = false;
					}
					else if (playerPlace != south)
					{
						cout << endl<<"This key does not seem to work with anything here." << endl<<endl;
					}
				}
			}
			else if (room2_items == true)
			{
				if (command == "paper")
				{
					cout << endl<<"You have used the " << command << ", on it is the code 6184." << endl<<endl;
					turn++;
				}
				else if (command == "candle1")
				{
					if (playerPlace == center)
					{
						cout << endl<<"You placed the first candle in the candlestick." <<endl<< endl;
						candle1_used = true;
						candles_used++;
						if (candles_used == 1)
							center_des = "You see a large dining room table with ten chairs.  On the table are three candlesticks, only one of them has a candle inside it.";
						else if (candles_used == 2)
							center_des = "You see a large dining room table with ten chairs.  On the table are three candlesticks, only two of them has a candle inside it.";
						turn++;
						list->DeleteByValue(command);
						if (candle1_used == true && candle2_used == true && candle3_used == true)
						{
							cout <<"As you place the last candle you hear a clicking sound.  Suddenly the table and floor move, revealing a secret passageway which you walk down." << endl<<endl;
							room2_finished = true;
							room2_items = false;
						}
					}
					else
						cout <<endl<< "You cannot use that here." << endl<<endl;
				}
				else if (command == "candle2")
				{
					if (playerPlace == center)
					{
						cout << endl<<"You placed the second candle in the candlestick." << endl<<endl;
						candle2_used = true;
						candles_used++;
						if (candles_used == 1)
							center_des = "You see a large dining room table with ten chairs.  On the table are three candlesticks, only one of them has a candle inside it.";
						else if (candles_used == 2)
							center_des = "You see a large dining room table with ten chairs.  On the table are three candlesticks, only two of them has a candle inside it.";
						turn++;
						list->DeleteByValue(command);
						if (candle1_used == true && candle2_used == true && candle3_used == true)
						{
							cout <<"As you place the last candle you hear a clicking sound.  Suddenly the table and floor move, revealing a secret passageway which you walk down." << endl<<endl;
							room2_finished = true;
							room2_items = false;
						}
					}
					else
						cout << endl<<"You cannot use that here." << endl<<endl;
				}
				else if (command == "candle3")
				{
					if (playerPlace == center)
					{
						cout << endl<<"You placed the third candle in the candlestick." << endl<<endl;
						candle3_used = true;
						candles_used++;
						if (candles_used == 1)
							center_des = "You see a large dining room table with ten chairs.  On the table are three candlesticks, only one of them has a candle inside it.";
						else if (candles_used == 2)
							center_des = "You see a large dining room table with ten chairs.  On the table are three candlesticks, only two of them has a candle inside it.";
						turn++;
						list->DeleteByValue(command);
						if (candle1_used == true && candle2_used == true && candle3_used == true)
						{
							cout <<"As you place the last candle you hear a clicking sound.  Suddenly the table and floor move, revealing a secret passageway which you walk down." <<endl<< endl;
							room2_finished = true;
							room2_items = false;
						}
					}
					else
						cout << endl<<"You cannot use that here." <<endl<< endl;
				}
				else if (command == "tools")
				{
					if (playerPlace == west)
					{
						cout << endl<<"You used the fireplace tools to remove the ash from the fireplace, you can now see a candle laying inside the fireplace." << endl;
						list->DeleteByValue(command);
						turn++;
						tools_used = true;
					}
					else
						cout << endl<<"You cannot use that here." << endl<<endl;
				}
			}
			else if (room3_items == true)
			{
				if (command == "incubator key")
				{
					if (playerPlace == east)
					{
						cout << endl<<"You used the incubator key to open both incubators, you can now see an orange vial, a blue vial and a red vial." <<endl<< endl;
						list->DeleteByValue(command);
						key_used = true;
						turn++;
					}
					else
						cout << endl<<"You cannot use that here." << endl<<endl;
				}
				else if (command == "red vial")
				{
					if (playerPlace == west)
					{
						cout <<endl<< "One of the four bars has melted." << endl<<endl;
						bar1 = 0;
						list->DeleteByValue(command);
						turn++;
						if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
						{
							cout << "All four bars are melted, you were able to open the door and escape." << endl<<endl;
							room3_finished = true;
							room3_items = false;
						}
					}
					else if(playerPlace!=west)
					{
						cout << endl<<"As soon as the liquid hits the floor it turns to gas." << endl;
						cout << "You begin to choke on the gas." << endl;
						cout << "You died! Game Over.";
						exit(20);
					}
				}
				else if (command == "orange vial")
				{
					if (playerPlace == west)
					{
						cout << endl<<"One of the four bars has melted." << endl<<endl;
						bar2 = 0;
						list->DeleteByValue(command);
						turn++;
						if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
						{
							cout <<"All four bars are melted, you were able to open the door and escape." << endl<<endl;
							room3_finished = true;
							room3_items = false;
						}
					}
					else if(playerPlace!=west)
					{
						cout << endl<<"As soon as the liquid hits the floor it turns to gas." << endl;
						cout << "You begin to choke on the gas." << endl;
						cout << "You died! Game Over.";
						exit(20);
					}
				}
				else if (command == "yellow vial")
				{
					if (playerPlace == west)
					{
						cout << endl<<"One of the four bars has melted." << endl<<endl;
						bar3 = 0;
						list->DeleteByValue(command);
						turn++;
						if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
						{
							cout <<"All four bars are melted, you were able to open the door and escape." << endl<<endl;
							room3_finished = true;
							room3_items = false;
						}
					}
					else if(playerPlace!=west)
					{
						cout << endl<<"As soon as the liquid hits the floor it turns to gas." << endl;
						cout << "You begin to choke on the gas." << endl;
						cout << "You died! Game Over.";
						exit(20);
					}
				}
				else if (command == "blue vial")
				{
					if (playerPlace == west)
					{
						cout << endl<<"One of the four bars has melted." <<endl<< endl;
						bar4 = 0;
						list->DeleteByValue(command);
						turn++;
						if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
						{
							cout <<"All four bars are melted, you were able to open the door and escape." << endl<<endl;
							room3_finished = true;
							room3_items = false;
						}
					}
					else if(playerPlace!=west)
					{
						cout << endl<<"As soon as the liquid hits the floor it turns to gas." << endl;
						cout << "You begin to choke on the gas." << endl;
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
					cout << endl<<"You have used the corkscrew inside the bottle was a key." << endl<<endl;
					list->DeleteByValue(command);
					list->DeleteByValue("white zinfindel");
					turn++;
					bottle_opened = true;
				}
				else
				{
					cout << endl<<"You must have a wine bottle to use the corkscrew." << endl<<endl;
				}
			}
			else if (command == "shovel")
			{
				if (playerPlace == center)
				{
					cout << endl<<"As you shovel the dirt, you see a battery that was hidden underneath." << endl<<endl;
					list->DeleteByValue(command);
					turn++;
					shovel_used = true;
				}
				else
					cout << endl<<"You cannot use that here." << endl<<endl;
			}
			else if (command == "white zinfindel")
			{
				int pos = list->Search("corkscrew");
				if (pos != 0)
				{
					cout << endl<<"You have used the corkscrew inside the bottle was a key." << endl<<endl;
					list->DeleteByValue("corkscrew");
					list->DeleteByValue("white zinfindel");
					turn++;
					bottle_opened = true;
				}
				else
				cout << endl<<"Uh oh! You need something that can open this wine bottle." << endl<<endl;
				list->DeleteByValue(command);
			}
			else if (command == "key")
			{
				if (playerPlace == east)
				{
					cout << endl<<"You have used the key on the door.";
					cellar_key_used = true;
					turn++;
					if (battery_used == false)
						cout << "  But you still need a power supply for the motorized door." << endl<<endl;
					list->DeleteByValue(command);
					if (cellar_key_used == true && battery_used == true)
					{
						cout << endl<<"As power is restored to the door and the key is turned, a bright light appears through the cracks." << endl<<endl;
						room4_finished = true;
						room4_items = false;
					}
				}
				else
					cout << endl<<"You cannot use that here." << endl<<endl;
			}
			else if (command == "battery")
			{
				if (playerPlace == east)
				{
					cout << endl<<"You have used the battery to power the motorized door.";
					battery_used = true;
					turn++;
					if (cellar_key_used == false)
						cout << "  But you still need a key for the lock." << endl<<endl;
					list->DeleteByValue(command);
					if (cellar_key_used == true && battery_used == true)
					{
						cout << endl<<"As power is restored to the door and the key is turned, a bright light appears through the cracks." << endl<<endl;
						room4_finished = true;
						room4_items = false;
					}
				}
				else
					cout <<endl<< "You cannot use that here." << endl<<endl;
			}
		}
		}
	}
}

void Actions::Inventory()
{
	cout << "Your inventory is: " << endl;
	list->Print();
}

void Actions::Commands()
{
	cout << "These are the possible commands:" << endl;
	cout << "move, pickup/pick up, use, inventory/items, commands, look, quit/exit" << endl << endl;
}

void Actions::Look()
{
	if (playerPlace == north)
		cout << north_des << endl<<endl;
	else if (playerPlace ==south)
		cout << south_des<<endl<<endl;
	else if (playerPlace == east)
		cout << east_des<<endl<<endl;
	else if (playerPlace ==west)
		cout << west_des<<endl<<endl;
	else if (playerPlace == center)
		cout << center_des<<endl<<endl;
}

