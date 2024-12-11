#include<stdio.h>
#include<conio.h>


int max;
void display(int arr[]);
void search(int arr[]);
void insert(int arr[]);
void delete(int arr[]);
void sort(int arr[]);

int main(){
    int option=0;

    printf("Enter the size of the array:");
    scanf("%d",&max);
    
    int arr[100];

    for(int i=0;i<max;i++)
    {
        printf("Enter the element :");
        scanf("%d",&arr[i]);
    }
    

    while(option<6)
    {   
        printf("\nWhich function do you want to perform:");
        printf("\n1. Display\t 2.Search\t 3.insert\t 4.delete\t 5.sort\t 6.exit");
        printf("\nEnter your choice: ");
        scanf("%d",&option);     

        switch (option)
        {
        case 1:    
            display(arr);
            break;

        case 2:
            search(arr);
            break;
        case 3:
            insert(arr);
            break;
        case 4:
            delete(arr);
            break;
        case 5:
            sort(arr);
        default:
            break;
        }
    }

    return 0;
    
}


void display(int arr[])
{
    for(int i=0;i<max;i++) 
    {
        printf("%d\t",arr[i]);
    }
   
}


void search(int arr[])
{
    int key;
    printf("\nEnter the element to be searched:");
    scanf("%d",&key);
    for(int i=0;i<=max;i++)
    {
        if(arr[i]==key){
            printf("\nElement found at index %d",i);
            break;
        }
        if(i==max){
            printf("\nElement is not found");
        }
    }

}


void insert(int arr[])
{
    int new,position;
    printf("Enter the element to be inserted:");
    scanf("%d",&new);
    printf("enter the position of the element");
    scanf("%d",&position);
    for(int i=max;i>position;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[position]=new;
    max++;
    display(arr);
}


void delete(int arr[])
{
    int position;
    printf("enter the position to be deleted");
    scanf("%d",&position);
    for(int i=position;i<max;i++)
    {
        arr[i]=arr[i+1];
    }
    max--;
    display(arr);
}


void sort(int arr[])
{
    for(int i=0;i<max-1;i++)
    {
        for(int j=0;j<max-i-1;j++)
        { 
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
        	}
        }
    }
   
    display(arr);
}
