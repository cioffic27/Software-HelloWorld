#include<iomanip>
#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	string data;
	Node* next;
	Node() {}
	Node(string x)
	{
		data = x; 
		next = nullptr;
	}
};

class LinkedList 
{
public:
	Node* head;
	LinkedList()
	{ 
		head = nullptr; 
	}
	void InsertAtFront(string x) 
	{
		Node* node = new Node(x);
		node->next = head;
		head = node;
	}
	int Search(string x) 
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

	void DeleteByValue(string x) 
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
	void DeleteAtPosition(int pos) {
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
	void Print() 
	{
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " "<< endl;
			temp = temp->next;
		}
		cout << endl;
	}
};

//when typing commands make sure they are all uppercase----i tried to make a conversion function but it didn't work and I didn't go and all the paramters for the functions so they all take in only uppercase

class Actions {
public:
	LinkedList* list = new LinkedList();
	string command;

	//function for picking up an item---for objects changed to a generic pick command for any room instance. Inventory will move from room to room
	void Pickup()
	{
		cout << "What do you want to pick up?" <<endl;
		getline(cin, command);
		cout << "You have picked up the " << command << endl;
		list->InsertAtFront(command);
	}
	//use function---changed to a generic use command for any room instance
	
	void Use()
	{
		cout << "What do you want to use?" << endl;
		getline(cin, command);
		cout << "You have used the " << command << endl;
		list->DeleteByValue(command);
	}
	void Inventory()
	{
		cout << "Your inventory is: " << endl;
		list->Print();
		cout << endl;
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
	//testing that it worked. Added inventory, but still dont know how to implement different cases.
	Actions room2;
	bool playing = true;
	string command;
	while (playing == true)
	{
		cout << endl << "What do you want to do?" << endl;
		getline(cin, command);
		//convert(command);
		cout << endl;
		if (command == "PICKUP" || command == "PICK UP")
			room2.Pickup();
		else if (command == "USE")
			room2.Use();
		else if (command == "INVENTORY")
			room2.Inventory();
		else
			cout << "That is not a valid command" << endl;
	}
	return 0;
}