/*********************
Name: Isaac Kittrell
Final Project
Purpose: Data header file
*********************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    string id;
    int weight = -1;
};

struct dijkstraNode {
	string parent;
	int cost;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

#endif 

