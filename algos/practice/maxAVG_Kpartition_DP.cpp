#include <bits/stdc++.h>
using namespace std;

double solve(const vector<int> &nums, int k, int s, int e)
{
    if (e < s)
        return 0.0;
    if (k == 0)
    {
        return (double)(nums[e] - nums[s]) / (e - s + 1);
    }
    if (k < 0)
        return 0.0;
    double ans = -1;

    for (int i = s; i <= e; i++)
    {
        double a = solve(nums, k - 1, s, i) * (i - s + 1);
        double b = solve(nums, k - 1, i + 1, e) * (e - i);
        double temp = (double)(a + b) / (e - s + 1);
        ans = max(ans, temp);
    }
    return ans;
}

double largestSumOfAverages(vector<int> &nums, int k)
{
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
    }
    return solve(nums, k, 0, n - 1);
}
int fn(int a, char ch)
{
    std::cout << a;
    return a;
}
int fn(char ch, int a)
{
    return 2;
}
int main()
{
    using namespace std;
    vector<int> v = {9, 1, 2, 3, 9};
    std::cout << largestSumOfAverages(v, 1);
    return 0;
}
