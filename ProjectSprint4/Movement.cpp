#include <iostream>
#include <string>

using namespace std;
class Movement {
public:
	string north_des= "";
	string south_des = "";
	string east_des = "";
	string west_des= "";
	string center_des= "";
	string input = "";

	void North( Movement test) {
		cout << "You are in the north end of the room." << endl;
		cout << north_des << endl;
		while (input != "Exit") {
			cin >> input;
			if (input == "North") {
				cout << "You are already north." << endl;

			}
			
			if (input == "South") {
				cout << "You go South" << endl;
				test.South(test);
			}
			if (input == "Center")
			{
				cout << "You go to the Center" << endl;
				test.Center(test);
			}
			if (input == "East") {
				cout << "You go East" << endl;
				test.East(test);
			}
			if (input == "West") {
				cout << "You go West" << endl;
				test.West(test);

			}
			if (input == "Search") {
				cout << north_des << endl;
			}
		}

	}
	void South(Movement test) {
		cout << "You are in the south end of the room." << endl;
		cout << south_des << endl;
		while (input != "Exit") {
			cin >> input;
			if (input == "North") {
				cout << "You go North" << endl;
				test.North(test);

			}

			if (input == "South") {
				cout << "You are already South" << endl;
			}
			if (input == "Center")
			{
				cout << "You go to the Center" << endl;
				test.Center(test);
			}
			if (input == "East") {
				cout << "You go East" << endl;
				test.East(test);
			}
			if (input == "West") {
				cout << "You go West" << endl;
				test.West(test);

			}
			if (input == "Search") {
				cout << south_des << endl;
			}
		}
	}
	void East(Movement test) {
		cout << "You are in the east end of the room." << endl;
		cout << east_des << endl;
		while (input != "Exit") {
			cin >> input;
			if (input == "North") {
				cout << "You go North" << endl;
				test.North(test);

			}
			if (input == "South") {
				cout << "You go South" << endl;
				test.South(test);
			}
			
			if (input == "Center")
			{
				cout << "You go to the Center" << endl;
				test.Center(test);
			}
			if (input == "East") {
				cout << "You are already east" << endl;

				
			}
			if (input == "West") {
				cout << "You go West" << endl;
				test.West(test);

			}
			if (input == "Search") {
				cout << east_des << endl;
			}
		}
	}
	void West(Movement test) {
		cout << "You are in the west end of the room." << endl;
		cout << west_des << endl;
		while (input != "Exit") {
			cin >> input;
			if (input == "North") {
				cout << "You go North" << endl;
				test.North(test);

			}
			if (input == "South") {
				cout << "You go South" << endl;
				test.South(test);
			}

			if (input == "Center")
			{
				cout << "You go to the Center" << endl;
				test.Center(test);
			}
			if (input == "East") {
				cout << "You go East" << endl;
				test.East(test);
			}
			if (input == "West") {
				cout << "You are already West" << endl;


			}
			if (input == "Search") {
				cout << west_des << endl;
			}
		}
	}
	void Center(Movement test) {
		cout << "You are in the center of the room." << endl;
		cout << center_des << endl;
		while (input != "Exit") {
			cin >> input;
			if (input == "North") {
				cout << "You go North" << endl;
				test.North(test);

			}
			if (input == "South") {
				cout << "You go South" << endl;
				test.South(test);
			}

			if (input == "Center")
			{
				cout << "You are already in the Center" << endl;
				
			}
			if (input == "East") {
				cout << "You go East" << endl;
				test.East(test);
			}
			if (input == "West") {
				cout << "You go West" << endl;
				test.West(test);

			}
			if (input == "Search") {
				cout << center_des << endl;
			}
		}
	}
};


int main() {
	Movement room2;
	room2.North(room2);
}

