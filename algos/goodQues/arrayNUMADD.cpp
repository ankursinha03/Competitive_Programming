#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> addToArrayForm(vector<int> &num, int k)
{
    vector<int> ans;
    vector<int> kv;
    while (k != 0)
    {
        kv.push_back(k % 10);
        k = k / 10;
    }
    reverse(kv.begin(), kv.end());
    if (kv.size() > num.size())
        num.swap(kv);
    int lkv = kv.size();
    for (int i = num.size() - 1;; i--)
    {

        lkv--;
        if (lkv < 0)
            break;
        num[i] += kv[lkv];
    }
    int c = 0;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if (num[i] + c < 10)
        {
            ans.push_back(num[i] + c);
            c = (num[i] + c) / 10;
        }

        else
        {
            if (i == 0)
            {
                ans.push_back(num[i] + c);
                break;
            }
            ans.push_back((num[i] + c) % 10);
            c = (num[i] + c) / 10;
        }
    }
    if (ans.back() >= 10)
    {
        int x = ans.back();
        ans.back() = ans.back() % 10;
        ans.push_back(x / 10);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int ans = 0;
    int count = 0;
    if (nums.size() == 1)
    {
        if (nums[0] == 1)
            return 1;
        return 0;
    }
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1] && nums[i] == 1)
            count++;
        else
            count = 0;
        if (count > ans)
            ans = count;
    }
    ans++;
    return ans;
}
int main()
{
    using namespace std;

    vector<int> j = {0, 0};
    // vector<int> ans;
    // ans = addToArrayForm(j, 26);
    // for (int x : ans)
    //     std::cout << x << ",";
    std::cout << findMaxConsecutiveOnes(j);
    return 0;
}
