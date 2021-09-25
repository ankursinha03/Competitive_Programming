#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool validMountainArray(vector<int> &arr)
{
    if (arr.size() < 3)
        return false;

    return true;
}

bool hasGroupsSizeX(vector<int> &deck)
{
    if (deck.size() < 2)
        return false;
    int max = INT_MIN;
    for (int i = 0; i < deck.size(); i++)
    {
        if (deck[i] > max)
        {
            max = deck[i];
        }
    }
    vector<int> count(max + 1);
    for (int i = 0; i < deck.size(); i++)
    {
        count[deck[i]]++;
    }
    int isODD = 0, isEVEN = 0;
    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] == 0)
            continue;
        if (count[i] % 2 == 0 && isEVEN == 0)
            isEVEN = 1;
        if (count[i] % 2 == 0 && isODD != 0)
            return false;
        if (count[i] % 2 != 0 && isODD == 0)
            isODD = 1;
        if (count[i] % 2 != 0 && isEVEN != 0)
            return false;
    }
    if (isODD == 1)
    {
        if (count[0] != count[1])
            return false;
    }
    return true;
}
int pivotIndex(vector<int> &nums)
{
    int Lsum = 0;
    int Rsum = 0;
    int i = -1;
    int j = nums.size();
    while (i < j)
    {
        if (abs(Lsum) == abs(Rsum))
        {

            i++;
            j--;
            Lsum += nums[i];
            Rsum += nums[j];
        }
        else if (abs(Lsum) < abs(Rsum))
        {

            i++;
            Lsum += nums[i];
        }
        else if (abs(Rsum) < abs(Lsum))
        {

            j--;
            Rsum += nums[j];
        }
    }
    if (Lsum == Rsum && i == j)
    {
        return i;
    }
    return -1;
}
int main()
{
    using namespace std;
    vector<int> z = {-1, -1, -1, -1, -1, 1};
    // string s = "gaf";
    // cout << slowestKey(z, s);
    cout << pivotIndex(z);
    return 0;
}
