#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int numEquivDominoPairs(vector<vector<int>> &dominoes)
{
    int ans = 0;

    map<vector<int>, int> m;
    for (auto i : dominoes)
    {
        sort(i.begin(), i.end());
        if (m.find(i) != m.end())
            ans += m[i]++;
        else
            m[i]++;
    }

    return ans;
}
int findLengthOfLCIS(vector<int> &nums)
{
    int ans = 0;
    int i = 0;
    int j = 0;
    while (j < nums.size())
    {
        if (j == nums.size() - 1)
        {
            if (ans < j - i + 1)
            {
                ans = j - i + 1;
            }
            break;
        }
        if (nums[j + 1] > nums[j])
        {
            j++;
        }
        else
        {
            if (ans < j - i + 1)
            {
                ans = j - i + 1;
            }
            j++;
            i = j;
        }
    }
    return ans;
}
vector<vector<int>> largeGroupPositions(string s)
{

    int i = 0, j = 0;
    vector<vector<int>> ans;
    while (j < s.length())
    {
        if (j >= s.length() - 1)
        {
            if (j - i + 1 >= 3)
            {
                ans.push_back({i, j});
            }
            break;
        }
        if (s[j + 1] != s[j])
        {
            if (j - i + 1 >= 3)
            {
                ans.push_back({i, j});
            }
            j++;
            i = j;
        }
        else
        {
            j += 2;
        }
    }
    return ans;
}
vector<bool> prefixesDivBy5(vector<int> &nums)
{
    int q;
    vector<bool> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        q = 0;
        for (int j = 0; j <= i; j++)
        {
            q += nums[j] * pow(2, i - j);
        }
        if (q % 5 == 0)
            ans.push_back(true);
        else
            ans.push_back(false);
    }
    return ans;

    // vector<bool> ans;
    // int n = a.size(), curr = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     curr = curr * 2 + a[i];
    //     if (curr % 5 == 0)
    //         ans.push_back(1);
    //     else
    //         ans.push_back(0);

    //     curr %= 5;
    // }
    // return ans;
}
bool isOneBitCharacter(vector<int> &bits)
{
    int j = 0;
    while (j < bits.size())
    {
        if (j == bits.size())
        {
            return false;
        }
        if (j == bits.size() - 1)
        {
            return true;
        }
        if (bits[j] == 1)
        {
            j = j + 2;
        }
        else
        {
            j++;
        }
    }
    return false;
}
void duplicateZeros(vector<int> &arr)
{
    int j = 0;

    while (j < arr.size())
    {
        if (arr[j] != 0)
        {
            j++;
            continue;
        }
        else
        {
            for (int i = arr.size() - 1; i > j; i--)
            {
                arr[i] = arr[i - 1];
            }
            j += 2;
        }
    }
}
int maxProfit(vector<int> &prices)
{
    int j = 0;
    int ans = 0;
    int min, max;
    int maxI = 0;
    min = prices[0];
    max = INT_MIN;
    while (j < prices.size())
    {
        j++;
        if (j == prices.size())
            break;
        if (prices[j] < min)
        {
            min = prices[j];
            if (maxI < j)
            {
                max = INT_MIN;
            }
            continue;
        }
        else if (prices[j] > max)
        {
            max = prices[j];
            maxI = j;
        }
        if (max - min > ans)
        {
            ans = max - min;
        }
    }
    return ans;
}
int solve(vector<int> &A)
{
    // int ans = INT_MIN;
    // int i, j, k;
    // i = 0;
    // j = 1;
    // k = 2;
    // // while (k<A.size())
    // // {
    // //     if(A[i]<A[j]<A[k]){
    // //         if(A[i]+A[j]+A[k]>ans){
    // //             ans=A[i]+A[j]+A[k];
    // //         }
    // //     }else{
    // //         k++;
    // //         if(k==A.size()-1&&j<A.size()-2){
    // //             j++;
    // //             k=j+1;
    // //         }
    // //         else if(j==A.size()-2){
    // //             i++;
    // //         }
    // //     }

    int ans = 0;

    vector<int> maxAhead(A.size());
    maxAhead.back() = A.back();
    for (int i = A.size() - 2; i >= 0; i--)
    {
        maxAhead[i] = max(A[i], maxAhead[i + 1]);
    }
    set<int> s;
    s.insert(A[0]);

    for (int i = 1; i < A.size() - 1; i++)
    {

        if (A[i] >= maxAhead[i])
            continue;
        s.insert(A[i]);
        auto it = s.find(A[i]);
        if (it == s.begin())
        {
            continue;
        }
        it--;

        if (*it + A[i] + maxAhead[i] > ans)
            ans = *it + A[i] + maxAhead[i];
    }
    return ans;

    // int ans = 0;
    // int min = INT_MIN;
    // int max = INT_MIN;
    // for (int i = 1; i < A.size() - 1; i++)
    // {
    //     min = INT_MIN;
    //     max = INT_MIN;
    //     for (int j = 0; j < i; j++)
    //         if (A[j] > min && A[j] < A[i])
    //             min = A[j];

    //     for (int k = i + 1; k < A.size(); k++)
    //         if (A[k] > max)
    //             max = A[k];
    //     if (A[i] > max)
    //         continue;
    //     if (min + A[i] + max > ans)
    //         ans = min + A[i] + max;
    // }
    // return ans;
}
int solved(vector<vector<int>> &A, int B)
{
    int sum = 0;
    int ans = INT_MIN;
    int i = 0;
    int j = 1;

    int trim1 = 0, trim2 = 0;
    while (i + B - 1 < A.size())
    {
        sum = 0;
        for (int t = i; t < B + i; t++)
        {
            for (int p = 0; p < B; p++)
            {
                sum += A[t][p];
            }
        }
        j = 1;
        if (sum > ans)
            ans = sum;
        while (j + B - 1 < A.size())
        {
            trim1 = 0;
            trim2 = 0;
            for (int p = i; p < B + i; p++)
            {
                trim1 += A[p][j - 1];
            }
            sum -= trim1;
            for (int p = i; p < B + i; p++)
            {
                trim2 += A[p][j + B - 1];
            }
            sum += trim2;
            if (sum > ans)
                ans = sum;
            j++;
        }
        i++;
    }
    return ans;
}

