// LL representation using stl
#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int>list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    for(auto i : list)
    {
        cout << i << " ";
    }
}