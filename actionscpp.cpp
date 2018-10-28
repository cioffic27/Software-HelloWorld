#include<iomanip>
#include<iostream>
#include<string>
using namespace std;

//when typing commands make sure they are all uppercase----i tried to make a conversion function but it didn't work and I didn't go and all the paramters for the functions so they all take in only uppercase


class Actions {
public:

	string command;
	int code_guess;
	int code_correct = 1234;
	bool code_entering = false;

	//usable items in room 2
	//north side
	bool code_paper = false;
	//south side
	bool redCup = false;
	bool blueCup = false;
	bool bowl = false;
	bool dish = false;
	bool candle1 = false;
	//east side
	bool portrait = false;
	bool candle2 = false;
	//west side
	bool candle3 = false;
	//center area-enter when done
	bool candle1_used = false;
	bool candle2_used = false;
	bool candle3_used = false;

	//for room 3 feel free to add objects that will be used

	//function for picking up an item---for objects in room 3 add them in the same format
	//needs to be integrated with the inventory function as well as movement when finished
	void Pickup()
	{
		cout << "What do you want to pick up?" << endl;
		getline(cin, command);
		transform(command.begin(), command.end(), command.begin(), toupper);

		//convert(command);
		if (command == "PAPER")
		{
			code_paper = true;
			cout << "you picked up the paper" <</*add paper description with code on it*/endl;
		}
		else if (command == "RED CUP")
		{
			redCup = true;
			cout << "you picked up the red cup" << endl;
		}
		else if (command == "BLUE CUP")
		{
			blueCup = true;
			cout << "you picked up the blue cup" << endl;
		}
		else if (command == "BOWL")
		{
			bowl = true;
			cout << "you picked up the bowl" << endl;
		}
		else if (command == "DISH")
		{
			dish = true;
			cout << "you picked up the dish" << endl;
		}
		else if (command == "CANDLE")
		{
			//add more parameters depending on location of player
			candle1 = true;
			candle2 = true;
			candle3 = true;
			cout << "you picked up the candle" << endl;
		}
		else if (command == "PORTRAIT")
		{
			portrait = true;
			cout << "you picked up the portrait, there was a safe behind it" << endl;
		}
	}

	//use function---can later be integrated with inventory possibly and objects from rooms 3
	void Use()
	{
		cout << "What do you want to use?" << endl;
		getline(cin, command);
		transform(command.begin(), command.end(), command.begin(), toupper);

		//convert(command);
		if (command == "PAPER")
		{
			if (code_paper == true)
				cout << "you used the paper" << endl;   //this is just a temporary cout- it will show the code when used
			else
				cout << "you don't have that item" << endl;
		}
		else if (command == "CANDLE1")
		{
			if (candle1 = true)  //add parameter about player being in the center
			{
				cout << "you placed the first candle in the candlestick" << endl;
				candle1_used = true;
				if (candle1_used == true && candle2_used == true && candle3_used == true)
					cout << "you escaped this room" << endl;
			}
			else
				cout << "you don't have that item" << endl;
		}
		else if (command == "CANDLE2")
		{
			if (candle2 == true) //add parameter about player being in the center
			{
				cout << "you placed the second candle in the candlestick" << endl;
				candle2_used = true;
				if (candle1_used == true && candle2_used == true && candle3_used == true)
					cout << "you escaped this room" << endl;
			}
			else
				cout << "you don't have that item" << endl;
		}
		else if (command == "CANDLE3")
		{
			if (candle3 == true) //add parameter about player being in the center
			{
				cout << "you placed the third candle in the candlestick" << endl;
				candle3_used = true;
				if (candle1_used == true && candle2_used == true && candle3_used == true)
					cout << "you escaped this room" << endl;
			}
			else
				cout << "you don't have that item" << endl;
		}
		else if (command == "SAFE")
		{
			//add parameter for location
			code_entering = true;
			while (code_entering == true)
			{
				cout << "What is the code to open the safe?" << endl;
				cin >> code_guess;
				if (code_guess == code_correct)
				{
					cout << "you successfully opened the safe." << endl;
					code_entering = false;
				}
				else
				{
					cout << "you didn't enter the correct code, would you like to try again" << endl;
					cin >> command;
					//convert(command);
					if (command == "NO")
						code_entering = false;
				}
			}
		}
		else if (command == "TOOLS")
		{
			//add parameter for location
			cout << "you used the fireplace tools to remove the ash from the fireplace, you can now see a candle laying inside the fireplace" << endl;
		}
	}
};

//toupper for strings function--needs fixing
/* string convert(string& s)
{
	for (int i = 0; i < s.length; i++)
	{
		s[i] = toupper(s[i]);
	}
	return s;
 }
 */

int main()
{
	//testing that it workds
	Actions room2;
	bool playing = true;
	string command;
	while (playing == true)
	{
		cout << "What do you want to do?" << endl;
		getline(cin, command);
		transform(command.begin(), command.end(), command.begin(), toupper);

		//convert(command);
		if (command == "PICKUP" || command == "PICK UP")
			room2.Pickup();
		else if (command == "USE")
			room2.Use();
		else
			cout << "That is not a valid command" << endl;
	}
	return 0;
}