#include <stdio.h>

#define SIZE 50

int vertices, i, j;
int graph[SIZE][SIZE];
int mst[SIZE][SIZE];
int max=0;

int prims(int startnode){
    printf("hi");
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
    for (j = 0; j < vertices; j++) {
        if (i < j) { // Only ask for the upper triangle of the matrix
            printf("\nDoes an edge exist between vertex %d and vertex %d? (if Yes, enter its weight; 0 for No): ", i, j);
            scanf("%d", &edge);
            if (edge != 0) {
                graph[i][j] = edge;
                graph[j][i] = edge;  // Undirected graph: set both directions
            }
        }
        else if (i == j) { // Handle self-loops
            printf("\nDoes a self-loop exist at vertex %d? (if Yes, enter its weight; 0 for No): ", i);
            scanf("%d", &edge);
            if (edge != 0) {
                graph[i][i] = edge;  // Self-loop at vertex i
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
    printf("\nEnter the starting node for making the minimum spanning tree: ");
    scanf("%d", &startnode);
    
    // Initialize MST 
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            mst[i][j] = 0; // No edges initially
        }
    }
    // Perform Prims algorithm starting from the given node
    int mst=prims(startnode);
    printf("\nMST:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}