#include "graph.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Graph *graph = readGraph(argv[1]);
    if (!graph) {
        fprintf(stderr, "Failed to initialize graph.\n");
        return 1;
    }

    int choice;
    do {
        prompt();
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAdjacencyList(graph);
                break;
            case 2:
                printf("Enter the starting vertex (1-%d): ", graph->numVertices);
                int bfsStart;
                scanf("%d", &bfsStart);
                bfs(graph, bfsStart - 1);
                break;
            case 3:
                printf("Enter the starting vertex (1-%d): ", graph->numVertices);
                int dfsStart;
                scanf("%d", &dfsStart);
                dfs(graph, dfsStart - 1);
                break;
            case 4:
                printf("Enter the starting vertex (1-%d): ", graph->numVertices);
                int dijkstraStart;
                scanf("%d", &dijkstraStart);
                dijkstra(graph, dijkstraStart - 1);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    freeGraph(graph);
    return 0;
}
