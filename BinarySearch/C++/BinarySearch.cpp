#include<bits/stdc++.h>
using namespace std;

int searchElement(int array[], int start, int n, int k)
{
     if(start < n)
     {
         int mid = (start+n)/2;

         if(array[mid] == k)
              return mid;
        searchElement(array, 0, mid, k);
        searchElement(array, mid+1, n, k);
     }
     return -1;
}

int main()
{
   int array[] = {1,2,3,4,5,7,8};

   cout << "index: " << searchElement(array, 0, 7, 41);
    
}