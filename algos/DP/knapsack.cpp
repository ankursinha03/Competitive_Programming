#include <bits/stdc++.h>
using namespace std;

int solveRecursive(vector<int> &w, vector<int> &v, int n, int bag)
{
    if (n == 0 || bag == 0)
        return 0;
    if (w[n - 1] <= bag)
    {
        return max(v[n - 1] + solveRecursive(w, v, n - 1, bag - w[n - 1]), solveRecursive(w, v, n - 1, bag));
    }
    return solveRecursive(w, v, n - 1, bag);
}

int solveMem(vector<int> &w, vector<int> &v, int n, int bag, vector<vector<int>> &m)
{
    if (n == 0 || bag == 0)
        return 0;
    if (m[n][bag] != -1)
    {
        return m[n][bag];
    }
    if (w[n - 1] <= bag)
    {
        m[n][bag] = max(v[n - 1] + solveMem(w, v, n - 1, bag - w[n - 1], m), solveMem(w, v, n - 1, bag, m));
        return m[n][bag];
    }
    m[n][bag] = solveMem(w, v, n - 1, bag, m);
    return m[n][bag];
}
int main()
{
    using namespace std;
    vector<int> v = {60, 100, 120};
    vector<int> w = {4, 5, 1};
    int bag = 50;
    std::cout << solveRecursive(w, v, v.size(), bag);
    printf("\n");   
    vector<vector<int>> memory(v.size() + 1, vector<int>(bag + 1, -1));
    std::cout << solveMem(w, v, v.size(), bag, memory);

    //iterative dynmaic programming
    //top down approach

    vector<vector<int>> dp(v.size() + 1, vector<int>(bag + 1));

    for (int n = 1; n < dp.size(); n++)
    {
        for (int b = 1; b < dp[0].size(); b++)
        {
            if (w[n - 1] <= b)
                dp[n][b] = max(v[n - 1] + dp[n - 1][b - w[n - 1]], dp[n - 1][b]);
            else
                dp[n][b] = dp[n - 1][b];
        }
    }
    printf("\n");
    std::cout << dp[dp.size() - 1][bag];

    printf("\n");
    printf("\n");

    //subset sum equal to target
    v = {3, 34, 4, 12, 5, 2};
    int target = 7;

    vector<vector<bool>> DP(v.size() + 1, vector<bool>(target + 1));
    for (int i = 0; i < DP.size(); i++)
    {
        DP[i][0] = 1;
    }

    for (int n = 1; n < DP.size(); n++)
    {
        for (int t = 1; t < DP[0].size(); t++)
        {
            if (v[n - 1] > t)
            {
                DP[n][t] = DP[n - 1][t];
            }
            else
            {
                DP[n][t] = (DP[n - 1][t - v[n - 1]] || DP[n - 1][t]);
            }

            // if (t < v[n - 1])
            //     DP[n][t] = DP[n - 1][t];
            // if (t >= v[n - 1])
            //     DP[n][t] = DP[n - 1][t] || DP[n - 1][n - v[n - 1]];
        }
    }
    std::cout << DP[DP.size() - 1][DP[0].size() - 1];

    // number of subset with given sum

    v = {1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6};
    int targetSum = 12;

    vector<vector<int>> DP_SS(v.size() + 1, vector<int>(targetSum + 1));
    for (int i = 0; i < DP_SS.size(); i++)
    {
        DP_SS[i][0] = 1;
    }

    for (int n = 1; n < DP_SS.size(); n++)
    {
        for (int t = 1; t < DP_SS[0].size(); t++)
        {
            if (v[n - 1] > t)
            {
                DP_SS[n][t] = DP_SS[n - 1][t];
            }
            else
            {
                DP_SS[n][t] = DP_SS[n - 1][t] + DP_SS[n - 1][t - v[n - 1]];
            }
        }
    }
    std::cout << "\n\n"
              << DP_SS[v.size()][targetSum];

    //minimum subset sum diff

    v = {1, 2, 1, 3};
    int diff = 1;
    long long sum = 0;
    for (auto x : v)
    {
        sum += (long long)x;
    }
    int TARGET = sum + diff / 2;
    vector<vector<int>> D(v.size() + 1, vector<int>(TARGET + 1));
    for (int i = 0; i < D.size(); i++)
    {
        D[i][0] = 1;
    }

    for (int n = 1; n < D.size(); n++)
    {
        for (int t = 1; t < D[0].size(); t++)
        {
            if (v[n - 1] > t)
            {
                D[n][t] = D[n - 1][t];
            }
            else
            {
                D[n][t] = D[n - 1][t] + D[n - 1][t - v[n - 1]];
            }
        }
    }
    std::cout << "\n\n"
              << D[v.size()][TARGET];

    return 0;
}