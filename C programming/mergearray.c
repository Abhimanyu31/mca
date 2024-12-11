#include<stdio.h>
#include<conio.h>


void main()
{
    int arr1[10],arr2[10],arr3[10],m,n;
    printf("Enter the size of the first array:");
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        printf("Enter the elements of the first array:");
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<m;i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("Enter the size of the second array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the elements of the second array:");
        scanf("%d",&arr2[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr2[i]);
    }
    for(int i=0;i<n;i++)
    {
      arr3[i]=arr1[i];
      arr3[m+i]=arr2[i];
    }
   
    for(int i=0;i<m+n;i++)
    {
        printf("\n%d ",arr3[i]);
    }
    getch();
}