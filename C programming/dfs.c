#include<stdio.h>
#include<conio.h>
#define size 50

int vertices,i,j;
int graph[size][size];
int visited[size];

int dfs(startnode){
    //initializing visited array
    for(i=0;i<vertices;i++){
        visited[i]=0;
    }
    visited[startnode]=1;
    printf("%d",startnode);
    //recur the function
    if()
}

void main(){
    //Initialize the graph
    printf("Enter the number of vertices: \n");
    scanf("%d",&vertices);
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            graph[i][j]=0;
            graph[j][i]=0;
        }
    }
    //assigning edges to the graph
    int edge;
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            printf("\nDoes edge exist between the vertices: %d and %d",i,j);
            printf("\n If it does, enter '1'");
            scanf("%d",&edge);
            if(edge){
                if(edge==1){
                    graph[i][j]=1;
                    graph[j][i]=1;
                }
                else{
                    printf("Enter a valid input!!");
                }
            }
        }
    }
    //Printing the adjacent matrix
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            printf("%d  ",graph[i][j]);
        }
        printf("\n");
    }
    //BFS traversal call
    int startnode;
    printf("\nEnter the starting node for the traversal: ");
    scanf("%d",&startnode);
    dfs(startnode);
}