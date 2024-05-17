#include "Graph.h"
#include <iostream>

using namespace std;

void Graph::MakeEmptyGraph(int n)
{
	graph.clear();
	graph.resize(n);
}

void Graph::GetEdgesFromUser(int m) 
{
	int from, to;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to;
		if (isEdgeValid(from, to))
			addEdge(from, to);
		else
		{
			cout << "invalid input" << endl;
			exit(1);
		}
	}
}
bool Graph::isEdgeValid(int u, int v) 
{
	
	int size = graph.size();
	bool valid = true;
	bool notInRange = u > size || v > size || u < Constants::MIN_VERTICE_VAL || v < Constants::MIN_VERTICE_VAL;
	if (notInRange || isAdjacent(u, v))// if the vertice is not in the range of the graph values or edge exist
		valid = false;

	return valid;
}

bool Graph::isAdjacent(int u, int v) 
{
	list<int> adjList = getAdjList(u);
	return find(adjList.begin(), adjList.end(), v) != adjList.end();
}

list<int>& Graph::getAdjList(int u) 
{
	return graph[u];
}
void Graph::addEdge(int u, int v)
{
	list<int>& tmp = getAdjList(u);
	tmp.push_back(v);
}
void Graph::removeEdge(int u, int v)
{
	list<int>& tmp = getAdjList(u);
	if (isAdjacent(u, v))
		tmp.remove(v);
}