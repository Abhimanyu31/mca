#include <stdio.h>

#define SIZE 50

int vertices, i, j;
int graph[SIZE][SIZE];
int mst[SIZE][SIZE];
int key[SIZE];
int parent[SIZE];
int inMST[SIZE];

int kruskal(){
    
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

    kruskal();
    
    printMST();
    
    return 0;
}