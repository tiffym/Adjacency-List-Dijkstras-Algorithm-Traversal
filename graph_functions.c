#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Displays the menu options.
 */
void prompt(void) {
    printf("\nMenu:\n");
    printf("1. Display Adjacency List\n");
    printf("2. Perform Breadth-First Search (BFS)\n");
    printf("3. Perform Depth-First Search (DFS)\n");
    printf("4. Find Shortest Path using Dijkstra's Algorithm\n");
    printf("5. Exit\n");
}

/**
 * Creates a new node for the adjacency list.
 */
Node *createNode(int vertex) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for a new node");
        return NULL;
    }
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

/**
 * Reads a graph from a file and constructs the adjacency matrix.
 */
Graph *readGraph(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    Graph *graph = malloc(sizeof(Graph));
    graph->adjList = NULL;
    graph->numVertices = 0;

    int v1, v2, weight, maxVertex = 0;

    while (fscanf(file, "%d %d %d", &v1, &v2, &weight) != EOF) {
        maxVertex = v1 > maxVertex ? v1 : maxVertex;
        maxVertex = v2 > maxVertex ? v2 : maxVertex;
    }

    graph->numVertices = maxVertex;
    graph->adjList = malloc(graph->numVertices * sizeof(Node *));
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%d %d %d", &v1, &v2, &weight) != EOF) {
        Node *newNode = createNode(v2 - 1, weight);
        newNode->next = graph->adjList[v1 - 1];
        graph->adjList[v1 - 1] = newNode;

        newNode = createNode(v1 - 1, weight);  // For undirected graph
        newNode->next = graph->adjList[v2 - 1];
        graph->adjList[v2 - 1] = newNode;
    }

    fclose(file);
    return graph;
}

/**
 * Displays the adjacency list of the graph.
 */
void displayAdjacencyList(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i + 1);
        Node *temp = graph->adjList[i];
        while (temp) {
            printf("-> %d ", temp->vertex + 1);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

/**
 * Performs Breadth-First Search (BFS) starting from a given vertex.
 */
void bfs(Graph *graph, int startVertex) {
    if (startVertex >= graph->numVertices || startVertex < 0) {
        printf("Invalid start vertex\n");
        return;
    }

    bool searched[MAX_VERTICES] = {false};
    int *queue = malloc(graph->numVertices * sizeof(int));
    if (!queue) {
        perror("Failed to allocate memory for BFS queue");
        return;
    }

    int front = 0, rear = 0;

    searched[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS starting from vertex %d:\n", startVertex + 1);
    while (front != rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex + 1);

        Node *temp = graph->adjList[currentVertex];
        while (temp) {
            if (!searched[temp->vertex]) {
                searched[temp->vertex] = true;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(queue);
}


/**
 * Performs Depth-First Search (DFS) starting from a given vertex.
 */
void index(Graph *graph, int vertex, bool *searched) {
    searched[vertex] = true;
    printf("%d ", vertex + 1);

    Node *temp = graph->adjList[vertex];
    while (temp) {
        if (!searched[temp->vertex]) {
            index(graph, temp->vertex, searched);
        }
        temp = temp->next;
    }
}

void dfs(Graph *graph, int startVertex) {
    if (startVertex >= graph->numVertices || startVertex < 0) {
        printf("Invalid start vertex\n");
        return;
    }

    bool searched[MAX_VERTICES] = {false};

    printf("DFS starting from vertex %d:\n", startVertex + 1);
    index(graph, startVertex, searched);
    printf("\n");
}


/**
 * Finds the shortest path using Dijkstra's algorithm.
 */
void dijkstra(Graph *graph, int startVertex) {
    if (startVertex >= graph->numVertices || startVertex < 0) {
        printf("Invalid start vertex\n");
        return;
    }

    int distances[MAX_VERTICES];
    bool searched[MAX_VERTICES] = {false};

    for (int i = 0; i < graph->numVertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[startVertex] = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        int minVertex = -1;
        for (int j = 0; j < graph->numVertices; j++) {
            if (!searched[j] && (minVertex == -1 || distances[j] < distances[minVertex])) {
                minVertex = j;
            }
        }

        if (minVertex == -1) {
            break;
        }

        searched[minVertex] = true;

        Node *temp = graph->adjList[minVertex];
        while (temp) {
            if (!searched[temp->vertex] && distances[minVertex] != INT_MAX &&
                distances[minVertex] + temp->weight < distances[temp->vertex]) {
                distances[temp->vertex] = distances[minVertex] + temp->weight;
            }
            temp = temp->next;
        }
    }

    printf("Shortest paths from vertex %d:\n", startVertex + 1);
    for (int i = 0; i < graph->numVertices; i++) {
        if (distances[i] == INT_MAX) {
            printf("Vertex %d: INF\n", i + 1);
        } else {
            printf("Vertex %d: %d\n", i + 1, distances[i]);
        }
    }
}

/**
 * Frees the graph and its adjacency list.
 */
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node *temp = graph->adjList[i];
        while (temp) {
            Node *prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(graph->adjList);
    free(graph);
}

