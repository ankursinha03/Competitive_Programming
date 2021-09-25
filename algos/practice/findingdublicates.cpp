#include <iostream>
#include <vector>

#include <bits/stdc++.h>
using namespace std;
void findDuplicates(vector<int> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        if (v[abs(v[i])] >= 0)
        {
            v[abs(v[i])] *= -1;
        }
        else
        {
            cout << abs(v[i]);
        }
    }
}
void printRepeating(vector<int> arr)
{
    int i;
    int size = arr.size();
    cout << "The repeating elements are:" << endl;
    for (i = 0; i < size; i++)
    {
        if (arr[abs(arr[i])] >= 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << " ";
    }
}

int main()
{
    using namespace std;
    vector<int> k = {1, 2, 3, 6, 3, 6, 1};
    findDuplicates(k);
    printf("\n");
    printRepeating(k);

    return 0;
}
