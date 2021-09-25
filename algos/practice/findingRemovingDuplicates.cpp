#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }
    auto itr = nums.begin();
    for (int i = 0; i < int(nums.size()) - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            nums.erase(itr + i + 1);
            i--;
        }
    }
    return nums.size();
}
int removeElement(vector<int> &nums, int val)
{
    if (nums[0] == val)
    {
        nums.erase(nums.begin());
    }
    for (int i = 0; i < (int)nums.size() - 1; i++)
    {
        if (nums[i + 1] == val)
        {
            nums.erase(nums.begin() + i);
        }
    }
    return (int)nums.size();
}
int searchInsert(vector<int> &nums, int target)
{
    auto Lbound = lower_bound(nums.begin(), nums.end(), target);
    return (int)(Lbound - nums.begin());
}

int maxSubArray(vector<int> &nums)
{
    if ((int)nums.size() == 0)
        return 0;
    int sum = nums[0];
    int maxNegative = nums[0];
    int x = 0;
    int f = 0;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (nums[i] < 0 && f == 0)
        {
            if (maxNegative < nums[i])
                maxNegative = nums[i];
            continue;
        }
        f = 1;
        x = x + nums[i];
        if (sum < x)
        {
            sum = x;
        }
        if (x < 0)
            x = 0;
    }
    if (f == 0)
    {
        return maxNegative;
    }
    return sum;
}
int main()
{
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    vector<int> a = {
        -2,
        -8,
        -3,
        -1,
        -5};
    int k = 7;
    cout << maxSubArray(a);
    // printf("\n");
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }

    return 0;
}
