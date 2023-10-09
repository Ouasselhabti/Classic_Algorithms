#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H
#define INF 99999999 // A very large value to represent infinity

// Structure to represent an edge in a graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Function to perform Dijkstra's Algorithm for finding the shortest path
void dijkstra(struct Graph* graph, int src);

// Function to perform Kruskal's Algorithm for finding the Minimum Spanning Tree (MST)
void kruskal(struct Graph* graph);

// Function to perform Floyd-Warshall Algorithm for finding all shortest paths
void floydWarshall(int graph[][10], int V);

// Function to perform Topological Sort on a graph
void topologicalSort(struct Graph* graph);

#endif
