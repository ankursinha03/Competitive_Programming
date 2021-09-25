#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int leftSum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        sum -= nums[i];
        if (leftSum == sum)
            return i;
        leftSum += nums[i];
    }

    return -1;
}
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> Map;
    pair<int, int> p;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = Map.find(nums[i]);
        if (it != Map.end())
        {
            int point = it->second;
            if (abs(point - i) <= k)
            {
                return true;
            }
            else
            {
                it->second = i;
            }
        }
        else
        {
            p.first = nums[i];
            p.second = i;
            Map.insert(p);
        }
    }

    return false;
}
double findMaxAverage(vector<int> &nums, int k)
{
    double avg = INT16_MIN;
    double sum = 0;
    for (int i = 0; i < nums.size() - k + 1; i++)
    {
        sum = 0;
        for (int j = i; j < i + k; j++)
        {
            sum += nums[j];
        }
        if (avg < sum)
            avg = sum;
    }
    avg /= k;
    return avg;
}
int maximumProduct(vector<int> &nums)
{

    sort(nums.begin(), nums.end());
    int a, b, c;
    a = nums[nums.size() - 1];
    b = nums[nums.size() - 2];
    c = nums[nums.size() - 3];
    if (a > 0)
    {
        if (nums[0] * nums[1] > b * c)
            return nums[0] * nums[1] * a;
        else
            return a * b * c;
    }

    if (a < 0)
        return a * b * c;
    return -1;
}
int main()
{
    using namespace std;
    // std::unordered_map<std::string, double> mymap = {
    //     {"mom", 5.4},
    //     {"dad", 6.1},
    //     {"bro", 5.9}};

    // std::string input;
    // std::cout << "who? ";
    // getline(std::cin, input);

    // std::unordered_map<std::string, double>::const_iterator got = mymap.find(input);

    // if (got == mymap.end())
    //     std::cout << "not found";
    // else
    //     std::cout << got->first << " is " << got->second;

    // std::cout << std::endl;
    vector<int> v = {-100, -98, -1, 2, 3, 4};
    // std::cout << containsNearbyDuplicate(v, 1);
    std::cout << maximumProduct(v);

    return 0;
}