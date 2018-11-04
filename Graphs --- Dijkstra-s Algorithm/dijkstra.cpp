#include "dijkstra.h"

using namespace std;

// Main program function.
int main(int argc, char const *argv[]){
	//  Let us create the example
    // graph discussed above
    int graph[Vertices][Vertices] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       				 {4, 0, 8, 0, 0, 0, 0, 11, 0},
                        			 {0, 8, 0, 7, 0, 4, 0, 0, 2},
                        			 {0, 0, 7, 0, 9, 14, 0, 0, 0},
                        			 {0, 0, 0, 9, 0, 10, 0, 0, 0},
                        			 {0, 0, 4, 0, 10, 0, 2, 0, 0},
                        			 {0, 0, 0, 14, 0, 2, 0, 1, 6},
                        			 {8, 11, 0, 0, 0, 0, 1, 0, 7},
                        			 {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstra(graph, 0);
	return 0;
}

// Minimum distance from vertix.
int minDistance(int distance[], bool shortestPathSet[]){
	int minimum = INT_MAX; // We replace min whenever we find something smaller.
	int minimumIndex;
	for(int vertix = 0; vertix < Vertices; vertix++){
		if((!shortestPathSet[vertix]) && (distance[vertix] < minimum)){
			minimum = distance[vertix];
			minimumIndex = vertix;
		}
	}
	return minimumIndex;
}

// Print shortest path.
void printPath(int parentNode[], int target){
	// Check if target is also source node.
	if(parentNode[target] == -1){
		return;
	}
	// Recursively print.
	printPath(parentNode, parentNode[target]);
	cout << target << " ";
}

// Print the entire solution.
void printSolution(int distance[], int parentNode[]){
	int sourceNode = 0;
	cout << "Vertix\tDistance\tPath";
	for(int i = 1; i < Vertices; i++){
		cout << endl << sourceNode << " -> " << i << "\t" << distance[i] << "\t\t" << sourceNode;
		printPath(parentNode, i);
	}
}

// Find the shortest path with a given matrice.
void dijkstra(int graph[Vertices][Vertices], int startNode){
	// Holds shortest distance from source to vertice.
	int distance[Vertices];
	// Check to make sure path is shortest possible.
	bool shortestPathSet[Vertices];
	// Store path tree.
	int parentNode[Vertices];
	parentNode[0] = -1;
	// Set up all distances. False for shortestPathSet.
	for(int i = 0; i < Vertices; i++){
		distance[i] = INT_MAX; 
		shortestPathSet[i] = false;
	}
	distance[startNode] = 0;
	for(int i = 0; i < (Vertices - 1); i++){
		// Pick min distance vertix.
		int minDistanceVertix = minDistance(distance, shortestPathSet);
		// Mark as processed.
		shortestPathSet[minDistanceVertix] = true;
		// Update distance values.
		for(int vertix = 0; vertix < Vertices; vertix++){
			// Update if not in shortestPathSet.
			if(!shortestPathSet[vertix] && graph[minDistanceVertix][vertix] && ((distance[minDistanceVertix] + graph[minDistanceVertix][vertix] < distance[vertix]))){
				parentNode[vertix] = minDistanceVertix;
				distance[vertix] = distance[minDistanceVertix] + graph[minDistanceVertix][vertix];
			}
		}
	}
	printSolution(distance, parentNode);
}
