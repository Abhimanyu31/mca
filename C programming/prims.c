#include <stdio.h>

#define SIZE 50

int vertices, i, j;
int graph[SIZE][SIZE];
int mst[SIZE][SIZE];
int key[SIZE];
int parent[SIZE];
int inMST[SIZE];

int prims(){
    int next, minKey;
    
    for (i = 0; i < vertices; i++) {
        key[i] = 1e8;  
        inMST[i] = 0;  
        parent[i] = -1;
    }
    
    key[0] = 0;  
    parent[0] = -1;  
    
    
    for (int count = 0; count < vertices - 1; count++) {
        minKey = 1e8;
        next = -1;
        
        // Find the vertex with the minimum key value that is not yet in MST
        for (i = 0; i < vertices; i++) {
            if (inMST[i] == 0 && key[i] < minKey) {
                minKey = key[i];
                next = i;
            }
        }
        
        // Include this vertex in MST
        inMST[next] = 1;
        
        // Update the key and parent values of the adjacent vertices
        for (i = 0; i < vertices; i++) {
            if (graph[next][i] != 0 && inMST[i] == 0 && graph[next][i] < key[i]) {
                key[i] = graph[next][i];
                parent[i] = next;
            }
        }
    }
}

void printMST() {
    int totalCost = 0;
    printf("\nMinimum Spanning Tree (MST):\n");
    printf("Edge   Weight\n");
    for (i = 1; i < vertices; i++) {
        if (parent[i] != -1) {
            printf("%d -> %d    %d\n", parent[i], i, graph[i][parent[i]]);
            totalCost += graph[i][parent[i]];
        }
    }
    printf("\nTotal Cost of MST: %d\n", totalCost);
}

int main() {
    printf("Enter the number of vertices: \n");
    scanf("%d", &vertices);

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    int edge;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (i < j) { 
                printf("\nDoes an edge exist between vertex %d and vertex %d? (if Yes, enter its weight; 0 for No): ", i, j);
                scanf("%d", &edge);
                if (edge != 0) {
                    graph[i][j] = edge;
                    graph[j][i] = edge;  
                }
            }
            else if (i == j) { 
                printf("\nDoes a self-loop exist at vertex %d? (if Yes, enter its weight; 0 for No): ", i);
                scanf("%d", &edge);
                if (edge != 0) {
                    graph[i][i] = edge;  
                }
            }
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    prims();
    
    printMST();
    
    return 0;
}
