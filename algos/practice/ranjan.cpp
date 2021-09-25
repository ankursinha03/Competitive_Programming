#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> a;
    int i, j, m = nums.size();
    for (i = 0; i < nums.size(); i++)
    {
        a.push_back(nums[i] * nums[i]);
        j = i;
        if (i + 1 < m && nums[i + 1] >= 0)
            break;
    }
    for (i = j + 1; i < nums.size(); i++)
    { // O(N)
        nums[i] = nums[i] * nums[i];
    }

    cout << j;
    i = j + 1;
    while (j >= 0 && i < m)
    {
        if (a[j] < nums[i])
        {
            nums[i - 1 - j] = a[j];
            j--;
        }
        if (a[j] >= nums[i])
        {
            nums[i - 1 - j] = nums[i];
            i++;
        }
    }

    return nums;
}

int main()
{
    using namespace std;
    vector<int> v{-4, -1, 0, 3, 10};
    vector<int> k = sortedSquares(v);
    for (int a : k)
        std::cout << a << " ";

    return 0;
}