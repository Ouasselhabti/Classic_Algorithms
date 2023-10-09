#include "graph_algorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to create a new graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    if (src >= 0 && src < graph->V && dest >= 0 && dest < graph->V) {
        graph->edge[graph->E].src = src;
        graph->edge[graph->E].dest = dest;
        graph->edge[graph->E].weight = weight;
        graph->E++;
    } else {
        printf("Error: Invalid source or destination vertex.\n");
    }
}

// Utility function to find the vertex with the minimum distance
int minDistance(int dist[], bool sptSet[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to perform Dijkstra's Algorithm for finding the shortest path
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[V];
    bool sptSet[V];

    // Initialize distances and sptSet
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph->edge[u].weight && dist[u] != INF &&
                dist[u] + graph->edge[u].weight < dist[v]) {
                dist[v] = dist[u] + graph->edge[u].weight;
            }
        }
    }

    printf("Dijkstra's Algorithm:\n");
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Utility function to find the parent of a subset
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Utility function to perform union of two subsets
void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Comparison function for sorting edges by weight
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to perform Kruskal's Algorithm for finding the Minimum Spanning Tree (MST)
void kruskal(struct Graph* graph) {
    int V = graph->V;
    int E = graph->E;
    struct Edge result[V]; // MST will have V-1 edges

    qsort(graph->edge, E, sizeof(graph->edge[0]), compare);

    int* parent = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    int i = 0; // Index used to pick the next edge

    printf("Kruskal's Algorithm (Minimum Spanning Tree):\n");
    while (i < V - 1 && result[i].src != -1) {
        struct Edge next_edge = graph->edge[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[i - 1] = next_edge;
            unionSets(parent, x, y);
        }
    }

    for (int j = 0; j < i - 1; j++) {
        printf("Edge: %d - %d, Weight: %d\n", result[j].src, result[j].dest, result[j].weight);
    }

    free(parent);
}

// Function to perform Floyd-Warshall Algorithm for finding all shortest paths
void floydWarshall(int graph[][10], int V) {
    int dist[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Floyd-Warshall Algorithm (All Shortest Paths):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}


void topologicalSortUtil(struct Graph* graph, int v, bool visited[], int stack[]) {
    visited[v] = true;

    // Recur for all adjacent vertices
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack);
        }
    }

    // Push current vertex to stack
    stack[graph->V] = v;
}

// Function to perform Topological Sort on a graph
void topologicalSort(struct Graph* graph) {
    int V = graph->V;
    bool* visited = (bool*)malloc(V * sizeof(bool));
    int* stack = (int*)malloc(V * sizeof(int));
    int stackIndex = 0;

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Call the recursive helper function to store Topological Sort starting from all vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack);
        }
    }

    printf("Topological Sort:\n");
    for (int i = V - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    free(visited);
    free(stack);
}

