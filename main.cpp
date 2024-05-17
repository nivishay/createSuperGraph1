
#include<stdlib.h>
#include "Graph.h"
#include <iostream>
using namespace std;
void main()
{
	int num_of_edges, num_of_vertices;
	Graph graph;
	cin >> num_of_vertices;
	cin >> num_of_edges;

	graph.MakeEmptyGraph(num_of_vertices);
	graph.GetEdgesFromUser(num_of_edges);
}