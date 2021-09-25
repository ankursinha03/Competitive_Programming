#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int repeatedNumber(const vector<int> &A)
{
    // unordered_map<int, int> m;
    // for (int i = 0; i < A.size(); i++)
    // {
    //     auto it = m.find(A[i]);
    //     if (it == m.end())
    //     {
    //         m[A[i]]++;
    //     }
    //     else
    //     {
    //         return A[i];
    //     }
    // }
    // return -1;

    vector<int> B;
    B.assign(A.begin(), A.end());
    B[0] *= -1;
    for (int i = 0; i < B.size(); i++)
    {
        if (B[abs(B[i])] < 0)
        {
            return abs(B[i]);
        }
        else
        {
            B[abs(B[i])] *= -1;
        }
    }
    return -1;

    int slow = A[0];
    int fast = A[A[0]];
    while (slow != fast)
    {
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;
    while (slow != fast)
    {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}

int maximumGap(const vector<int> &A)
{
    if (A.size() < 2)
        return 0;
    vector<int> B;
    B.assign(A.begin(), A.end());
    sort(B.begin(), B.end());
    int maxDiff = 0;
    for (int i = 0; i < B.size() - 1; i++)
    {
        if (B[i + 1] - B[i] > maxDiff)
            maxDiff = B[i + 1] - B[i];
    }
    B.clear();
    return maxDiff;
}
int removeDuplicates(vector<int> &A)
{

    for (int i = 0; i < A.size(); i++)
    {
        auto a = lower_bound(A.begin(), A.end(), A[i]);
        auto b = upper_bound(A.begin(), A.end(), A[i]);
        if (b - a > 1)
        {
            A.erase(a);
            i--;
        }
    }
    return A.size();
}
int main()
{
    using namespace std;
    vector<int> v = {1, 1, 2};
    std::cout << removeDuplicates(v);
    return 0;
}