#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

// Function to perform Binary Search on a sorted array
int binarySearch(int arr[], int size, int target);

// Function to perform Depth-First Search (DFS) on a graph
void depthFirstSearch(int graph[][10], int vertices, int startVertex);

// Function to perform Breadth-First Search (BFS) on a graph
void breadthFirstSearch(int graph[][10], int vertices, int startVertex);

#endif
