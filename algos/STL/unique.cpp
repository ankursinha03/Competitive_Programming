#include <bits/stdc++.h>
using namespace std;

int main()
{
    using namespace std;
    // vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    // auto it = unique(v.begin(), v.end());
    // for (auto i = v.begin(); i != it; i++)
    // {
    //     std::cout << *i;
    // }
    // printf("\n");
    // for (int x : v)
    //     std::cout << x << " ";
    vector<int> A;
    A = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    // auto itr = unique(A.begin(), A.end());
    // auto it = unique(itr, A.end());
    // A.erase(it, A.end());
    // sort(A.begin(), A.end());
    // int ans = it - A.begin();
    // return ans;
    //A = {0};
    A = {1000, 1000, 1000, 1000, 1001, 1002, 1003, 1003, 1004, 1010};
    A = {0, 0, 0, 1, 1, 2, 2, 3};
    int s = -1;
    int count = 0;
    int prev = A[0];
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == prev)
            count++;
        else
        {
            count = 1;
            prev = A[i];
        }
        s++;
        if (count > 2)
        {
            while (i < A.size() and A[i] == prev)
                i++;
            if (i == A.size())
                i--;
            A[s] = A[i];
            prev = A[i];
            count = 1;
        }
        A[s] = A[i];
        if (i == A.size() - 1 and (A[i] != A[i - 1] or s == i - 1))
        {
            s++;
        }
    }
    if (s == 0)
        return A.size();
    A.erase(A.begin() + s, A.end());
    return A.size();

    return 0;
}