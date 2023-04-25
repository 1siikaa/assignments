//Data Structure Array Traversal 
#include <stdio.h>
void display(int arr[], int n);
int main()
{
int arr[7]= {1, 2, 3, 4, 5, 6};
int n=6;
printf("Code for Array Traversal\n");
display(arr, n);
return 0;
 
}
 
void display(int arr[7], int n)
{
    // Code for Traversal
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",  arr[i]);
    }
    printf("\n");
    
}
