#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

int solved(vector<string> &A)
{
    int m = A.size();
    int n = A[0].length();
    vector<vector<int>> calc(n); //RG RB GB
    set<char> s;
    int RG, RB, GB;

    for (int c = 0; c < n; c++)
    {
        RG = RB = GB = 0;
        int i = INT_MAX;
        for (int r = 0; r < m; r++)
        {
            if (A[r][c] == 'r' && i == INT_MAX)
            {
                i = r;
            }
            if (A[r][c] == 'g')
            {
                if (r - i > RG)
                    RG = r - i + 1;
            }
        }
        i = INT_MAX;
        for (int r = 0; r < m; r++)
        {
            if (A[r][c] == 'r' && i == INT_MAX)
            {
                i = r;
            }
            if (A[r][c] == 'b')
            {
                if (r - i > RB)
                    RB = r - i + 1;
            }
        }
        i = INT_MAX;
        for (int r = 0; r < m; r++)
        {
            if (A[r][c] == 'g' && i == INT_MAX)
            {
                i = r;
            }
            if (A[r][c] == 'b')
            {
                if (r - i > GB)
                    GB = r - i + 1;
            }
        }
        calc[c].push_back(RG);
        calc[c].push_back(RB);
        calc[c].push_back(GB);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
                }
    }
    return ans;
}
int main()
{
    using namespace std;
    vector<string> A = {"rrrrr", "rrrrg", "rrrrr", "bbbbb"};
    std::cout << solved(A);
    return 0;
}