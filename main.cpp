
#include<stdlib.h>
#include "Graph.h"
#include <iostream>
using namespace std;
void main()
{
	int num_of_edges, num_of_vertices;
	Graph G;
	cin >> num_of_vertices;
	cin >> num_of_edges;

	G.MakeEmptyGraph(num_of_vertices);
	G.GetEdgesFromUser(num_of_edges);
	SuperGraph super(G);
	super.print();
}