#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

vector<int> plusOne(vector<int> &A)
{
    vector<int> ans;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
        {
            A.erase(A.begin() + i);
            i--;
        }
        else
        {
            break;
        }
    }
    if (A.size() == 0)
    {

        ans.push_back(1);
        return ans;
    }
    int n = A.size();
    A[n - 1]++;
    int c = 0;

    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] + c > 9)
        {
            ans.push_back((A[i] + c) % 10);
            c = 1;
            if (i == 0)
            {
                ans.push_back(c);
            }
        }
        else
        {
            ans.push_back(A[i] + c);
            c = 0;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int solve(vector<int> &A, int B)
{
    // int ans = 0;
    // vector<int> light(A.size());
    // for (int i = 0; i < A.size(); i++)
    // {
    //     if (A[i] == 0)
    //     {
    //         continue;
    //     }
    //     else if (A[i] == 1)
    //     {
    //         int p, s;
    //         if (i - B + 1 < 0)
    //         {
    //             s = 0;
    //         }
    //         else
    //         {
    //             s = i - B + 1;
    //         }
    //         for (p = s; p <= i + B - 1 && p < A.size(); p++)
    //         {
    //             light[p]++;
    //         }
    //     }
    // }
    // for (int x : light)
    //     if (x == 0)
    //         return -1;
    // for (int i = 0; i < A.size(); i++)
    // {
    //     if (A[i] == 0)
    //     {
    //         continue;
    //     }
    //     else if (A[i] == 1)
    //     {
    //         int p, s;
    //         if (i - B + 1 <= 0)
    //         {
    //             s = 0;
    //         }
    //         else
    //         {
    //             s = i - B + 1;
    //         }
    //         for (p = s; p <= i + B - 1 && p < A.size(); p++)
    //         {
    //             light[p]--;
    //             if (light[p] == 0)
    //             {
    //                 ans++;
    //                 light[p]++;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // return ans;

    int ans = 0;
    vector<int> light(A.size());
    for (int i = 0; i < light.size(); i++)
    {
        if (light[i] == 0)
        {
            for (int j = A.size() - 1; j >= 0; j--)
            {
                if (A[j] == 0)
                    continue;
                if (j - B + 1 <= i)
                {
                    ans++;
                    int s;

                    if (j - B + 1 < 0)
                        s = 0;
                    else
                        s = j - B + 1;
                    for (int p = s; p <= j + B - 1 && p < A.size(); p++)
                        light[p]++;
                    break;
                }
            }
        }
    }
    for (int x : light)
        if (x == 0)
            return -1;
    return ans;
}
int solved(vector<string> &A)
{
    set<char> s;
    int m = A.size();
    int n = A[0].length();
    float area = 0;
    float base = 0;
    float height = 0;
    for (int c = 0; c < n - 1; c++)
    {
        for (int r = 0; r < m; r++)
        {
            s.clear();
            if (s.find(A[r][c]) == s.end())
                s.insert(A[r][c]);
            for (int p = r + 1; p < m; p++)
            {
                if (s.find(A[p][c]) == s.end())
                {
                    s.insert(A[p][c]);
                    base = p - r + 1;
                    for (int q = n - 1; q >= c; q--)
                    {
                        height = 0;
                        for (int i = 0; i < m; i++)
                        {
                            if (s.find(A[i][q]) == s.end())
                            {
                                height = q - c + 1;
                                if ((float)0.5 * base * height > area)
                                {
                                    area = (float)0.5 * base * height;
                                    break;
                                }
                            }
                        }
                    }
                    s.erase(A[p][c]);
                }
                base = 0;
            }
        }
    }
    return ceil(area);
}

int main()
{
    using namespace std;
    vector<string> A = {"rbrrggggbbbrgrrbr", "bbrrgbrbrgbrrgbbg", "ggbrggrrgrrgbrrrg", "rrrbgggbbggrrbgbr", "bbggggrbrgggrrbgg", "rrrbbgbgrrbrrgrbg", "gbbbrgbggrgbbrbgg", "bgbgrgbrbrgbrgggr", "bgbggrrrbrrgbrgbb", "brbggbbrrbgbrrgrb", "ggbbgbbbgbrbbbgbg", "gbrrbgrbrbgrrrgbg", "bgbrbbgrgbgrrrbgr", "brrgggbbgrrbgrbbg", "bbbrrbbbrbggrrbbr", "rrrrbgrbgrrbbrbbr", "gbggggrrrbrbggbgg", "grbgbbgrggrrrgbbg", "grgggbggbrgrgrgrb", "ggrrgrbggbrbggrbr", "ggbbbrgrbgbrggrgb", "grgbggrbrrrgrbbbg", "bbrrbrrbgbrrggbgg", "rrgrrgbggbbbgbggr", "rgrbrbrbgrbrrrrgg", "rgrbrbgrgrggbbrgr", "brgrggrgrgbgrrggg", "grbggrrbbrrgrgbgg", "rgrbbrbrgggrgrrbg"};
    std::cout << solved(A);
    return 0;
}