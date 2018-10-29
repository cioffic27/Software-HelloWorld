#ifndef classes_h
#define classes_h

#include<iomanip>
#include<iostream>
#include<string>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Node {
public:
	string data;
	Node* next;
	Node() {}
	Node(string x);
};

class LinkedList
{
public:
	Node* head;
	LinkedList();
	void InsertAtFront(string x);
	int Search(string x);
	void DeleteByValue(string x);
	void DeleteAtPosition(int pos);
	void Print();
};

class Movement
{
public:
	Movement();
	Movement(string n, string s, string e, string w, string c);
	enum location { north, south, east, west, center, person };			 //possible player locations
	location playerPlace = center;
	string north_des;
	string south_des;
	string east_des;
	string west_des;
	string center_des;
	string input;
	void Move();
	void North();
	void South();
	void East();
	void West();
	void Center();
};

class Actions : public Movement {
public:
	LinkedList* list = new LinkedList();
	string command;
	Actions(string n, string s, string e, string w, string c);
	bool room1_finished = false;
	bool room2_finished = false;
	bool room3_finished = false;

	int code_guess;
	int code_correct = 6185;
	bool code_entering = false;

	bool candle1_used = false;
	bool candle2_used = false;
	bool candle3_used = false;

	//function for picking up an item---for objects changed to a generic pick command for any room instance. Inventory will move from room to room
	void Pickup();
	//use function---changed to a generic use command for any room instance
	void Use();
	void Inventory();
	void Commands();
};

#endif // !classes_h
