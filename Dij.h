#pragma once
#define V 11
#include <string>
using namespace std;
class Dij
{
private:

public:
	//Default constructor
	Dij();
	// Overload constructor
	Dij(int graph[V][V], int src);
	// Setter Methods
	void printSolution(int dist[], int n, int parent[]);
	// Getter methods
	int minDistance(int dist[], bool sptSet[]);
	void printPath(int parent[], int j);
	void dijkstra(int graph[V][V], int src);
	string getCity(int src);
};

