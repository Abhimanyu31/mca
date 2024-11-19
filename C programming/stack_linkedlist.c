#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void push();
void pop();
void peek();

struct node{
    int data;
    struct node* next;
};

struct node  *newnode, *current, *temp,*head=NULL, *prev, *top=NULL;

void main(){
    top=NULL;
    int choice=0;
    while (choice!=4){
        printf("\nWhich stack operation do you want to perform: \n");
        printf("1.push\t2.pop\t3.peek\n");
        printf("Enter the number next to the operation: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        default:
            break;
        }
    }
}

void push(){
    newnode= (struct node*)malloc(sizeof(struct node));
    if (newnode!=NULL){
        printf("enter the  data ");
        scanf("%d",&newnode->data);
        newnode->next=top;
        top=newnode;
    }
    else{
        printf("`\nStack Overflow");
    }     
}

void pop(){
    int data;
    if(top==NULL){
        printf("\nStack underflow");
    }
    else{
        temp=top;
        data=temp->data;
        printf("\nPoped data is : %d",data);
        top=temp->next;
        free(temp);
    }
}

void peek(){
    int data;
    if(top==NULL){
        printf("\nStack underflow");
    }
    else{
        data=top->data;
        printf("\nPoped data is : %d",data);
    }
}