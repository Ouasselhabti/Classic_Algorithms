#include "search_algorithms.h"
#include <stdio.h>

// Function to perform Binary Search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at the middle
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // Target not found in the array
    return -1;
}

// Function to perform Depth-First Search (DFS) on a graph
static void dfsHelper(int graph[][10], int vertices, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfsHelper(graph, vertices, i, visited);
        }
    }
}

void depthFirstSearch(int graph[][10], int vertices, int startVertex) {
    int visited[10] = {0}; // Initialize visited array with all zeros
    printf("Depth-First Search (DFS) starting from vertex %d: ", startVertex);
    dfsHelper(graph, vertices, startVertex, visited);
    printf("\n");
}

// Function to perform Breadth-First Search (BFS) on a graph
void breadthFirstSearch(int graph[][10], int vertices, int startVertex) {
    int visited[10] = {0}; // Initialize visited array with all zeros
    int queue[10];
    int front = 0, rear = 0;

    printf("Breadth-First Search (BFS) starting from vertex %d: ", startVertex);
    printf("%d ", startVertex);
    visited[startVertex] = 1;

    // Enqueue the starting vertex
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                // Enqueue the adjacent vertex
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
