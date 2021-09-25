#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
    vector<int> v;
    return 0;
}