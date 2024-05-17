#pragma once 
#include <list>
#include <vector>

using namespace std;

class Graph
{
	vector<list<int>> graph;
public:
	void MakeEmptyGraph(int n);
	bool isAdjacent(int u,int v) ; // return if the vertext (u,v) exist
	list<int>& getAdjList(int u) ;//get list of adj(u) nighbors of u
	void addEdge(int u, int v); // add (u,v) to the graph
	void removeEdge(int u, int v);// remove (u,v) from the graph

	bool isEdgeValid(int u, int v);
	void GetEdgesFromUser(int m);//  m = number of edges that will be entered
	
};

class Constants {
public:
	static constexpr int MIN_VERTICE_VAL = 1;
};