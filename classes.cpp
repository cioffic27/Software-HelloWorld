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
	if (pos == 1)
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
		cout << endl << "You are in the north end of the room." << endl << endl;
		playerPlace = north;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << endl << north_des << endl;
		else
			cout << endl;
	}
}

void Movement::South()
{
	if (playerPlace == south)
	{
		cout << endl;
		cout << "You are already in the south end of the room." << endl << endl;
	}
	else
	{
		turn++;
		cout << endl << "You are in the south end of the room." << endl << endl;
		playerPlace = south;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << endl << south_des << endl << endl;
		else
			cout << endl;
	}

}

void Movement::East()
{
	if (playerPlace == east)
	{
		cout << endl;
		cout << "You are already in the east end of the room." << endl << endl;
	}
	else
	{
		turn++;
		cout << endl << "You are in the east end of the room." << endl << endl;
		playerPlace = east;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << endl << east_des << endl << endl;
		else
			cout << endl;
	}

}

void Movement::West()
{
	if (playerPlace == west)
	{
		cout << endl;
		cout << "You are already in the west end of the room." << endl << endl;
	}
	else
	{
		turn++;
		cout << endl << "You are in the west end of the room." << endl << endl;
		playerPlace = west;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << endl << west_des << endl << endl;
		else
			cout << endl;
	}

}

