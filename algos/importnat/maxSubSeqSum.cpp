#include <iostream>
#include <vector>
int maxSubArray(std::vector<int> &nums)
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
    using namespace std;
    int n;
    // cout << "Number of terms: ";
    // cin >> n;
    n = 10;
    int a[10];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long sum = 0;
    long small_sum = 0;
    int n_end;

    for (int i = 0; i < n; i++)
    {
        small_sum = small_sum + a[i];
        if (small_sum > sum)
        {
            sum = small_sum;
        }
        if (small_sum < 0)
        {
            small_sum = 0;
        }
    }
    cout << "the max sub is: " << sum;

    return 0;
}
