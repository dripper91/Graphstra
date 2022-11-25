/*********************
Name: Isaac Kittrell
Final Project
Purpose: Linked list header file
*********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <iomanip>
#include "data.h"
using std::cout;
using std::endl;
using std::setw;
using std::right;
using std::left;

class LinkedList {
	
public:

    LinkedList();	
    ~LinkedList();
    
    bool addNode(string* id, int weight);
    bool deleteNode(string* id);
    bool getNode(string* id, Data* data);
    void printList(bool reverse = false);
    int getCount();
    bool clearList();
    bool exists(string* id);
    bool isEmpty();
    string returnID(int index);
    int returnWeight(int index);
    bool changeWeight(string* id, int weight);
	
private:

    Node* head;
    
    Node* makeNode(string* id, int weight);
};

#endif
