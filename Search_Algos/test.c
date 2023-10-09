#include <stdio.h>
#include "search_algorithms.h"

int main() {
    // Test Binary Search
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 11;
    int result = binarySearch(arr, size, target);
    if (result != -1) {
        printf("Binary Search: Element %d found at index %d\n", target, result);
    } else {
        printf("Binary Search: Element %d not found\n", target);
    }

    // Test Depth-First Search (DFS)
    int graphDFS[10][10] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0}
    };
    int verticesDFS = 10;
    int startVertexDFS = 0;
    printf("Depth-First Search (DFS) starting from vertex %d:\n", startVertexDFS);
    depthFirstSearch(graphDFS, verticesDFS, startVertexDFS);

    // Test Breadth-First Search (BFS)
    int graphBFS[10][10] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0}
    };
    int verticesBFS = 10;
    int startVertexBFS = 0;
    printf("Breadth-First Search (BFS) starting from vertex %d:\n", startVertexBFS);
    breadthFirstSearch(graphBFS, verticesBFS, startVertexBFS);

    return 0;
}
