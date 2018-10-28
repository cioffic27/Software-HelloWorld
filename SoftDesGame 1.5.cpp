#include "pch.h"

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

class Movement 
{
public:
	string north_des;
	string south_des;
	string east_des;
	string west_des;
	string center_des;
	string input;

	Movement()
	{
		north_des = "";
		south_des = "";
		east_des = "";
		west_des = "";
		center_des = "";
	}

	Movement(string n, string s, string e, string w, string c)
	{
		north_des = n;
		south_des = s;
		east_des = e;
		west_des = w;
		center_des = c;
	}

	void North(Movement test)
	{
		cout << "You are in the north end of the room." << endl;
		cout << north_des << endl;

		while (input != "EXIT")
		{
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), toupper);

			if (input == "NORTH")
			{
				cout << "You are already north.\n" << endl;
			}

			if (input == "SOUTH")
			{
				cout << "You go South\n" << endl;
				test.South(test);
			}

			if (input == "CENTER")
			{
				cout << "You go to the Center\n" << endl;
				test.Center(test);
			}

			if (input == "EAST")
			{
				cout << "You go East\n" << endl;
				test.East(test);
			}

			if (input == "WEST")
			{
				cout << "You go West\n" << endl;
				test.West(test);
			}

			if (input == "SEARCH" || input == "LOOK")
			{
				cout << north_des << endl;
			}
		}

		cout << "You are done.\n";
	}

	void South(Movement test)
	{
		cout << "You are in the south end of the room." << endl;
		cout << south_des << endl;

		while (input != "EXIT")
		{
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), toupper);

			if (input == "NORTH")
			{
				cout << "You go North\n" << endl;
				test.North(test);
			}

			if (input == "SOUTH")
			{
				cout << "You are already South\n" << endl;
			}

			if (input == "CENTER")
			{
				cout << "You go to the Center\n" << endl;
				test.Center(test);
			}

			if (input == "EAST")
			{
				cout << "You go East\n" << endl;
				test.East(test);
			}

			if (input == "WEST")
			{
				cout << "You go West\n" << endl;
				test.West(test);
			}

			if (input == "SEARCH" || input == "LOOK")
			{
				cout << south_des << endl;
			}
		}

		cout << "You are done.\n";
	}

	void East(Movement test)
	{
		cout << "You are in the east end of the room." << endl;
		cout << east_des << endl;

		while (input != "EXIT")
		{
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), toupper);

			if (input == "NORTH")
			{
				cout << "You go North\n" << endl;
				test.North(test);
			}

			if (input == "SOUTH")
			{
				cout << "You go South\n" << endl;
				test.South(test);
			}

			if (input == "CENTER")
			{
				cout << "You go to the Center\n" << endl;
				test.Center(test);
			}

			if (input == "EAST")
			{
				cout << "You are already east\n" << endl;
			}

			if (input == "WEST")
			{
				cout << "You go West\n" << endl;
				test.West(test);
			}

			if (input == "SEARCH" || input == "LOOK")
			{
				cout << east_des << endl;
			}
		}

		cout << "You are done.\n";
	}

	void West(Movement test)
	{
		cout << "You are in the west end of the room." << endl;
		cout << west_des << endl;

		while (input != "EXIT")
		{
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), toupper);

			if (input == "NORTH")
			{
				cout << "You go North\n" << endl;
				test.North(test);
			}

			if (input == "SOUTH")
			{
				cout << "You go South\n" << endl;
				test.South(test);
			}

			if (input == "CENTER")
			{
				cout << "You go to the Center\n" << endl;
				test.Center(test);
			}

			if (input == "EAST")
			{
				cout << "You go East\n" << endl;
				test.East(test);
			}

			if (input == "WEST")
			{
				cout << "You are already West\n" << endl;
			}

			if (input == "SEARCH" || input == "LOOK")
			{
				cout << west_des << endl;
			}
		}

		cout << "You are done.\n";
	}

	void Center(Movement test)
	{
		cout << "You are in the center of the room." << endl;
		cout << center_des << endl;

		while (input != "EXIT")
		{
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), toupper);

			if (input == "NORTH")
			{
				cout << "You go North\n" << endl;
				test.North(test);
			}

			if (input == "SOUTH")
			{
				cout << "You go South\n" << endl;
				test.South(test);
			}

			if (input == "CENTER")
			{
				cout << "You are already in the Center\n" << endl;
			}

			if (input == "EAST")
			{
				cout << "You go East\n" << endl;
				test.East(test);
			}

			if (input == "WEST")
			{
				cout << "You go West\n" << endl;
				test.West(test);
			}

			if (input == "SEARCH" || input == "LOOK")
			{
				cout << center_des << endl;
			}
		}

		cout << "You are done.\n";
	}
};


int main() 
{
	Movement room2
	("This is North\n",
	 "This is South\n",
	 "This is East\n",
	 "This is West\n",
	 "This is Center\n"
	);

	Movement room3
	("The table is furnished with standard lab equipment, including a microscope.\n"								//Microscope
		"There is a Red Vial next to the microscope.\n"																//Red Vial
		"A piece of paper sits of the table. There appears to be a lot written on it.\n"							//Lab Notes
		"There is a bottle of water in the cabinet above the table.\n"
		"There is a screwdriver in a left-open drawer of the table.\n",

	 "There are multiple books stacked on the table.\n"
		"The lables on the side read 'Physics', 'Thermodynamics' and 'Neuroscience.'\n",							//Neuroscience Book

	 "A set of incubators are hooked up to a computer, ready to run calculations.\n"
		"The incubators are locked and have Orange, Blue and Purple Vials.\n",										//Locked Incubators or Put Vials in Incubators

	 "The door out of the room is barricaded with an iron bar.\n\n"													//Iron Bar or Door
		"A sign on the wall next to the door reads 'EMERGENCY LOCK IN PROCEDURE'\n"								
		"Scribbled at the bottom of the sign is a message saying 'The answer is in the Brain.'\n",

	 "At the center of the laboratory you see a table with beakers and burners.\n\n"
		"There is a Yellow Vial in the center.\n"																	//Yellow Vial
	);

	cout << "This is the start of the game\n\n";
	
	room2.North(room2);

	cout << "Entering the next room...\n\n";

	room3.Center(room3);

	cout << "You have completed the game.\n\n";

	return 0;
}