/*********************
Name: Isaac Kittrell
Final Project
Purpose: Graph cpp file
*********************/

#include "graph.h"

Graph::Graph()
{
	vertices = 0;
	edges = 0;
}

Graph::~Graph()
{
	for (auto& vertex : adjList)
	{
		delete vertex.second;
	}
}

bool Graph::addEdge(string v1, string v2, int weight)
{
	bool added1 = false;
	bool added2 = false;
	
	if((vertexExists(v1) && vertexExists(v2)) && v1 != v2)
	{
		added1 = adjList[v1]->changeWeight(&v2, weight);
		added2 = adjList[v2]->changeWeight(&v1, weight);
	}
	
	if (added1 && added2)
	{
		edges++;
	}
	
	return (added1 && added2);
}


bool Graph::removeEdge(string v1, string v2)
{
	bool removed1 = false;
	bool removed2 = false;
	
	removed1 = adjList[v1]->changeWeight(&v2, -1);
	removed2 = adjList[v2]->changeWeight(&v1, -1);

	if(removed1 && removed2)
	{
		edges--;
	}

    return(removed1 && removed2);
}


bool Graph::addVertex(string v)
{
	bool added = false;
	
	if (!vertexExists(v))
	{
	    adjList.emplace(v, new LinkedList);
	
	    for(int i = 0; i < vertices; i++)
	    {
		    string temp = vertexList.returnID(i);
		
		    adjList[v]->addNode(&temp, -1);
	    }

	    vertexList.addNode(&v, -1);
	
	    vertices++;

	    for (auto& vertex : adjList)
	    {
		    	vertex.second->addNode(&v, -1);
	    }

        added = true;
    }

	return added;
}

bool Graph::removeVertex(string v)
{
	bool removed = false;
	
	if(vertexExists(v))
    {
    	vertexList.deleteNode(&v);
    	
    	for(auto& vertex : adjList)
    	{
    		vertex.second->deleteNode(&v);
		}
    	
    	delete adjList[v];
    	
	    adjList.erase(v);
	    
	    vertices--;
    
        removed = true;
    }
    
    return removed;
    
}

void Graph::printAdjList()
{
	for(int i = 0; i < vertices; i++)
	{
		string vertex = vertexList.returnID(i);
		
		cout << setw(13) << right << vertex << ": ";
		adjList[vertex]->printList();
		cout << endl;
	}
	cout << endl;
}

void Graph::clearGraph()
{
	for (auto& vertex : adjList)
	{
		delete vertex.second;
	}
	
	adjList.clear();
}

void Graph::dfs_start(string vertex)
{
	for (int i = 0; i < vertices; i++)
	{
		visited.emplace(vertexList.returnID(i), false);
	}
	
	dfs(vertex);
	
	visited.clear();
}

void Graph::dfs(string vertex)
{
	if(!(visited[vertex]))
	{
	    cout << vertex << "  ";
	    visited[vertex] = true;
	
	    for(int i = 0; i < vertices; i++)
	    {
		    if(adjList[vertex]->returnWeight(i) > -1)
		    {
			    dfs(vertexList.returnID(i));
		    }
	    }
	}
	
	return;
}


void Graph::dijkstra(string root)
{
	string lowest;
	Data tempData;
	string index;
	LinkedList path;
	
	for (int i = 0; i < vertices; i++)
	{
		string vertex = vertexList.returnID(i);
			
		unexplored.emplace(vertex, new dijkstraNode);
			
		unexplored[vertex]->cost = 1000000;
	}
		
	unexplored[root]->cost = 0;
		
	while (!unexplored.empty())
	{
		for (auto& vertex : unexplored)
		{
			if(lowest.empty())
			{
				lowest = vertex.first;
			}
			else if(vertex.second->cost < unexplored[lowest]->cost)
			{
				lowest = vertex.first;
			}
		}
		
		explored.emplace(lowest, unexplored[lowest]);
		
		unexplored.erase(lowest);
		
		lowest = "";
		
		for (auto& uVertex : unexplored)
		{    
		    for (auto& eVertex : explored)
		    {
		    	index = uVertex.first;
		    	
				adjList[eVertex.first]->getNode(&index, &tempData);
				
				if (tempData.weight > -1 && eVertex.second->cost + tempData.weight < uVertex.second->cost)
				{
					uVertex.second->cost = eVertex.second->cost + tempData.weight;
					uVertex.second->parent = eVertex.first;
				}
			}
		}
	}
	
	cout << "Shortest paths from " << root << ": " << endl << endl;
	
	for(auto& vertex : explored)
	{
		index = vertex.first;
		
		
		while (index != root && !explored[index]->parent.empty())
		{
			path.addNode(&index, ((explored[index]->cost) - explored[explored[index]->parent]->cost));
			index = explored[index]->parent;
		}
		
		path.addNode(&root, -1);
		
		cout << "to " << setw(15) << left << vertex.first << " (Total cost: "; 
		
		if (vertex.second->cost == 1000000)
		{
			cout << setw(6) << right << "Inf.";
		}
		else
		{
			cout << setw(6) << right << vertex.second->cost;
		}
		
		cout << ") - ";
		
		path.printList(true);
		
		cout << endl << endl;
		
		path.clearList();
	}
	
	for (auto& vertex : explored)
	{
		delete vertex.second;
	}
	
	explored.clear();
}


int Graph::getVertices()
{
	return vertices;
}

int Graph::getEdges()
{
	return edges;
}

bool Graph::vertexExists(string v)
{
	return vertexList.exists(&v);
	
}


bool Graph::addRandomEdge(int weight)
{
	string vertex1 = vertexList.returnID(rand() % vertices);
	string vertex2 = vertexList.returnID(rand() % vertices);
	
	cout << "Adding edge from " << vertex1 << " <--> " << vertex2 << " with weight " << weight << endl;
	
	return addEdge(vertex1, vertex2, weight);
}


void Graph::randomDFS()
{
	string vertex = vertexList.returnID(rand() % vertices);
	
	cout << "DFS starting at " << vertex << ":" << endl;
	
	dfs_start(vertex);
}

void Graph::randomDijkstra()
{
	string vertex = vertexList.returnID(rand() % vertices);
	
	dijkstra(vertex);
}
