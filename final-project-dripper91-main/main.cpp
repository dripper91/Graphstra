/*********************
Name: Isaac Kittrell
Final Project
Purpose: Main cpp file
*********************/

#include "main.h"

int main()
{
	srand(time(NULL));
	
	string cities[SET_SIZE] = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix", "Philadelphia", 
							"San Antonio", "San Diego", "Dallas", "San Jose", "Austin", "Jacksonville",
							"Fort Worth", "Columbus", "Charlotte", "San Francisco", "Indianapolis",
							"Seattle", "Denver", "Washington DC", "Boston", "El Paso", "Nashville",
							"Detroit", "Oklahoma City", "Portland", "Las Vegas", "Memphis", "Louisville",
							"Baltimore", "Milwaukee", "Albuquerque", "Tucson", "Fresno", "Mesa", "Sacramento",
							"Atlanta", "Kansas City", "CO Springs", "Omaha", "Raleigh", "Miami", "Long Beach",
							"VA Beach", "Oakland", "Minneapolis", "Tulsa", "Tampa", "Arlington", "New Orleans"};
	
	Graph graph;
	int index, index2, weight;
	
	for(int i = 0; i < 8; i++)
	{
		index = (rand() % 50);
		
		cout << "Adding " << cities[index] << "..." << endl;
		
		if (graph.addVertex(cities[index]))
		{
			cout << "Added " << cities[index] << "." << endl << endl;
		}
		else
		{
			cout << "Failed to add " << cities[index] << "." << endl << endl;
		}
	}
	
	graph.printAdjList();
	
	for(int i = 0; i < 4; i++)
	{
		while(!graph.vertexExists(cities[index]))
		{
			index = (rand() % 50);
		}
		
		cout << "Removing " << cities[index] << "..." << endl;
		
		if (graph.removeVertex(cities[index]))
		{
			cout << "Removed " << cities[index] << "." << endl << endl;
		}
		else
		{
			cout << "Failed to remove " << cities[index] << "." << endl << endl;
		}
	}
	
	graph.printAdjList();
	
	for(int i = 0; i < 4; i++)
	{
		index = (rand() % 50);
		
		cout << "Adding " << cities[index] << "..." << endl;
		
		if (graph.addVertex(cities[index]))
		{
			cout << "Added " << cities[index] << "." << endl << endl;
		}
		else
		{
			cout << "Failed to add " << cities[index] << "." << endl << endl;
		}
	}
	
	graph.printAdjList();
	
	for(int i = 0; i < 8; i++)
	{
		weight = (rand() % 3500) + 1;
		
		if (graph.addRandomEdge(weight))
		{
			cout << "Edge added." << endl << endl;
		}
		else
		{
			cout << "Failed to add edge." << endl << endl;
		}
	}
	
	graph.printAdjList();
	
	cout << endl;
	
	graph.randomDFS();
	
	cout << endl << endl;
	
	graph.randomDFS();
	
	cout << endl << endl << endl;
	
	graph.randomDijkstra();
	
	return 0;
}
