#include <bits/stdc++.h>
using namespace std;

int lengthOfContinuous(vector<int> &v)
{
    int j, i;
    int ans = 0;
    j = i = 0;
    while (j < v.size() - 1)
    {
        if (v[j + 1] > v[j])
        {
            j++;
        }
        else
        {
            ans = max(ans, j - i);
            i = j + 1;
            j++;
        }
    }

    return ans;
}

int lengthOfINC_SS(vector<int> v)
{

    int n = v.size();
    vector<int> aux(n);
    aux[0] = v[0];
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        auto it = lower_bound(aux.begin(), aux.begin() + len, v[i]);
        if (it == aux.begin() + len)
        {
            aux[len++] = v[i];
        }
        else
        {
            *it = v[i];
        }
    }
    return len;
}
int main()
{
    using namespace std;
    vector<int> v;
    return 0;
}
