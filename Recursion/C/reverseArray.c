#include<stdio.h>
int j=0;
void reverse(int arr[], int n, int i)
{
    if(n==i) return;

int temp = arr[i];
    reverse(arr, n, i+1);

    arr[j] = temp;
    j++;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    
    reverse(arr, 5, 0);

    for(int i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
}