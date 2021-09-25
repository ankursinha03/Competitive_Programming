#include <bits/stdc++.h>
using namespace std;

void fourSome(vector<int> v, const int target)
{
    sort(v.begin(), v.end());
    int k, l, f = 1, i, j;
    for (i = 0; i < v.size(); i++)
    {
        for (j = i + 1; j < v.size(); j++)
        {
            k = j + 1;
            l = v.size() - 1;
            while (l > k)
            {
                if (v[i] + v[j] + v[k] + v[l] == target)
                {
                    f = 2;
                    std::cout << v[i] << v[j] << v[k] << v[l];
                    printf("\n");
                    k++;
                    l--;
                }
                else if (v[l] + v[k] > target - v[i] - v[j])
                {
                    l--;
                }
                else if (v[l] + v[k] < target - v[i] - v[j])
                {
                    k++;
                }
            }
        }
    }
}
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    set<vector<int>> s;
    vector<vector<int>> ans;
    if (nums.size() < 4)
        return ans;
    int n = nums.size();

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {

            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum < target)
                {
                    k++;
                }
                else if (sum == target)
                {
                    s.insert({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    for (auto x : s)
    {
        ans.push_back(x);
    }
    return ans;
}
int main()
{
    vector<int> k = {1, 2, 3, 4, 5, 9, 7, 8};

    fourSome(k, 16);
    k = {1, 0, -1, 0, -2, 2};
    fourSum(k, 0);
    return 0;
}
