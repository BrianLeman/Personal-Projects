/*
C++ program for Dijkstra's shortest path algorithm.
Adjacency matrix representation of the graph.
*/
#include <iostream>
// Limits is needed for using INT_MAX.
#include <limits>

using namespace std;

// There are this many vertices in the graph.
#define Vertices 9

// Minimum distance from vertix.
int minDistance(int distance[], bool shortestPathSet[]);

// Print shortest path.
void printPath(int parentNode[], int target);

// Print the entire solution.
void printSolution(int distance[], int parentNode[]);

// Find the shortest path with a given matrice.
void dijkstra(int graph[Vertices][Vertices], int startNode);