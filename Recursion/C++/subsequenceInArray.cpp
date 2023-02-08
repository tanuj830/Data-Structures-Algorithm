#include<bits/stdc++.h>
using namespace std;

void FindAllSubset(int arr[], vector<int>v, vector<vector<int> >&vv, int i)
{
    if(i >= 3)
    {
        vv.push_back(v);
        return;
    }

    FindAllSubset(arr, v, vv, i+1);

    v.push_back(arr[i]);
    FindAllSubset(arr, v, vv, i+1);
}

int main()
{
    int arr[] = {1, 2, 3};
    vector<int>v;
    vector<vector<int> >vv;

    FindAllSubset(arr, v, vv, 0);

  for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }
}