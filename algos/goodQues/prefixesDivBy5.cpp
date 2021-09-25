#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an array nums of 0s and 1s, consider xi: the i-th subarray from nums[0] to nums[i]
// interpreted as a binary number (from most-significant-bit to least-significant-bit

vector<bool> prefixesDivBy5(vector<int> &a)
{
    // int q;
    // vector<bool> ans;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     q = 0;
    //     for (int j = 0; j <= i; j++)
    //     {
    //         q += nums[j] * pow(2, i - j);
    //     }
    //     if (q % 5 == 0)
    //         ans.push_back(true);
    //     else
    //         ans.push_back(false);
    // }
    // return ans;
    vector<bool> ans;
    int n = a.size(), curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr = curr * 2 + a[i];
        if (curr % 5 == 0)
            ans.push_back(1);
        else
            ans.push_back(0);

        curr %= 5;
    }
    return ans;
}
int main()
{
    using namespace std;
    vector<int> v = {1, 0, 1, 1};
    prefixesDivBy5(v);
    return 0;
}