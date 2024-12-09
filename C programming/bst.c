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
int searching(key);

struct node *root=NULL, *newnode, *temp, *parent;
int choice=0,trav,key;

void main(){
    while(choice!=5){
        printf("\nWhich of the following functions do you want to perform on the BST: ");
        printf("\n\t1.Insertion\n\t2.Searching\n\t3.Traversal\n\t4.Deletion\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insertion();
            break;
        
        case 2:
            printf("\nEnter the key to be searched: ");
            scanf("%d",&key);
            searching(key);
            break;

        case 3:
            printf("Which of the following traversals do you want to perform: ");
            printf("\n\t1.In-order\n\t2.pre-order\n\t3.postorder\n");
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

int searching(key){
    temp=root;
    while(temp!=NULL){
        if(temp->data<key){
            temp=temp->rchild;
        }
        else if(temp->data>key){
            temp=temp->lchild;
        }
        else if(temp->data==key){
            printf("The key is present in the tree.");
        }
    }
    printf("The key is not in the BST!!");
}