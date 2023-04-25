//Data Structure Array Deletion of index 3 element 
#include <stdio.h>
void display(int arr[], int size);
void indDeletion(int arr[], int size, int index);
int main()
{
int arr[7]= {17, 20, 30, 44, 58, 69};
int size=6;

int index;
printf("function call for Array Traversal\n");
display(arr, size);
printf("\n");
printf("function call for Deletion:\n");

indDeletion(arr,size, index=3);
size -=1;
display(arr,size);


return 0;
 
}
 
void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ",  arr[i]);
    }
    printf("\n");
    
}

 void indDeletion(int arr[], int n, int index)
{
    // code for Deletion
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }  
    
     
}


