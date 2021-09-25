#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArr(vector<int> &A)
{
    // int ans = 0;
    // for (int i = 0; i < A.size() - 1; i++)
    // {
    //     for (int j = i + 1; j < A.size(); j++)
    //     {
    //         if (abs(A[i] - A[j]) + abs(i - j) > ans)
    //             ans = abs(A[i] - A[j]) + abs(i - j);
    //     }
    // }
    // return ans;

    int max1, max2, min1, min2;
    //1 a[i]-i
    //2 a[i]+i
    max1 = max2 = INT_MIN;
    min1 = min2 = INT_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        int t = A[i];

        min1 = (min1 > t - i) ? t - i : min1;
        max1 = (max1 < t - i) ? t - i : max1;

        min2 = (min2 > t + i) ? t + i : min2;
        max2 = (max2 < t + i) ? t + i : max2;
    }
    int p = max1 - min1;
    int q = max2 - min2;
    return (max(p, q));
}

int main()
{
    using namespace std;
    vector<int> v = {1, 3, -1};
    cout << maxArr(v);

    return 0;
}
