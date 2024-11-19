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

struct node  *newnode, *current, *temp,*head=NULL, *prev;
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
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
            temp->next=head;
        }
    }

    temp=head;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    } while (temp!=head);


    while(choice!=3){
        printf("What operation do you want to perform?\n1. insertion\t2. deletion");
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
        }
    }

    getch();
}

void insertion(){
    int i,p,n;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the  data ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("where to enter the data 1.beginning \n 2.between \n 3.end");
    scanf("%d",&p);
    switch(p){
        case 1:
        {
            newnode->next=head;
            head=newnode;
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
                while(temp->next!=head)
                    {
                        temp=temp->next;

                    }
                    temp->next=newnode;
                    newnode->next=head;
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
            break;
        }
        case 2:
        {
            printf("enter the position");
            scanf("%d",&n);
            temp=head;
            for(i=0;i<n-1;i++)
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
                while(temp->next!=head)
                    { 
                        prev=temp;
                        temp=temp->next;
                    }
                    prev->next=head;
                break;
            }

        default:
            printf("invalid");
    }
    getch();
}

void print(){
    temp=head;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    } while (temp!=head);
    
}