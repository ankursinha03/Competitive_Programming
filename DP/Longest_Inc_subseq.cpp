#include <bits/stdc++.h>
using namespace std;

int maxIncSubSeqSum(vector<int> v)
{
    const int n = v.size();

    vector<int> dp(n);

    for (int i = 0; i < n; i++)
    {
        dp[i] = v[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j] and dp[i] < dp[j] + v[i])
                dp[i] = dp[j] + v[i];
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    using namespace std;
    vector<int> v = {1, 2, 3, 100};
    std::cout << maxIncSubSeqSum(v);
    return 0;
}