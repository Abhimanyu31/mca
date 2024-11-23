#include <stdio.h>
#include <conio.h>
    int size, arr[100], i, rear = -1, front = -1;
    int enque(int arr[], int size);
    int deque(int arr[], int size);
    int peek(int arr[]);
    void main()
    {
        int op;
      printf("Enter the size of circular queue:");
      scanf("%d", &size);
      while (1)
      {
        printf("\n\nwhich operation you want to perform 1.enque \n 2. deque \n 3. peek \n 4. display \n ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
          enque(arr, size);
          break;
        }
        case 2:
        {
          deque(arr, size);
          break;
        }
        case 3:
        {
            peek(arr);
            break;
        }
        
        case 4:
        {
          if (front == -1)
          {
            printf("Queue is empty");
          }
          else
          {
            for (i = front; i < size; i++)
              printf("%d", arr[i]);
          }
        }
        }
      }
    }

    int enque(int arr[], int size){
        int item;
        printf("Enter the element to be inserted: ");
        scanf("%d",&item);
        if((rear+1)%size==front){
            printf("The queue is full!!!");
        }
        else if(front==-1&&rear==-1){
            front=0;
            rear=0;
            arr[rear]=item;
        }
        else{
            rear=(rear+1)%size;
            arr[rear]=item;
        }
    }

    int deque(int arr[], int size){
        if(front==-1){
            printf("The queue is empty!!!");
        }
        else if(front==rear){
            printf("deleted item is %d", arr[front]);
            front=-1;
            rear=-1;
        }
        else{
            printf("deleted item is %d", arr[front]);
            front=(front+1)%size;
        }
    }

    int peek(int arr[]){
        printf("The item in front is %d",arr[front]);
    }