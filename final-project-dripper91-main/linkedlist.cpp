/*********************
Name: Isaac Kittrell
Final Project
Purpose: Linked list cpp file
*********************/

#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
	clearList();
}


bool LinkedList::addNode(string* id, int weight)
{
	Node *current = head;
	bool added = false;
	
	if (!(id->empty()))
    {
    	// Add head (list empty)
    	if (head == NULL)
    	{
    		Node *n = makeNode(id, weight);
    		
    		n->prev = NULL;
    		n->next = NULL;
			head = n;
			
    		added = true;
		}
		//Add tail (list NOT empty)
		else
		{
			while(current->next)
			{
				current = current->next;
			}
			
			Node *n = makeNode(id, weight);
				
			current->next = n;
			n->prev = current;
			n->next = NULL;
				
			added = true;	
		}
	}

	
    return added;
}


bool LinkedList::deleteNode(string* id)
{
	Node *current = head;
	
	while (current && current->data.id != *id)
	{
		current = current->next;
	}
	
	if (current)
	{
		//delete middle
		if (current->next && current->prev)
		{
			current->prev->next = current->next;
			current->next->prev = current->prev;
		
		    delete current;
		}
		//delete tail
		else if (!(current->next) && current->prev)
		{
			current->prev->next = NULL;
			
			delete current;
		}
		//delete head (more than one node)
		else if (current->next && !(current->prev))
		{
			current->next->prev = NULL;
			head = current->next;
			
			delete current;
		}
		//delete head (only one node)
		else if (!(current->next) && !(current->prev))
		{
			delete current;
			head = NULL;
		}
	}
	
    return (current != nullptr);
}


bool LinkedList::getNode(string* id, Data* data)
{
	Node *current = head;
	
	while(current)
	{
		if (current->data.id == *id)
		{
			data->id = *id;
			data->weight = current->data.weight;
			
			break;
		}
		
		current = current->next;
	}
	
    return (current != nullptr);
}


void LinkedList::printList(bool reverse)
{
    Node *current = head;

    if (!reverse)
    {
        while(current)
        {
            cout << setw(13) << right << current->data.id << "/";
            
            if (current->data.weight > -1)
            {
            	cout << setw(4) << right << current->data.weight;
			}
			else
			{
				cout << "    ";
			}
            
            if(current->next)
            {
            	cout << "  -->";
			}
            
            current = current->next;
		}
	}
	else
	{
		bool tail = false;
		while(current && !tail)
		{
			if (current->next)
			{
				current = current->next;
			}
			else
			{
				tail = true;
			}
		}
		
		while(current)
        {
            cout << setw(13) << right << current->data.id;
            
            if (current->data.weight > -1)
            {
            	cout << "/" << setw(4) << right << current->data.weight;
			}
			else
			{
				cout << "    ";
			}
            
            if(current->prev)
            {
            	cout << "  -->";
			}
            
            current = current->prev;
		}
	}
	
}


int LinkedList::getCount()
{
    Node *current = head;
	int count = 0;
	
	while(current)
	{
	    count++;
	    current = current->next;
	}    
	
	return count;
}


bool LinkedList::clearList()
{
	
	Node *current = head;

	while(current)
	{
		head = current->next;
		delete current;
		current = head;
	}
		
    return (head == nullptr);
}


bool LinkedList::exists(string* id)
{
	Node *current = head;
	
	while(current)
	{
		if(*id == current->data.id)
		{
			break;
		}
		
		current = current->next;	
	}
	
    return (current != nullptr);
}

bool LinkedList::changeWeight(string* id, int weight)
{
	Node *current = head;
	
	while(current)
	{
		if((*id == current->data.id))
		{
			if(current->data.weight == weight)
            {
                current = nullptr;
				break;	
			}
			
			current->data.weight = weight;
			
			break;
		}
		
		current = current->next;	
	}
	
    return (current != nullptr);
}

bool LinkedList::isEmpty()
{
	return head == nullptr;
}


Node* LinkedList::makeNode(string* id, int weight)
{
	Node *n = new Node;
	n->data.id = *id;
    n->data.weight = weight;
    
    return n;
}

string LinkedList::returnID(int index)
{
	Node* current = head;
	
	int counter = 0;
	
	while(counter < index)
	{
		current = current->next;
		counter++;
	}
	
	return current->data.id;
}

int LinkedList::returnWeight(int index)
{
	Node* current = head;
	
	int counter = 0;
	
	while(counter < index)
	{
		current = current->next;
		counter++;
	}
	
	return current->data.weight;
}
