#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    const int n = nums.size();
    vector<int> dp(n);
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] + i >= n - 1)
        {
            dp[i] = 1;
        }
        else if (nums[i] == 0)
        {
            dp[i] = INT_MAX;
        }
        else
        {
            int temp = INT_MAX;
            for (int k = i + 1; k <= i + nums[i]; k++)
            {
                if (dp[k] < temp)
                {
                    temp = dp[k];
                    if (temp == 1)
                        break;
                }
            }
            if (temp != INT_MAX)
                dp[i] = temp + 1;
            else
                dp[i] = temp;
        }
    }
    return dp[0];
}

//maximum increasing subseq
int maxSumIS(vector<int> arr)
{
    int n = arr.size();
    // int ans = INT_MIN;
    // int sum = 0;
    // vector<int> aux;
    // aux.push_back(arr[0]);
    // sum += arr[0];
    // ans = max(ans, sum);
    // for (int i = 1; i < n; i++)
    // {
    //     auto it = lower_bound(aux.begin(), aux.end(), arr[i]);
    //     if (it == aux.end())
    //     {
    //         sum += arr[i];
    //         aux.push_back(arr[i]);
    //         ans = max(ans, sum);
    //     }
    //     else
    //     {
    //         sum -= *it;
    //         sum += arr[i];
    //         *it = arr[i];
    //         ans = max(ans, sum);
    //     }
    // }
    // return ans;
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && (dp[i] < dp[j] + arr[i]))
            {
                dp[i] = dp[j] + arr[i];
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
bool isInterleave(string A, string B, string C)
{
    if (A.length() + B.length() != C.length())
        return false;

    int dp[A.length() + 1][C.length() + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= A.length(); i++)
    {
        for (int j = 1; j <= C.length(); j++)
        {
            if (A[i - 1] == C[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    if (dp[A.length()][C.length()] != A.length())
        return 0;
    int i = 0;
    int j = 0;
    vector<int> del;
    while (j < A.length())
    {
        if (C[i] == A[j])
        {
            del.push_back(i);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    while (!del.empty())
    {
        int k = del.back();
        C.erase(C.begin() + k);
        del.pop_back();
    }

    if (C != B)
        return 0;

    return 1;
}
int main()
{
    using namespace std;
    isInterleave("aabcc", "dbbca", "aadbbcbcac");
    vector<int> v;
    // v = {2, 3, 1, 1, 4};
    v = {20, 8, 27, 37, 9, 12, 46};
    maxSumIS(v);

    jump(v);
    return 0;
}