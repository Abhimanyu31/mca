#include<stdio.h>
int size,arr[10],item,i,rear=-1,front=-1,op;
int enque(int arr[],int size);
int deque(int arr[],int size);
void main()
{

printf("Enter the size of array:");
scanf("%d",&size);
while(1)
{
printf("\n\nwhich operation you want to perform 1.enque \n 2. deque \n 3. display \n ");
scanf("%d",&op);
switch(op)
{
case 1:
{
enque(arr,size);
break;
}
case 2:
{
deque(arr,size);
break;
}
case 3:
{
  if (front==-1){
    printf("Queue is empty");
  }
  else{
    for(i=front;i<size;i++)
    printf("%d",arr[i]);
  }

}
}
}
}
int enque(int arr[],int size)
{
  if(rear==size-1)
 {
     printf("Array is full");
 }
else
 {
    if(front ==-1)
      front=0;
      for(i=0;i<size;i++)
     { printf("enter the item to be inserted ");
      scanf("%d",&item);
      rear=rear+1;
      arr[rear]=item;
    
     }


}
}

int deque(int arr[],int size)
{
  printf("%d\n\n",front);
  if(front==-1 || front>rear)
  {
    printf("Array is empty");
  }
  else
  {
    printf("deleted item is %d",arr[front]);
    front++;
  }
}