void Movement::Center()
{
	if (playerPlace == center)
	{
		cout << endl;
		cout << "You are already in the center of the room." << endl << endl;
	}
	else
	{
		turn++;
		cout << endl << "You are in the center of the room." << endl << endl;
		playerPlace = center;
		cout << "Would you like to look around?" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);
		if (input == "YES")
			cout << endl << center_des << endl << endl;
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
		cout << endl << "You already picked up this item." << endl << endl;
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
					if (room1_key == false)
					{
						cout << endl << "You picked up the key." << endl << endl;
						list->InsertAtFront("key");
						room1_key = true;
						east_des = "There is a table in the corner with a vase of yellow flowers.";
					}
					else
						cout << "You have already picked up that key." << endl << endl;
				}
				else
					cout << endl << "That item is not here." << endl << endl;
			}
			else
				cout << endl << "You can't pick that up." << endl << endl;
		}
		else if (room2_items == true)
		{
			if (command == "PAPER")
			{
				if (playerPlace == north)
				{
					if (paper_pickup == false)
					{
						cout << endl << "You picked up the paper, on the back of it you see the numbers 6184." << endl << endl;
						list->InsertAtFront("paper");
						paper_pickup = true;
						north_des = "This is the direction you entered the room from.";
					}
					else
						cout << "You have already picked up the paper." << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "FIRE")
			{
				if (playerPlace == west)
				{
					cout << endl << "You picked up the fire." << endl;
					cout << "You are now on fire!" << endl;
					cout << "You died.  Game Over." << endl;
					restart = true;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "DISH")
			{
				if (playerPlace == south)
				{
					if (dish_pickup == false)
					{
						cout << endl << "You pick up the dish and it's just a plain white dish, but as you move it you notice a candle lying behind it." << endl << endl;
						dish_pickup = true;
						south_des = "You see a china cabinet with a see-through case.  Inside you see a red cup, a blue cup, a bowl with a flower and a candle where the dish used to lay.";
					}
					else
						cout << "You have already picked up the dish." << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "CANDLE")
			{
				if (playerPlace == west)
				{
					if (tools_used == true)
					{
						if (candle1_pickup == false)
						{
							cout << endl << "You picked up the candle." << endl << endl;
							list->InsertAtFront("candle1");
							candle1_pickup = true;
							west_des = "You see a large brick fireplace with sculptures on the mantle.";
						}
						else
							cout << "You have already picked up this candle";
					}
					else
					{
						cout << endl << "You don't see a candle here yet." << endl << endl;
						cout << "You reach in to grab what is inside the fireplace, but your sleeve catches on fire!" << endl;
						cout << "You are now on fire!" << endl;
						cout << "You died.  Game Over." << endl;
						restart = true;
					}
				}
				else if (playerPlace == east)
				{
					if (safe_cracked == true)
					{
						if (candle2_pickup == false)
						{
							cout << endl << "You picked up the candle." << endl << endl;
							list->InsertAtFront("candle2");
							candle2_pickup = true;
							east_des = "The safe is opened with nothing inside.";
						}
						else
							cout << "You have already picked up this candle.";
					}
					else
						cout << endl << "You don't see a candle here yet." << endl << endl;
				}
				else if (playerPlace == south)
				{
					if (dish_pickup == true)
					{
						if (candle3_pickup == false)
						{
							cout << endl << "You picked up the candle." << endl << endl;
							list->InsertAtFront("candle3");
							candle3_pickup = true;
							south_des = "You see a china cabinet with a see-through case.  Inside you see a red cup, a blue cup and a bowl with a flower design.";
						}
						else
							cout << "You have already picked up this candle." << endl << endl;
					}
					else
						cout << endl << "You don't see a candle here yet." << endl << endl;
				}
				else
					cout << endl << "this item is not here" << endl << endl;
			}
			else if (command == "PAINTING")
			{
				if (playerPlace == east)
				{
					if (painting_moved == false)
					{
						cout << endl << "You picked up the painting, there was a safe behind it." << endl << endl;
						painting_moved = true;
						east_des = "There is a safe here.  Crack the code to see what is inside.";
					}
					else
						cout << "You have already picked up the painting." << endl << endl;
				}
				else
					cout << endl << "That item is not here." << endl << endl;
			}
			else if (command == "TOOLS")
			{
				if (playerPlace == west)
				{
					if (tools_pickup == false)
					{
						cout << endl << "You picked up the tools." << endl << endl;
						list->InsertAtFront("tools");
						tools_pickup = true;
						west_des = "You see a large brick fireplace with sculptures on the mantle.  It seems as though there is something hidden under the pile of ash residue inside the fireplace, but you can't make out what it is.";
					}
					else
						cout << "You have already picked up the tools.";
				}
				else
					cout << endl << "That item is not here." << endl << endl;
			}
			else
				cout << endl << "That item cannot be picked up." << endl << endl;
		}
		else if (room3_items == true)
		{
			if (command == "YELLOW VIAL")
			{
				if (playerPlace == center)
				{
					if (yellow_vial_pickup == false)
					{
						cout << endl << "You picked up the yellow vial." << endl << endl;
						list->InsertAtFront("yellow vial");
						yellow_vial_pickup = true;
						center_des = "You find yourself in a laboratory in front of you is a table with beakers and burners in the middle.";
					}
					else
						cout << "You have already picked up the yellow vial." << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "RED VIAL")
			{
				if (playerPlace == east)
				{
					if (key_used == true)
					{
						if (red_vial_pickup == false)
						{
							cout << endl << "You picked up the red vial." << endl << endl;
							list->InsertAtFront("red vial");
							red_vial_pickup = true;
							east_des = "The incubators have been unlocked and the red vial is missing.";
						}
						else
							cout << "You have already picked up the red vial." << endl << endl;
					}
					else
						cout << endl << "You can't reach this object yet." << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "BLUE VIAL")
			{
				if (playerPlace == east)
				{
					if (key_used == true)
					{
						if (blue_vial_pickup == false)
						{
							cout << endl << "You picked up the blue vial." << endl << endl;
							list->InsertAtFront("blue vial");
							blue_vial_pickup = true;
							east_des = "The incubators have been unlocked and the blue vial is missing.";
						}
						else
							cout << "You have already picked up the blue vial." << endl << endl;
					}
					else
						cout << endl << "You can't reach this object yet." << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "ORANGE VIAL")
			{
				if (playerPlace == east)
				{
					if (key_used == true)
					{
						if (orange_vial_pickup == false)
						{
							cout << endl << "You picked up the orange vial." << endl << endl;
							list->InsertAtFront("orange vial");
							orange_vial_pickup = true;
							east_des = "The incubators have been unlocked and the orange vial is missing.";
						}
						else
							cout << "You have already picked up the orange vial." << endl << endl;
					}
					else
						cout << endl << "You can't reach this object yet." << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "BOOK")
			{
				if (playerPlace == south)
				{
					if (book_pickup == false)
					{
						cout << endl << "You picked up the Neuroscience book; inside it you see an incubator key." << endl << endl;
						book_pickup = true;
						south_des = "You see a table with multiple books laying on it.  The neuroscience book is opened with a candle inside.";
					}
					else
						cout << "You have already picked up the Neuroscience book." << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "INCUBATOR KEY")
			{
				if (playerPlace == south)
				{
					if (book_pickup == true)
					{
						if (key2_pickup == false)
						{
							cout << endl << "You picked up the Incubator Key." << endl << endl;
							list->InsertAtFront("incubator key");
							key2_pickup = true;
							south_des = "You see a table with multiple books laying on it.  The Neuroscience book is open but nothing is inside it.";
						}
						else
							cout << "You have already picked up the incubator key." << endl << endl;
					}
					else
						cout << endl << "You don't see a key here" << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else
				cout << endl << "That item cannot be picked up." << endl << endl;
		}
		else if (room4_items == true)
		{
			if (command == "SHOVEL")
			{
				if (playerPlace == west)
				{
					if (shovel_pickup == false)
					{
						cout << endl << "You picked up the shovel." << endl << endl;
						list->InsertAtFront("shovel");
						shovel_pickup = true;
						if (corkscrew_pickup == true)
							west_des = "You see a decorated bar with several glasses and alcohol behind, but you can't pick up any of them.";
						else if (corkscrew_pickup == false)
							west_des = "You see a decorated bar with several glasses and alcohol behind.  On the bar is a corkscrew.";
					}
					else
						cout << "You have already picked up the shovel." << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "CORKSCREW")
			{
				if (playerPlace == west)
				{
					if (corkscrew_pickup == false)
					{
						cout << endl << "You picked up the corkscrew." << endl << endl;
						list->InsertAtFront("corkscrew");
						corkscrew_pickup = true;
						if (shovel_pickup == false)
							west_des = "You see a decorated bar with several glasses and alcohol behind.  A shovel leans agains the front of the bar.";
						else if (shovel_pickup == true)
							west_des = "You see a decorated bar with several glasses and alcohol behind, but nothing can be picked up.";
					}
					else
						cout << "You have already picked up the corkscrew." << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "BATTERY")
			{
				if (playerPlace == center)
				{
					if (shovel_used == true)
					{
						if (battery_pickup == false)
						{
							cout << endl << "You picked up the battery." << endl << endl;
							list->InsertAtFront("battery");
							battery_pickup = true;
							center_des = "You see the hole you just dug, that is now empty.";
						}
						else
							cout << "You have already picked up the battery" << endl << endl;
					}
					else
						cout << endl << "You don't see a battery here." << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "WHITE ZINFINDEL")
			{
				if (playerPlace == south)
				{
					if (white_zin == false)
					{
						cout << endl << "You picked up the white zinfindel." << endl << endl;
						list->InsertAtFront("white zinfindel");
						white_zin = true;
						south_des = "You see a wine rack here:  A bottle of Merlot, Pinot Noir and Pink Moscato.";
					}
					else
						cout << "You have already picked up the white zinfindel." << endl << endl;
				}
				else
					cout << endl << "This item is not here." << endl << endl;
			}
			else if (command == "KEY")
			{
					if (bottle_opened == true)
					{
						if (cellar_key_pickup == false)
						{
							cout << endl << "You picked up the key." << endl << endl;
							list->InsertAtFront("key");
							cellar_key_pickup = true;
						}
						else
							cout << "You have already picked up the key." << endl << endl;
					}
					else
						cout << endl << "You can't get the key out yet." << endl << endl;
			}
			else
				cout << endl << "That item cannot be picked up." << endl << endl;
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
				cout << endl << "What is the code to open the safe?" << endl;
				cin >> code_guess;
				if (code_guess == code_correct)
				{
					cout << endl << "You successfully opened the safe.  Inside there is a candle." << endl << endl;
					getline(cin, command);
					transform(command.begin(), command.end(), command.begin(), toupper);
					turn++;
					safe_cracked = true;
				}
				else if (code_guess != code_correct)
				{
					cout << endl << "You didn't enter the correct code." << endl << endl;
					getline(cin, command);
					transform(command.begin(), command.end(), command.begin(), toupper);
					turn++;
				}
			}
			else
				cout << endl << "You don't see a safe here." << endl << endl;
		}
		else if (playerPlace != east)
		{
			cout << endl << "The safe is not in this area." << endl << endl;
			getline(cin, command);
			transform(command.begin(), command.end(), command.begin(), toupper);
		}
	}
	else
	{
		int pos = list->Search(command);
		if (pos == 0)
		{
			cout << endl << "You do not have that item." << endl << endl;
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
						cout << endl << "The door unlocks and you open it, heading into another room." << endl << endl;
						room1_finished = true;
						room1_items = false;
					}
					else if (playerPlace != south)
					{
						cout << endl << "This key does not seem to work with anything here." << endl << endl;
					}
				}
			}
			else if (room2_items == true)
			{
				if (command == "paper")
				{
					cout << endl << "You have used the " << command << ", on it is the code 6184." << endl << endl;
					turn++;
				}
				else if (command == "candle1")
				{
					if (playerPlace == center)
					{
						cout << endl << "You placed the first candle in the candlestick." << endl << endl;
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
							cout << "As you place the last candle you hear a clicking sound.  Suddenly the table and floor move, revealing a secret passageway which you walk down." << endl << endl;
							room2_finished = true;
							room2_items = false;
						}
					}
					else
						cout << endl << "You cannot use that here." << endl << endl;
				}
				else if (command == "candle2")
				{
					if (playerPlace == center)
					{
						cout << endl << "You placed the second candle in the candlestick." << endl << endl;
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
							cout << "As you place the last candle you hear a clicking sound.  Suddenly the table and floor move, revealing a secret passageway which you walk down." << endl << endl;
							room2_finished = true;
							room2_items = false;
						}
					}
					else
						cout << endl << "You cannot use that here." << endl << endl;
				}
				else if (command == "candle3")
				{
					if (playerPlace == center)
					{
						cout << endl << "You placed the third candle in the candlestick." << endl << endl;
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
							cout << "As you place the last candle you hear a clicking sound.  Suddenly the table and floor move, revealing a secret passageway which you walk down." << endl << endl;
							room2_finished = true;
							room2_items = false;
						}
					}
					else
						cout << endl << "You cannot use that here." << endl << endl;
				}
				else if (command == "tools")
				{
					if (playerPlace == west)
					{
						if (tools_used == false)
						{
							cout << endl << "You used the fireplace tools to remove the ash from the fireplace, you can now see a candle laying inside the fireplace." << endl;
							list->DeleteByValue(command);
							turn++;
							tools_used = true;
						}
						else
							cout << "You have already used the tools." << endl << endl;
					}
					else
						cout << endl << "You cannot use that here." << endl << endl;
				}
			}
			else if (room3_items == true)
			{
				if (command == "incubator key")
				{
					if (playerPlace == east)
					{
						if (key2_used == false)
						{
							cout << endl << "You used the incubator key to open both incubators, you can now see an orange vial, a blue vial and a red vial." << endl << endl;
							list->DeleteByValue(command);
							key_used = true;
							key2_used = true;
							turn++;
							east_des = "You used the incubator key to open both incubators, you can now see an orange vial, a blue vial and a red vial.";
						}
						else
							cout << "You have already used the incubator key." << endl << endl;
					}
					else
						cout << endl << "You cannot use that here." << endl << endl;
				}
				else if (command == "red vial")
				{
					if (playerPlace == west)
					{
						if (red_vial_used == false)
						{
							cout << endl << "One of the four bars has melted." << endl << endl;
							bar1 = 0;
							list->DeleteByValue(command);
							turn++;
							red_vial_used = true;
							if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
							{
								cout << "All four bars are melted, you were able to open the door and escape." << endl << endl;
								room3_finished = true;
								room3_items = false;
							}
						}
						else
							cout << "You have already used the red vial." << endl << endl;
					}
					else if (playerPlace != west)
					{
						cout << endl << "As soon as the liquid hits the floor it turns to gas." << endl;
						cout << "You begin to choke on the gas." << endl;
						cout << "You died! Game Over.";
						restart = true;
					}
				}
				else if (command == "orange vial")
				{
					if (playerPlace == west)
					{
						if (orange_vial_used == false)
						{
							cout << endl << "One of the four bars has melted." << endl << endl;
							bar2 = 0;
							list->DeleteByValue(command);
							turn++;
							orange_vial_used = true;
							if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
							{
								cout << "All four bars are melted, you were able to open the door and escape." << endl << endl;
								room3_finished = true;
								room3_items = false;
							}
						}
						else
							cout << "You have already used the orange vial." << endl << endl;
					}
					else if (playerPlace != west)
					{
						cout << endl << "As soon as the liquid hits the floor it turns to gas." << endl;
						cout << "You begin to choke on the gas." << endl;
						cout << "You died! Game Over.";
						restart = true;
					}
				}
				else if (command == "yellow vial")
				{
					if (playerPlace == west)
					{
						if (yellow_vial_used == false)
						{
							cout << endl << "One of the four bars has melted." << endl << endl;
							bar3 = 0;
							list->DeleteByValue(command);
							turn++;
							yellow_vial_used = true;
							if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
							{
								cout << "All four bars are melted, you were able to open the door and escape." << endl << endl;
								room3_finished = true;
								room3_items = false;
							}
						}
						else
							cout << "You have already used the yellow vial." << endl << endl;
					}
					else if (playerPlace != west)
					{
						cout << endl << "As soon as the liquid hits the floor it turns to gas." << endl;
						cout << "You begin to choke on the gas." << endl;
						cout << "You died! Game Over.";
						restart = true;
					}
				}
				else if (command == "blue vial")
				{
					if (playerPlace == west)
					{
						if (blue_vial_used == false)
						{
							cout << endl << "One of the four bars has melted." << endl << endl;
							bar4 = 0;
							list->DeleteByValue(command);
							turn++;
							blue_vial_used = true;
							if (bar1 == 0 && bar2 == 0 && bar3 == 0 && bar4 == 0)
							{
								cout << "All four bars are melted, you were able to open the door and escape." << endl << endl;
								room3_finished = true;
								room3_items = false;
							}
						}
						else
							cout << "You have already used the blue vial." << endl << endl;
					}
					else if (playerPlace != west)
					{
						cout << endl << "As soon as the liquid hits the floor it turns to gas." << endl;
						cout << "You begin to choke on the gas." << endl;
						cout << "You died! Game Over.";
						restart = true;
					}
				}
			}
			else if (room4_items == true)
			{
				if (command == "corkscrew")
				{
					if (white_zin == true)
					{
						if (corkscrew_used == false)
						{
							cout << endl << "You have used the corkscrew inside the bottle was a key." << endl << endl;
							list->DeleteByValue(command);
							list->DeleteByValue("white zinfindel");
							turn++;
							bottle_opened = true;
							corkscrew_used = true;
						}
						else if (corkscrew_used = true)
							cout << "You already used the corkscrew to open the wine bottle." << endl << endl;
					}
					else
					{
						cout << endl << "You must have a wine bottle to use the corkscrew." << endl << endl;
					}
				}
				else if (command == "shovel")
				{
					if (playerPlace == center)
					{
						if (shovel_used == false)
						{
							cout << endl << "As you shovel the dirt, you see a battery that was hidden underneath." << endl << endl;
							list->DeleteByValue(command);
							turn++;
							shovel_used = true;
						}
						else
							cout << "You have already used the shovel.  A battery has been uncovered." << endl << endl;
					}
					else
						cout << endl << "You cannot use that here." << endl << endl;
				}
				else if (command == "white zinfindel")
				{
					int pos = list->Search("corkscrew");
					if (pos != 0)
					{
						cout << endl << "You have used the corkscrew to open the bottle of white zinfindel.  You can now get the key out of the bottle." << endl << endl;
						list->DeleteByValue("corkscrew");
						list->DeleteByValue("white zinfindel");
						turn++;
						bottle_opened = true;
					}
					else
						cout << endl << "Uh oh! You need something that can open this wine bottle." << endl << endl;
					list->DeleteByValue(command);
				}
				else if (command == "key")
				{
					if (playerPlace == east)
					{
						cout << endl << "You have used the key on the door.";
						cellar_key_used = true;
						turn++;
						if (battery_used == false)
							cout << "  But you still need a power supply for the motorized door." << endl << endl;
						list->DeleteByValue(command);
						if (cellar_key_used == true && battery_used == true)
						{
							cout << endl << "As power is restored to the door and the key is turned, a bright light appears through the cracks." << endl << endl;
							room4_finished = true;
							room4_items = false;
						}
					}
					else
						cout << endl << "You cannot use that here." << endl << endl;
				}
				else if (command == "battery")
				{
					if (playerPlace == east)
					{
						cout << endl << "You have used the battery to power the motorized door.";
						battery_used = true;
						turn++;
						if (cellar_key_used == false)
							cout << "  But you still need a key for the lock." << endl << endl;
						list->DeleteByValue(command);
						if (cellar_key_used == true && battery_used == true)
						{
							cout << endl << "As power is restored to the door and the key is turned, a bright light appears through the cracks." << endl << endl;
							room4_finished = true;
							room4_items = false;
						}
					}
					else
						cout << endl << "You cannot use that here." << endl << endl;
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
	cout << "move:  select an area that you want to move to." << endl;
	cout << "pickup/pick up:  choose to pick up an item and if required, the item will be placed in your inventory." << endl;
	cout << "use:  select an item to be used." << endl;
	cout << "inventory/items:  shows a list of current items in your inventory." << endl;
	cout << "commands:  prints the list of commands." << endl;
	cout << "look:  prints the description of the current location you are in." << endl;
	cout << "Turns:  displays how many turns you have taken, and the amount of turns remaining." << endl;
	cout << "quit/exit:  quits the game." << endl << endl;
}

void Actions::Look()
{
	if (playerPlace == north)
		cout << north_des << endl << endl;
	else if (playerPlace == south)
		cout << south_des << endl << endl;
	else if (playerPlace == east)
		cout << east_des << endl << endl;
	else if (playerPlace == west)
		cout << west_des << endl << endl;
	else if (playerPlace == center)
		cout << center_des << endl << endl;
}

void Actions::Restart()
{
	restart = false;

	turn = 0;

	room1_finished = false;
	room2_finished = false;
	room3_finished = false;
	room4_finished = false;

	room1_items = true;
	room2_items = false;
	room3_items = false;
	room4_items = false;

	room1_key = false;

	candle1_used = false;
	candle2_used = false;
	candle3_used = false;
	candles_used = 0;
	tools_used = false;

	painting_moved = false;
	safe_cracked = false;
	dish_pickup = false;
	paper_pickup = false;
	candle1_pickup = false;
	candle2_pickup = false;
	candle3_pickup = false;
	tools_pickup = false;

	bar1 = 1;
	bar2 = 1;
	bar3 = 1;
	bar4 = 1;

	yellow_vial_pickup = false;
	red_vial_pickup = false;
	blue_vial_pickup = false;
	orange_vial_pickup = false;
	book_pickup = false;
	key_pickup = false;
	key2_pickup = false;

	key_used = false;
	key2_used = false;
	yellow_vial_used = false;
	red_vial_used = false;
	blue_vial_used = false;
	orange_vial_used = false;

	cellar_key_used = false;
	battery_used = false;
	white_zin = false;
	corkscrew_used = false;

	shovel_used = false;
	bottle_opened = false;
	corkscrew_pickup = false;
	shovel_pickup = false;
	battery_pickup = false;
	cellar_key_pickup = false;

	for (int x = 0; x < 30; x++)
	{
		list->DeleteAtPosition(1);
	}
}

void Actions::SetDescriptions(string n, string s, string e, string w, string c)
{
	north_des = n;
	south_des = s;
	east_des = e;
	west_des = w;
	center_des = c;
}
