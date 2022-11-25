/*********************
Name: Isaac Kittrell
Final Project
Purpose: Graph header file
*********************/

#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"
#include <unordered_map>

class Graph {
	
public:
	
	Graph();
	~Graph();
	bool isEmpty();
	bool addEdge(string v1, string v2, int weight);
	bool removeEdge(string v1, string v2);
	bool addVertex(string v);
	bool removeVertex(string v);
	int getVertices();
	int getEdges();
	void printAdjList();
	void clearGraph();
	bool vertexExists(string id);
	void dfs_start(string v);
	void dijkstra(string root);
	
	//Driver functions for testing purposes
	bool addRandomEdge(int weight);
	void randomDFS();
	void randomDijkstra();
	
	
private:
	
	std::unordered_map<string, LinkedList*> adjList;
    std::unordered_map<string, bool> visited;
	LinkedList vertexList;
	int vertices;
	int edges;
	
	// Dijkstra Maps
	std::unordered_map<string, dijkstraNode*> explored;
	std::unordered_map<string, dijkstraNode*> unexplored;
	
	void dfs(string v);
};

#endif
