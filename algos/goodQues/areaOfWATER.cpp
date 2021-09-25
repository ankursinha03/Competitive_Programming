#include <iostream>
using namespace std;
#include <vector>

int WATERCOLLECTED(vector<int> v) //O(n^2) spaceComplexity O(1)
{
    int ans = 0;
    int LMAX;
    int RMAX;

    for (int i = 0; i < v.size(); i++)
    {
        LMAX = RMAX = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            LMAX = (v[j] > LMAX) ? v[j] : LMAX;
        }
        LMAX = max(LMAX, v[i]);
        for (int k = i + 1; k < v.size(); k++)
        {
            RMAX = (v[k] > RMAX) ? v[k] : RMAX;
        }
        RMAX = max(RMAX, v[i]);
        ans += min(LMAX, RMAX) - v[i];
    }
    return ans;
}

//we can increase the time complexity but pre calculating the left and right max of each element in O(n) time

// left[0] = arr[0];
// for (int i = 1; i < n; i++)
//     left[i] = max(left[i - 1], arr[i]);

// right[n - 1] = arr[n - 1];
// for (int i = n - 2; i >= 0; i--)
//     right[i] = max(right[i + 1], arr[i]);

//this will lower our time complexity to O(n) and inc space complexity tok O(n)

//instead of storing RMAX and RMIN for each element we can just keep max and min till that element

int findWater(vector<int> v)
{

    int n = v.size();
    int result = 0;

    int left_max = 0, right_max = 0;

    int lo = 0, hi = n - 1;

    while (lo <= hi)
    {
        if (v[lo] < v[hi])
        {
            if (v[lo] > left_max)
                left_max = v[lo];
            else
                result += left_max - v[lo];
            lo++;
        }
        else
        {
            if (v[hi] > right_max)
                right_max = v[hi];
            else
                result += right_max - v[hi];
            hi--;
        }
    }
    return result;
}
int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> left(n);
    vector<int> right(n);
    left[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], height[i]);
    }
    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], height[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - height[i];
    }
    return ans;
}
int waterCollected(vector<int> v)
{
    int n = v.size();
    int size = n - 1;

    int prev = v[0];

    int prev_index = 0;
    int water = 0;

    int temp = 0;
    for (int i = 1; i <= size; i++)
    {
        if (v[i] >= prev)
        {
            prev = v[i];
            prev_index = i;
            temp = 0;
        }
        else
        {
            water += prev - v[i];
            temp += prev - v[i];
        }
    }
    if (prev_index < size)
    {
        water -= temp;
        prev = v[size];
        for (int i = size; i >= prev_index; i--)
        {
            if (v[i] >= prev)
            {
                prev = v[i];
            }
            else
            {
                water += prev - v[i];
            }
        }
    }
    return water;
}
int main()
{
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << WATERCOLLECTED(v) << " " << waterCollected(v) << " " << trap(v);
    return 0;
}
