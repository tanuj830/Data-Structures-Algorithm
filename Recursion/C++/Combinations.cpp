// Print all the combinations of k elments.
// Refrence: https://www.geeksforgeeks.org/make-combinations-size-k/
#include<bits/stdc++.h>
using namespace std;

void findKCombinations(int arr[], vector<int>nums, int n, int k, int i)
{
    if(i==n)
    {
         if(nums.size() == k){
        for(int j=0;j<nums.size();j++)
            cout << nums[j] << " ";
            cout << endl;
    }
    return;
    }

   

    nums.push_back(arr[i]);
    findKCombinations(arr, nums, n, k, i+1);
    nums.pop_back();
    findKCombinations(arr, nums, n, k, i+1);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int k = 2;
    vector<int>nums;

    findKCombinations(arr, nums, 5, k, 0);

}