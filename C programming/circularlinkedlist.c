#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

void insertion();
void deletion();
void print();

struct node{
    int data;
    struct node* next;
};

struct node  *newnode, *current, *temp,*head=NULL, *prev,*tail;
int num;
void main(){
    int j,choice=0,n;
    printf("how many initial nodes do you want:");
    scanf("%d",&num);
    for(j=0;j<num;j++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&newnode->data);
        newnode->next=newnode;
        if (head==NULL){
            head=newnode; 
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }
    while(choice!=4){
        printf("What operation do you want to perform?\n1. insertion\t2. deletion\t3. display 4.exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insertion();
            print();
            break;
            case 2:
            deletion();
            print();
            break;
            case 3:
            print();
            break;
            default:
            printf("invalid choice!!");
        }
    }
}

void print(){
    temp=head;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
}


void insertion(){
    int i,p,n;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the  data ");
    scanf("%d",&newnode->data);
    newnode->next=newnode;
    printf("where to enter the data 1.beginning \n 2.between \n 3.end");
    scanf("%d",&p);
    switch(p){
        case 1:
        {
            newnode->next=head;
            head=newnode;
            tail->next=head;
            break;
        }
        case 2:
        {
            printf("insert the position");
            scanf("%d",&n);
            temp=head;
            for(i=0;i<n;i++)
                {
                    prev=temp;
                    temp=temp->next;
                    
                }
                prev->next=newnode;
                newnode->next=temp;
            break;
        }
        case 3:
            {   
                temp=head;
                do
                {
                    temp=temp->next;
                }
                while(temp->next!=head);
                tail=newnode;
                temp->next=tail;
                tail->next=head;
                break;
            }

        default:
            printf("invalid");
    }
    getch();
}

void deletion(){
    int i,p,n;
    
  
    printf("From where to delete the data 1.beginning \n 2.between \n 3.end");
    scanf("%d",&p);
    switch(p){
        case 1:
        {
            head=head->next;
            tail->next=head;
            break;
        }
        case 2:
        {
            printf("enter the position");
            scanf("%d",&n);
            if(n==0){
                printf("invalid");
                break;
            }
            temp=head;
            for(i=0;i<n;i++)
                {
                    prev=temp;
                    temp=temp->next;
                    
                }
                prev->next=temp->next;
                
            break;
        }
        case 3:
            {   
                temp=head;
                do
                    {   prev=temp;
                        temp=temp->next;
                    }
                    while(temp->next!=head);
                    tail=prev;
                    tail->next=head;
                break;
            }

        default:
            printf("invalid");
    }
    getch();
}