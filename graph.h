#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Node structure for adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node *next;
} Node;

// Graph structure
typedef struct {
    int numVertices;
    Node **adjList;  // Array of adjacency lists
} Graph;

// Function prototypes
void prompt(void);
Node *createNode(int vertex, int weight);
Graph *readGraph(const char *filename);
void displayAdjacencyList(Graph *graph);
void bfs(Graph *graph, int startVertex);
void dfs(Graph *graph, int startVertex);
void dijkstra(Graph *graph, int startVertex);
void freeGraph(Graph *graph);

#endif // GRAPH_H
