#pragma once 
#include <list>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

enum class Color
{
	WHITE,
	GRAY,
	BLACK
};

class Graph
{
	vector<list<int>> graph;
	void visit(int u, vector<Color>& color, stack<int>& res);

public:
	void MakeEmptyGraph(int n);
	bool isAdjacent(int u,int v) const; // return if the vertext (u,v) exist
	const list<int>& getAdjList(int u) const ;//get list of adj(u) nighbors of u
	void addEdge(int u, int v); // add (u,v) to the graph
	void removeEdge(int u, int v);// remove (u,v) from the graph
	int size()const;
	vector<int> DFS_endList(); // the start list is the order of the vertices

	bool isEdgeValid(int u, int v);
	void GetEdgesFromUser(int m);//  m = number of edges that will be entered
	Graph makeTranspose() const;
	
};

class Constants {
public:
	static constexpr int MIN_VERTICE_VAL = 1;
};

class SuperGraph
{
	void visitForSG(vector<int>& root, int u, int& currentRoot, vector<Color>& color, Graph& G);//SG stands for SuperGraph
	unordered_map<int, list<int>> graph;
	int vertices_num = 0;
	int edges_num = 0;
public:
	SuperGraph(Graph G);
	void increaseEdges();
	void increaseVertices();
	int size();
	void print();
};

