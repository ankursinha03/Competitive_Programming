#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> v)
{
    int i = 0;
    while (i < v.size())
    {
        if (v[i] > 0)
        {
            i++;
        }
        else if (v[i] < 0)
        {
            for (int k = i - 1; k >= 0; k--)
            {
                if (v[k] > abs(v[i]))
                {
                    v.erase(v.begin() + i);
                    i--;
                    break;
                }
                else if (v[k] == abs(v[i]))
                {
                    v.erase(v.begin() + i);
                    v.erase(v.begin() + k);
                    i = k - 1;
                    break;
                }
                else if (v[k] < abs(v[i]) && v[k] > 0)
                {
                    v.erase(v.begin() + k);
                    i--;
                }
            }
        }
    }
    return v;
}
int main()
{
    using namespace std;
    vector<int> v = {4, 5, -6, 7, -4};
    v = {3, -4, 2, -1, 6, 4, -5};
    solve(v);
    return 0;
}