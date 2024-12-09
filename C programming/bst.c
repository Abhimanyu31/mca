#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild,*rchild;
};

int insertion();
int inorder(struct node *temp);
int preorder(struct node *temp);
int postorder(struct node *temp);
int searching();

struct node *root=NULL, *newnode, *temp, *parent;
int choice=0,trav;

void main(){
    while(choice!=5){
        printf("\nWhich of the following functions do you want to perform on the BST: ");
        printf("\n\t1.Insertion\n2.Searching\n3.Traversal\n4.Deletion");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insertion();
            break;
        
        case 2:
            searching();
            break;

        case 3:
            printf("Which of the following traversals do you want to perform: ");
            printf("\n\t1.In-order\n2.pre-order\n3.postorder");
            scanf("%d",&trav);
            if(trav==1){
                inorder(root);
            }
            else if(trav==2){
                preorder(root);
            }
            else if(trav==3){
                postorder(root);
            }
            else{
                printf("Enter a valid choice!");
            }
            break;
        
        case 4:
            //deletion();
            break;
        
        case 5:
            break;
        
        default:
            printf("Enter a valid input!");
            break;
        }
    }
}

int insertion(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value of the new node: ");
    scanf("%d",&newnode->data);
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    if(root==NULL){
        root=newnode;
    }
    else{
        temp=root;
        while(temp!=NULL){
            if(temp->data>newnode->data){
                parent=temp;
                temp=temp->lchild;
            }
            else if(temp->data==newnode->data){
                printf("The value already exists in the BST!");
                free(newnode);
            }
            else{
                parent=temp;
                temp=temp->rchild;
            }
        }
        if(parent->data>newnode->data){
            parent->lchild=newnode;
        }
        else{
            parent->rchild=newnode;
        }
    }
}

int inorder(struct node *temp){
    if(root==NULL){
        printf("The tree is empty!!");
    }
    if(temp==NULL){
        return 0;
    }
    else{
        inorder(temp->lchild);
        printf("%d ->",temp->data);
        inorder(temp->rchild);
    }
}

int preorder(struct node *temp){
    if(root==NULL){
        printf("The tree is empty!!");
    }
    if(temp==NULL){
        return 0;
    }
    else{
        printf("%d ->",temp->data);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }
}

int postorder(struct node *temp){
    if(root==NULL){
        printf("The tree is empty!!");
    }
    if(temp==NULL){
        return 0;
    }
    else{
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d->",temp->data);
    }
}

int searching(){
    
}