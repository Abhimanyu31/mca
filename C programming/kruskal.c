#include <stdio.h>
#include <limits.h>

#define SIZE 50

int vertices;
int graph[SIZE][SIZE];
int parent[SIZE];
int rank[SIZE];
int mst[SIZE][3]; // Stores edges in the MST (u, v, weight)

// Union-Find functions
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

int unionfind(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return 0; // Successfully merged
    }
    return 1; // Cycle detected
}


void kruskal() {
    int mstCount = 0; // Count of edges in MST
    int totalWeight = 0;

    // Initialize Union-Find
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Repeat until MST has (vertices - 1) edges
    while (mstCount < vertices - 1) {
        int minWeight = INT_MAX;
        int u = -1, v = -1;

        // Find the minimum edge dynamically
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (graph[i][j] != 0 && graph[i][j] < minWeight) {
                    if (find(i) != find(j)) { // Ensure it doesn't form a cycle
                        minWeight = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // If no valid edge is found, break (this handles disconnected graphs)
        if (u == -1 || v == -1) {
            break;
        }

        // Add the edge to the MST and perform Union
        unionfind(u, v);
        mst[mstCount][0] = u;
        mst[mstCount][1] = v;
        mst[mstCount][2] = minWeight;
        mstCount++;

        // Add weight to total
        totalWeight += minWeight;

        // Remove the edge from the graph to avoid reprocessing
        graph[u][v] = 0;
        graph[v][u] = 0;
    }

    // Print MST
    printf("\nMinimum Spanning Tree:\n");
    for (int i = 0; i < mstCount; i++) {
        printf("Edge (%d, %d) with weight %d\n", mst[i][0], mst[i][1], mst[i][2]);
    }
    printf("Total Weight of MST: %d\n", totalWeight);
}

int main() {
    printf("Enter the number of vertices: \n");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    int edge;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
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
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    kruskal();

    return 0;
}
