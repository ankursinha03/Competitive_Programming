#include <bits/stdc++.h>
using namespace std;

int subArrayWithSum(vector<int> v, int k)
{

    int ans = INT_MAX;
    int i = 0;
    int j = 0;
    int s = v[0];
    if (v[0] == k)
        return 1;
    while (j < v.size())
    {

        if (s == k)
        {
            if (ans > j - i + 1)
                ans = j - i + 1;
            s -= v[i];
            i++;
        }
        else
        {
            if (s > k)
            {
                s -= v[i];
                i++;
                if (s == k)
                    if (ans > j - i + 1)
                        ans = j - i + 1;
            }
            else
            {

                j++;
                if (j == v.size())
                    break;
                s += v[j];
            }
        }
    }
    if (ans == INT_MAX)
        return 0;
    return ans;
}

int minSubarray1(vector<int> &nums, int p)
{
    int n = nums.size();
    int mod = 0;
    for (auto i : nums)
    {
        mod = (mod + i) % p;
    }

    if (mod == 0)
        return 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    int res = n;

    for (int i = 0; i < n; i++)
    {
        sum = (sum % p + nums[i]);
        int tmp = (sum - mod) % p;
        // tmp %=p;
        if (tmp < 0)
            tmp += p;
        if (mp.count(tmp))
        {
            res = min(res, i - mp[tmp]);
        }
        mp[sum % p] = i;
    }
    return res == n ? -1 : res;
}
int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();
    int s = nums[0];

    unordered_map<int, int> mp;
    mp[s % k]++;
    for (int i = 1; i < n; i++)
    {
        s += nums[i];
        s %= k;
        while (s < 0)
            s += k;
        mp[s]++;
    }
    int ans = 0;
    for (auto x : mp)
    {

        if (x.first != 0)
        {
            ans += x.second * (x.second - 1) / 2;
        }
        else
        {
            ans += x.second + x.second * (x.second - 1) / 2;
        }
    }
    return ans;
}
int minSubarray(vector<int> &nums, int p)
{
    int n = nums.size();
    int mod = 0;
    for (auto i : nums)
    {
        mod = (mod + i) % p;
    }

    if (mod == 0)
        return 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    int ans = n;

    for (int i = 0; i < n; i++)
    {
        sum = (sum + nums[i]) % p;
        int key = (sum - mod) % p;
        if (key < 0)
            key += p;
        if (mp.find(key) != mp.end())
        {
            ans = min(ans, i - mp[key]);
        }
        mp[sum] = i;
    }
    return ans == n ? -1 : ans;
}
int myminSubarray(vector<int> &nums, int p)
{
    int n = nums.size();
    int mod = 0;
    for (auto i : nums)
    {
        mod = (mod + i) % p;
    }

    if (mod == 0)
        return 0;
    unordered_map<int, int> mp;
    mp[mod] = -1;
    mp[0] = -1;
    int sum = 0;
    int ans = n;

    for (int i = 0; i < n; i++)
    {
        sum = (sum + nums[i]) % p;

        if (sum == mod)
        {
            ans = min(ans, i - mp[sum]);
        }
        mp[sum] = i;
    }
    return ans >= n - 1 ? -1 : ans;
}

int minSubarrayM(vector<int> &nums, int k)
{
    multimap<int, int> prefix_sum;
    long long int sum = 0;
    int minlen = INT_MAX;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = (sum + (nums[i] % k + k)) % k;
    }

    if (sum == 0)
        return 0;

    //find if we need to remove anything or not if yes then below
    // make prefix sum aaray, now in each iteration check if sum till there is equal to diff
    // if yes update minlen
    // then check if diff between sum and required is present as subarray sum, if yes again update it
    int diff = sum;
    sum = 0;
    int index = -1;
    for (int i = 0; i < nums.size(); i++)
    {

        sum = (sum + (nums[i] % k + k)) % k;

        if (sum == diff)
            minlen = min(minlen, i - index);
        else if (sum == 0)
            index = i;

        int temp = ((sum - diff) % k + k) % k;
        int temp_index = -1;

        if (prefix_sum.find(temp) != prefix_sum.end())
        {
            auto itr = prefix_sum.find(temp);
            while (itr->first == temp && itr != prefix_sum.end()) //can use upper_bound here
            {
                temp_index = itr->second;
                itr++;
            }

            minlen = min(minlen, i - temp_index);
        }

        prefix_sum.insert({sum, i});
    }
    if (minlen == INT_MAX || minlen == nums.size())
        return -1;
    return minlen;
}

int main()
{
    using namespace std;
    vector<int> v = {3, 1, 4, 2};
    // v = {3, 6, 8, 1};
    // v = {8, 32, 31, 18, 34, 20, 21, 13, 1, 27, 23, 22, 11, 15, 30, 4, 2};
    // v = {1, 1, 1};
    // v = {6, 3, 5, 2};
    // std::cout << minSubarray(v, 2);
    // printf("\n");
    std::cout << myminSubarray(v, 6);
    minSubarrayM(v, 6);
    // std::cout << subArrayWithSum(v, 12);

    return 0;
}