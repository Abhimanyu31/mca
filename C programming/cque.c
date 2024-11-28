
#include <stdio.h>
    int size, arr[10], item, i, rear = -1, front = -1, op;
    int enque(int arr[], int size);
    int deque(int arr[], int size);
    void main()
    {

      printf("Enter the size of array:");
      scanf("%d", &size);
      while (1)
      {
        printf("\n\nwhich operation you want to perform 1.enque \n 2. deque \n 3. peek \n ");
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
          if(front==-1){
            printf("Queue is empty!!");
          }
          else{
            printf("%d",arr[front]);
            break;
          }
        }
        }
      }
    }
    int enque(int arr[], int size)
    {

      if ((rear+1)%size==front)
      {
        printf("stack is full");
      }
      else if (front == -1 && rear == -1)
        {
          front = 0;
          rear = 0;
          printf("enter the item to be inserted ");
          scanf("%d", &item);
          arr[rear] = item;
        }
      else
      {
        rear = (rear + 1) % size ;
        printf("enter the item to be inserted ");
        scanf("%d", &item);
        arr[rear] = item;
      }
    }

      int deque(int arr[], int size)
      {
        if (front == -1)
        {
          printf("Array is empty");
        }
        else if(front==rear){
          front=-1;
          rear=-1;
        }
        else 
        {
          printf("deleted item is %d", arr[front]);
          front=(front+1)%size;
        }
      }

