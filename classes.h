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
	Node * head;
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
	int turn = 0;
};

class Actions : public Movement {
public:
	LinkedList * list = new LinkedList();
	string command;
	Actions(string n, string s, string e, string w, string c);
	bool room1_finished = false;
	bool room2_finished = false;
	bool room3_finished = false;
	bool room4_finished = false;

	//item pickup bools
	bool room1_items = true;
	bool room2_items = false;
	bool room3_items = false;
	bool room4_items = false;

	//if you picked up the key then description changes
	bool room1_key = false;

	//safe code entering variable
	int code_guess;
	int code_correct = 6184;
	bool code_entering = false;

	//room 2 escape variables
	bool candle1_used = false;
	bool candle2_used = false;
	bool candle3_used = false;
	bool tools_used = false;
	int candles_used = 0;

	//room 2 item pickup order variables
	bool painting_moved = false;
	bool safe_cracked = false;
	bool dish_pickup = false;
	bool paper_pickup = false;
	bool candle1_pickup = false;
	bool candle2_pickup = false;
	bool candle3_pickup = false;
	bool tools_pickup = false;

	//room 3 variables
	int bar1 = 1;
	int bar2 = 1;
	int bar3 = 1;
	int bar4 = 1;

	//room 3 item pickup order variables
	bool yellow_vial_pickup = false;
	bool red_vial_pickup = false;
	bool blue_vial_pickup = false;
	bool orange_vial_pickup = false;
	bool book_pickup = false;
	bool key_pickup = false;
	bool key2_pickup = false;

	//room 3 escape variables
	bool key_used = false;
	bool key2_used = false;
	bool yellow_vial_used = false;
	bool red_vial_used = false;
	bool blue_vial_used = false;
	bool orange_vial_used = false;

	//room 4 escape variables
	bool cellar_key_used = false;
	bool battery_used = false;
	bool white_zin = false;
	bool corkscrew_used = false;

	//room 4 item pickup order variables
	bool shovel_used = false;
	bool bottle_opened = false;
	bool corkscrew_pickup = false;
	bool shovel_pickup = false;
	bool battery_pickup = false;
	bool cellar_key_pickup = false;

	//restart condition-set false originally,when true will lead to game restart
	bool restart = false;

	void Pickup();
	void Use();
	void Inventory();
	void Commands();
	void Look();
	void Restart();
	void SetDescriptions(string n, string s, string e, string w, string c);
};

#endif // !classes_h
#pragma once#pragma once
