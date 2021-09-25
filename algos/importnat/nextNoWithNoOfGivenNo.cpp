#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
void Swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
void nextnum(int k)
{
    std::vector<int> nums;
    int i = 0;
    while (k > 0)
    {
        nums.push_back(k % 10);
        k /= 10;
    }
    reverse(nums.begin(), nums.end());
    int pos = nums.size() - 1;
    int last = nums[nums.size() - 1];

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] > last)
        {
            last = nums[i];
            pos--;
        }
        else
        {
            break;
        }
    }
    if (pos == 0)
    {
        std::cout << "NOT POSSIBLE";
        return;
    }
    else
    {
        for (int q = nums.size() - 1; q >= pos; q--)
        {
            if (nums[q] > nums[pos - 1])
            {
                Swap(nums[pos - 1], nums[q]);
                sort(nums.begin() + pos, nums.end());
                break;
            }
        }
        for (auto k : nums)
            std::cout << k;
        return;
    }
}
int main()
{
    using namespace std;
    nextnum(34722641);
    return 0;
}
