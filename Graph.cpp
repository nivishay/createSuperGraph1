#include "Graph.h"
#include <iostream>
#include <stack>
using namespace std;

void Graph::MakeEmptyGraph(int n)
{
	graph.clear();
	graph.resize(n + 1);// + 1 for making the list the right index;
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
int Graph::size()const
{
	return graph.size();
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

bool Graph::isAdjacent(int u, int v)const
{
	list<int> adjList = getAdjList(u);
	return find(adjList.begin(), adjList.end(), v) != adjList.end();
}

const list<int>& Graph::getAdjList(int u)const 
{
	return graph[u];
}
void Graph::addEdge(int u, int v)
{
	graph[u].push_back(v);
}
void Graph::removeEdge(int u, int v)
{
	if (isAdjacent(u, v))
		graph[u].remove(v);
}

vector<int> Graph::DFS_endList()
{
	int size = graph.size();
	vector<Color> color(size, Color::WHITE);// initalitze all with white
	stack<int> stack;
	vector<int> res;
	for (int i = 0; i < size; i++)
	{
		if (color[i] == Color::WHITE)
			visit(i, color, stack);
	}
	while (!stack.empty())
	{
		res.push_back(stack.top());
		stack.pop();
	}

	return res;
}

void SuperGraph::print()
{
	cout << graph.size() << ' ' << edges_num << endl;
}
SuperGraph::SuperGraph(Graph G)
{
	// Obtain DFS ending list and transpose graph
	vector<int> finishOrder = G.DFS_endList();
	Graph transpose = G.makeTranspose();

	// Initialize variables
	int size = G.size();
	int currentRoot;
	vector<int> root(size);
	vector<Color> color(size, Color::WHITE);

	for (auto u: finishOrder)
	{
		if (color[u] == Color::WHITE)
		{
			if (u != 0) // the 0 vertice has no meaning
				graph[u] = list<int>();
			increaseVertices();
			currentRoot = u;
			visitForSG(root, u, currentRoot, color, transpose);
		}
	}
}

void SuperGraph::increaseEdges()
{
	edges_num++;
}
int SuperGraph::size()
{
	return graph.size();
}
void SuperGraph::increaseVertices()
{
	vertices_num++;
}

void SuperGraph::visitForSG(vector<int>& root, int u, int& currentRoot, vector<Color>& color, Graph& G)
{
	root[u] = currentRoot;
	color[u] = Color::GRAY;
	for (int v : G.getAdjList(u))
	{
		if (color[v] == Color::WHITE)
			visitForSG(root, v, currentRoot, color, G); // Recursively visit the adjacent vertex

		if (color[v] == Color::BLACK && root[v] != root[u])
		{
			// Check if the list is empty or if the last element is not the current root
			if (graph[root[v]].empty() || graph[root[v]].back() != root[u])
			{
				graph[root[v]].push_back(u);
				increaseEdges();
			}
		}
	}
	color[u] = Color::BLACK;
}

void Graph::visit(int u,vector<Color>& color, stack<int>& res)
{
	color[u] = Color::GRAY;// Mark current vertex as being visited
	for (int v : getAdjList(u)) 
		if (color[v] == Color::WHITE)
			visit(v, color,res); // Recursively visit the adjacent vertex
		
	color[u] = Color::BLACK;
	res.push(u);
	
}

Graph Graph::makeTranspose()const
{
	Graph transpose;
	int size = graph.size();
	transpose.MakeEmptyGraph(size);
	for (int i = 0; i < size; i++)
	{
		for (auto v : getAdjList(i)) 
			transpose.addEdge(v, i);// add the oppsite edge
	}
	return transpose;
}

