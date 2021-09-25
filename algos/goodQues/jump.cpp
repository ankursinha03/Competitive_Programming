#include <bits/stdc++.h>
using namespace std;
int maxResult(vector<int> &nums, int k)
{
    // const int n = nums.size();
    // int dp[n];
    // memset(dp,0,sizeof(dp));
    // dp[0]=nums[0];
    // for(int i=1;i<n;i++){
    //     int temp = INT_MIN;
    //     int j=i-1;
    //     while(j>=0 and j>=i-k){
    //         temp=max(dp[j],temp);
    //         j--;
    //     }
    //     dp[i]=temp+nums[i];
    // }
    // return dp[n-1];

    const int n = nums.size();
    deque<pair<int, int>> dp;
    dp.push_back({0, nums[0]});
    int ans;
    for (int i = 0; i < n; i++)
    {
        int temp;
        while (1)
        {
            int index = dp.front().first;
            if (i - index <= k)
            {
                temp = dp.front().second;
                break;
            }
            dp.pop_front();
        }
        temp += nums[i];
        if (i == n - 1)
            ans = temp;
        if (dp.back().second > temp)
        {
            dp.push_back({i, temp});
        }
        else
        {
            while (dp.back().second < temp)
            {
                dp.pop_back();
                if (dp.empty())
                    break;
            }
            dp.push_back({i, temp});
        }
    }
    return ans;
}

int main()
{
    using namespace std;
    vector<int> v = {10, -5, -2, 4, 0, 3};
    std::cout << maxResult(v, 3);
    return 0;
}