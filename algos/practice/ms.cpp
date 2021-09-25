#include <bits/stdc++.h>
using namespace std;

// vector<int> ans;
// void solve(vector<int> soln, int sum, const long long &target, int count)
// {
//     if (sum > target)
//         return;
//     if (sum == target and count)
//     {
//         ans = soln;
//         return;
//     }
//     for (int i = 1; i <= 6; i++)
//     {
//         soln.push_back(i);
//         solve(soln, sum + i, target, count - 1);
//         soln.pop_back();
//     }
// }
// vector<int> solution(vector<int> &A, int F, int M)
// {
//     // write your code in C++14 (g++ 6.2.0)

//     long long sum = 0;
//     int n = A.size();
//     for (int i = 0; i < n; i++)
//     {
//         sum += (long long)A[i];
//     }
//     ans.clear();
//     long long total = M * (n + F);
//     long long reqSum = total - sum;
//     //x1+x2+x3+...+xf=reqSum
//     if (reqSum > (6 * F) || reqSum <= 0)
//         return {0};
//     vector<int> soln;

//     solve(soln, 0, reqSum, F);

//     return ans;
// }
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool solution(vector<int> A, vector<int> P, int B, int E)
{
    // write your code in C++14 (g++ 6.2.0)
    const int n = A.size();
    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++)
    {

        int e = P[i] + A[i];
        int s = P[i] - A[i];

        intervals.push_back({s, e});
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (merged.back()[1] < intervals[i][0])
            merged.push_back(intervals[i]);
        else
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
    }

    int p = min(B, E);
    int q = max(B, E);
    for (auto x : merged)
    {
        if (p >= x[0] && q <= x[1])
            return 1;
    }
    return 0;
}

int main()
{
    using namespace std;
    vector<int> v = {1, 5, 6};
    solution({1, 4, 2}, {10, 4, 7}, 11, 1);
    return 0;
}