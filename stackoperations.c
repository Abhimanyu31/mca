#include<stdio.h>

int choice=0,top=-1,max;
int push(int a[]);
int pop(int a[]);
int display(int a[]);
int peek(int a[]);
int count(int a[]);

void main()
{
int m,i,a[10];
printf("Enter the size of the stack:");
scanf("%d",&max);
while(choice<6)
{
    printf("\n\nwhat operation u want to perform\n");
    printf("1.push\t 2.pop\t 3.display 4.peek 5.count\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        push(a);
        break;
        case 2:
        pop(a);
        break;
        case 3:
        display(a);
        break;
        case 4:
        peek(a);
        break;
        case 5:
        count(a);
        break;
        default:
        break;
    }
}
}

int push(int a[])
{
    if(top>=max-1)
    {
        printf("\nstack is full");
    }
    else
    {
        top++;
        printf("\nenter the element:");
        scanf("%d",&a[top]);
    }
}

int pop(int a[])
{
    if (top==-1)
    {
        printf("\nstack is empty");
    }
    else
    {
        printf("\n%d is popped",a[top]);
        top--;
    }
}

int display(int a[])
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(int i=0;i<=top;i++){
            printf("%d\t",a[i]);
        }
    }

}
int peek(int a[])
{
    if (top==-1)
    {
      printf("the stack is empty");
    }
    else
    {
        printf("\n%d is the top element",a[top]);
    }

}

int count(int a[])
{
    if (top==-1)
    {
      printf("the stack is empty");
    }
    else
    {
        printf("The number of elements is: %d",top+1);
    }
}