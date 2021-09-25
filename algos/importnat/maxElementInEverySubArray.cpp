#include <bits/stdc++.h>
using namespace std;

vector<int> maxElemetInSubArray(vector<int> a, int k)
{
    int i = 0;
    int j = k - 1;
    vector<int> ans;
    deque<int> nMax;
    for (int i = 0; i < k; i++)
    {
        if (nMax.empty())
        {
            nMax.push_back(a[i]);
        }
        else
        {
            if (a[i] > nMax.front())
            {
                while (a[i] > nMax.front())
                {
                    nMax.pop_front();
                    if (nMax.empty())
                        break;
                }
                if (nMax.empty())
                {
                    nMax.push_back(a[i]);
                }
                else
                {
                    nMax.push_back(a[i]);
                }
            }
            else
            {
                nMax.push_back(a[i]);
            }
        }
    }
    ans.push_back(nMax.front());
    while (j < a.size())
    {
        j++;
        if (j == a.size())
            break;
        if (a[i] != nMax.front())
        {
            i++;
        }
        else
        {
            nMax.pop_front();
            i++;
        }
        if (nMax.back() > a[j])
        {

            nMax.push_back(a[j]);
        }
        else
        {
            while (nMax.back() < a[j])
            {
                nMax.pop_back();
                if (nMax.empty())
                    break;
            }
            nMax.push_back(a[j]);
        }
        ans.push_back(nMax.front());
    }

    return ans;
}
int main()
{
    using namespace std;
    vector<int> v = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    maxElemetInSubArray(v, 3);
    return 0;
}