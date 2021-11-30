// code adapted from https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/
// modified by Andrew Plowman, Stephen Linn and trae
//
#include "Dij.h"
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <string>
#define V 11
using namespace std;

Dij::Dij() {
	cout << "Nope";
}

Dij::Dij(int graph[V][V], int src) {
	dijkstra(graph, src);
}

// utility function to find the
// vertex with minimum distance
// value, from the set of vertices
// not yet included in shortest
// path tree
int Dij::minDistance(int dist[], bool sptSet[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false &&
			dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// Function to print shortest
// path from source to j
// using parent array
void Dij::printPath(int parent[], int j)
{

	// Base Case : If j is source
	if (parent[j] == -1)
		return;

	printPath(parent, parent[j]);

	cout << getCity(j) << " ";
}

// A utility function to print
// the constructed distance
// array
void Dij::printSolution(int dist[], int n,
	int parent[])
{
	int src = 0;

	
	printf("Cities\t\t\t Distance\t\tPath");
	cout << endl;
	for (int i = 1; i < V; i++)
	{
		string start = getCity(src);
		string next = getCity(i);
		cout << start << " -> " << next << "\t\t" << dist[i] << "\t\t" << start << " ";
		printPath(parent, i);
		cout << endl;
	}
}

// Utility function to get city name from vertex
string Dij::getCity(int src) {
	switch (src) {
	case 0:
		return "Mobile";
	case 1:
		return "Pensacola";
	case 2:
		return "Montgomery";
	case 3:
		return "Panama City";
	case 4:
		return "Columbus";
	case 5:
		return "Tallahasse";
	case 6:
		return "Atlanta";
	case 7:
		return "Jacksonville";
	case 8:
		return "Augusta";
	case 9:
		return "Charleston";
	case 10:
		return "Savannah";
	}
}

// Function that implements Dijkstra's
// single source shortest path
// algorithm for a graph represented
// using adjacency matrix representation
void Dij::dijkstra(int graph[V][V], int src)
{

	// The output array. dist[i]
	// will hold the shortest
	// distance from src to i
	int dist[V];

	// sptSet[i] will true if vertex
	// i is included / in shortest
	// path tree or shortest distance
	// from src to i is finalized
	bool sptSet[V];

	// Parent array to store
	// shortest path tree
	int parent[V];

	// Initialize all distances as
	// INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// Distance of source vertex
	// from itself is always 0
	dist[src] = 0;

	// Find shortest path
	// for all vertices
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum distance
		// vertex from the set of
		// vertices not yet processed.
		// u is always equal to src
		// in first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex
		// as processed
		sptSet[u] = true;

		// Update dist value of the
		// adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is
			// not in sptSet, there is
			// an edge from u to v, and
			// total weight of path from
			// src to v through u is smaller
			// than current value of
			// dist[v]
			if (!sptSet[v] && graph[u][v] &&
				dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	// print the constructed
	// distance array
	printSolution(dist, V, parent);
}