int main()
{
    using namespace std;
    // vector<vector<int>> dominoes = {{1, 1}, {2, 2}, {1, 1}, {1, 2}, {1, 2}, {1, 1}};
    // std::cout << numEquivDominoPairs(dominoes);
    // vector<int> v = {2, 1};
    // std::cout << findLengthOfLCIS(v);
    string s = "abcdddeeeeaabbbcd";
    vector<vector<int>> g = largeGroupPositions(s);
    vector<vector<int>> nums = {
        {-50, 73, -34, -56, -41, -8, -61, -47, -76, 54, 10, 45, -51, 86, 13, -26, -78, 68, -82, 87},
        {5, 58, 91, -98, -75, -23, -86, 14, -76, 34, -26, 72, 59, -67, -30, -13, -3, 18, 77, 73},
        {-30, 63, -32, 92, 85, 2, -20, -87, -73, -98, -1, 27, -75, 43, 24, -77, 72, -39, 81, -97},
        {-68, 5, 93, 25, -69, -8, 42, -78, -14, -36, 0, 87, 60, -87, 74, -30, 70, -65, -67, 11},
        {60, -4, -33, -15, 50, 40, -6, -5, -76, -81, 25, 76, -6, -42, 2, 71, -34, -22, 93, -49},
        {-16, -82, -36, 19, 52, -100, -13, -40, 26, -90, 57, 70, 15, 76, -73, -57, 58, 64, 9, -18},
        {-14, 65, -13, 77, -26, -75, -73, -71, 28, -77, 20, 2, 62, 23, 96, 37, -39, 95, 25, -36},
        {-40, -98, 16, -70, 26, -89, 71, -89, 47, 53, 20, 90, 24, 88, 63, 40, -49, -38, -71, 0},
        {13, 58, 78, 65, -93, -23, -100, -42, -61, 3, 60, 57, 24, -23, 8, 13, -13, -99, -50, -40},
        {-72, 93, 84, -95, 40, 11, 4, -65, 56, -28, 50, -77, -15, 56, -84, -74, 57, 26, 57, 37},
        {-29, -31, 61, -4, -78, -83, 12, 17, -4, 85, -59, -77, 29, -71, 65, 59, 32, -4, -45, -47},
        {62, 84, 34, -46, 72, -43, 69, 32, 63, -93, -17, 11, -65, -33, -52, -25, 38, -77, 42, 54},
        {11, 41, 75, -41, -75, -79, -30, -74, 34, -95, 83, -50, 98, -21, 1, 93, 34, -63, 34, 56},
        {93, 76, 5, 62, 48, -19, 0, -87, -59, -45, -45, 42, -38, -89, -23, -76, -22, 52, -57, -4},
        {-27, -60, 13, -25, -28, -82, -90, -83, 32, 12, -5, 69, -69, -60, -12, -15, -10, -3, 89, 90},
        {45, 53, 14, -49, 40, -56, -42, 35, 59, 92, -95, -36, 81, 3, -71, 75, -92, -8, 97, 49},
        {56, 61, -73, -33, 41, 29, -60, -87, 74, -99, -23, -85, -17, -87, 92, -76, -99, 92, 59, -30},
        {-72, -73, -16, -25, 86, -2, 70, -13, -53, -96, 3, -79, -37, 6, 63, -90, 71, -11, -60, 64},
        {42, -81, 13, 91, 4, -82, -68, 50, -95, 75, 39, 3, -78, -2, -53, 84, -52, 71, -36, 13},
        {-25, 45, 12, 46, -22, 69, -38, 19, 85, -11, 44, -35, 40, -55, 8, 18, -30, -99, 23, 32},
    };
    // prefixesDivBy5(nums);
    // std::cout << isOneBitCharacter(nums);
    std::cout << solved(nums, 13);
    return 0;
}