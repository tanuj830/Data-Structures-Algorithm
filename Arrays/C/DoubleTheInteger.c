// Given an array and an integer 'b' ,traverse array and if you find present element in array equal to integer b then double it and resume traverse.
// arr[] = {1, 2, 3, 4, 5}; and b=2;
// output: 16
#include<stdio.h>

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int b = 2, n, i=0;

    n = sizeof(array) / sizeof(array[0]);

    while(i < n)
    {
        if(array[i] == b)
        b = b * b;

        i++;
    }

    printf("%d",b);
}