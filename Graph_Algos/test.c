#include <stdio.h>
#include "graph_algorithms.h"

int main() {
    // Create a graph with 5 vertices and 7 edges
    struct Graph* graph = createGraph(5, 7);

    // Add edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 6);

    // Test Dijkstra's Algorithm
    printf("Dijkstra's Algorithm:\n");
    dijkstra(graph, 0);
    printf("\n");

    // Test Kruskal's Algorithm
    kruskal(graph);
    printf("\n");

    // Test Floyd-Warshall Algorithm
    int graphFW[10][10] = {
        {0, 2, INF, 1, INF},
        {INF, 0, 4, 3, INF},
        {INF, INF, 0, 5, 7},
        {INF, INF, INF, 0, 6},
        {INF, INF, INF, INF, 0}
    };
    printf("Floyd-Warshall Algorithm (All Shortest Paths):\n");
    floydWarshall(graphFW, 5);
    printf("\n");

    // Create a directed graph for Topological Sort
    struct Graph* topoGraph = createGraph(6, 6);
    addEdge(topoGraph, 5, 2, 1);
    addEdge(topoGraph, 5, 0, 1);
    addEdge(topoGraph, 4, 0, 1);
    addEdge(topoGraph, 4, 1, 1);
    addEdge(topoGraph, 2, 3, 1);
    addEdge(topoGraph, 3, 1, 1);

    // Test Topological Sort
    topologicalSort(topoGraph);

    // Clean up
    free(graph->edge);
    free(graph);
    return 0;
}
