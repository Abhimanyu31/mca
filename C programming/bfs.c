#include<stdio.h>
#include<conio.h>

#define size 50

int empty=0;
int vertices,i,j;
int visited[size],queue[size];
int rear=-1,front=-1;
int graph[size][size];

void enqueue(int arr[], int k) {
    if (rear == vertices - 1) {
        printf("Queue is full!!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = k;
    }
}

int dequeue(int arr[]) {
    int item;
    if (front == -1 || front > rear) {
        empty = 1;  // Queue is empty
        return -1;
    } else {
        item = arr[front];
        front++;
        return item;
    }
}

void bfs(int startnode){
    int next;
    enqueue(queue,startnode);
    visited[startnode]=1;

    while(empty!=1){
        next=dequeue(queue);
        while(next!=-1){
            printf("%d->",next);
        }
        for(j=0;j<vertices;j++){
            if(graph[next][j]==1){
                enqueue(queue,j);
                visited[j]=1;
            }
        }
    }

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
    bfs(startnode);
}