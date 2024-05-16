#pragma once 
#include <list>
#include <vector>

using namespace std;

class Graph
{
	vector<list<int>> graph;

public:
	Graph();
	bool isAdjacent(int u,int v); // return if the vertext (u,v) exist
	getAdjList(int u);//get list of adj(u) nighbors of u
	addEdge(int u, int v); // add (u,v) to the graph
	removeEdge(int u, int v);// remove (u,v) from the graph
	bool isEdgeValid(int u, int v);
	GetEdgesFromUser();

};

