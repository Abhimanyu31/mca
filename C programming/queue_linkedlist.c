#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void display();

struct node{
    int data;
    struct node* next;
};

struct node  *newnode, *current, *temp, *prev, *rear=NULL, *front=NULL;

void main(){
    int choice=0;
    while (choice!=4){
        printf("\nWhich stack operation do you want to perform: \n");
        printf("1.Enqueue\t2.Dequeue\t3.Display\n");
        printf("Enter the number next to the operation: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        default:
            break;
        }
    }
}

void enqueue(){
    newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be added: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(newnode!=NULL){
        if(front==NULL&&rear==NULL){
            front=newnode;
            rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }
    }
    else{
        printf("Queue overflow!!!!!");
    }
}

void dequeue(){
    if(front==NULL&&rear==NULL){
        printf("Queue is empty!!!");
    }
    else{
        if(front==rear){
            free(front);
            front=NULL;
            rear=NULL;
        }
        else{
            temp=front;
            front=temp->next;
            free(temp);
        }
    }
}

void display(){
    if(front==NULL&&rear==NULL){
        printf("The queue is empty!!!");
    }
    else{
        temp=front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}