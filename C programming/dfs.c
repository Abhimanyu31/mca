#include <stdio.h>

#define SIZE 50

int vertices, i, j;
int graph[SIZE][SIZE];
int visited[SIZE];

// DFS function definition
void dfs(int startnode) {
    // Print the start node
    printf("%d ", startnode);
    // Mark the node as visited
    visited[startnode] = 1;
    
    // Visit all unvisited adjacent nodes
    for (i = 0; i < vertices; i++) {
        if (graph[startnode][i] == 1 && !visited[i]) {
            dfs(i); // Recurse for the unvisited neighbor
        }
    }
}

int main() {
    // Initialize the graph
    printf("Enter the number of vertices: \n");
    scanf("%d", &vertices);

    // Initialize the adjacency matrix with zeros
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0; // No edges initially
        }
    }

    // Assign edges to the graph
    int edge;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) { // Include diagonal (self-loop)
            if (i == j) {
                printf("\nDoes a self-loop exist at vertex %d? (1 for Yes, 0 for No): ", i);
                scanf("%d", &edge);
                if (edge == 1) {
                    graph[i][i] = 1; // Self-loop at vertex i
                }
            } else {
                printf("\nDoes an edge exist between vertex %d and vertex %d? (1 for Yes, 0 for No): ", i, j);
                scanf("%d", &edge);
                if (edge == 1) {
                    graph[i][j] = 1;
                    graph[j][i] = 1; // Undirected graph (symmetrical edge)
                }
            }
        }
    }

    // Printing the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // DFS traversal call
    int startnode;
    printf("\nEnter the starting node for the DFS traversal: ");
    scanf("%d", &startnode);
    
    // Initialize visited array to 0 (unvisited)
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    // Perform DFS starting from the given node
    printf("\nDFS Traversal starting from vertex %d: ", startnode);
    dfs(startnode);

    return 0;
}
