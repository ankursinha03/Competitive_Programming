#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maximumGap(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    if (nums.size() == 2)
        return abs(nums[0] - nums[1]);
    int n = nums.size();
    auto itr = minmax_element(nums.begin(), nums.end());
    int mn = *itr.first;
    int mx = *itr.second;
    float gap = (float)(mx - mn) / (n - 1);
    if (gap == 0)
        return 0;
    vector<vector<int>> buff(n - 1);
    for (int x : nums)
    {
        if (x == mx)
        {
            buff[n - 2].push_back(x);
            continue;
        }

        buff[floor((x - mn) / gap)].push_back(x);
    }
    auto it = minmax_element(buff[0].begin(), buff[0].end());
    int prevMin = *it.first;
    int PrevMax = *it.second;
    int ans = INT_MIN;
    for (int i = 1; i < buff.size(); i++)
    {
        if (buff[i].size() == 0)
        {
            continue;
        }
        auto it = minmax_element(buff[i].begin(), buff[i].end());
        int mnn = *it.first;
        int mxx = *it.second;
        if (mnn - PrevMax > ans)
            ans = mnn - PrevMax;
        prevMin = mnn;
        PrevMax = mxx;
    }
    return ans;
}
int main()
{
    using namespace std;
    vector<int> v = {1, 1, 1, 1, 1, 5, 5, 5, 5, 5};
    std::cout << maximumGap(v);
    return 0;
}