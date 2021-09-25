#include <bits/stdc++.h>
using namespace std;

vector<int> NearestGreatestRIGHT(vector<int> q)
{
    vector<int> ans;
    stack<int> s;
    for (int i = q.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            ans.push_back(-1);
            s.push(q[i]);
        }
        else
        {
            if (s.top() > q[i])
            {
                ans.push_back(s.top());
                s.push(q[i]);
            }
            else
            {
                while (s.top() <= q[i])
                {
                    s.pop();
                    if (s.empty())
                    {
                        ans.push_back(-1);
                        break;
                    }
                }
                if (!s.empty())
                {
                    ans.push_back(s.top());
                    s.push(q[i]);
                }
                else
                {
                    s.push(q[i]);
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> NearestSmallestRIGHT(vector<int> q)
{
    vector<int> ans;
    stack<int> s;
    for (int i = q.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            ans.push_back(-1);
            s.push(q[i]);
        }
        else
        {
            if (s.top() < q[i])
            {
                ans.push_back(s.top());
                s.push(q[i]);
            }
            else
            {
                while (s.top() >= q[i])
                {
                    s.pop();
                    if (s.empty())
                    {
                        ans.push_back(-1);
                        break;
                    }
                }
                if (!s.empty())
                {
                    ans.push_back(s.top());
                    s.push(q[i]);
                }
                else
                {
                    s.push(q[i]);
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> STOCK_SPAN(vector<int> v)
{
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
        {
            s.push(i);
            ans.push_back(1);
        }
        else
        {
            if (v[s.top()] > v[i])
            {
                ans.push_back(i - s.top());
                s.push(i);
            }
            else
            {

                while (v[s.top()] < v[i] && !s.empty())
                {

                    s.pop();
                    if (s.empty())
                        break;
                }
                if (s.empty())
                {
                    ans.push_back(i + 1);
                    s.push(i);
                }
                else
                {
                    ans.push_back(i - s.top());
                    s.push(i);
                }
            }
        }
    }

    return ans;
}
int areaOfHistogramBruteForce(vector<int> v)
{
    int ans = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        int k, j;
        for (k = i - 1; k >= 0; k--)
        {
            if (v[k] < v[i])
                break;
        }
        for (j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[i])
                break;
        }
        if (ans < (j - k - 1) * v[i])
            ans = (j - k - 1) * v[i];
    }

    return ans;
}
int areaOfHistogram(vector<int> v)
{
    int ans = INT_MIN;
    stack<int> L;
    stack<int> R;
    vector<int> minL;
    vector<int> minR;
    for (int i = 0; i < v.size(); i++)
    {
        if (L.empty())
        {
            minL.push_back(-1);
            L.push(i);
        }
        else
        {
            if (v[L.top()] >= v[i])
            {
                while (v[L.top()] >= v[i])
                {
                    L.pop();
                    if (L.empty())
                        break;
                }
                if (L.empty())
                {
                    minL.push_back(-1);
                    L.push(i);
                }
                else
                {
                    minL.push_back(L.top());
                    L.push(i);
                }
            }
            else
            {
                minL.push_back(L.top());
                L.push(i);
            }
        }
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (R.empty())
        {
            minR.push_back(v.size());
            R.push(i);
        }
        else
        {
            if (v[R.top()] >= v[i])
            {
                while (v[R.top()] >= v[i])
                {
                    R.pop();
                    if (R.empty())
                        break;
                }
                if (R.empty())
                {
                    minR.push_back(v.size());
                    R.push(i);
                }
                else
                {
                    minR.push_back(R.top());
                    R.push(i);
                }
            }
            else
            {
                minR.push_back(R.top());
                R.push(i);
            }
        }
    }
    reverse(minR.begin(), minR.end());
    for (int i = 0; i < v.size(); i++)
    {
        if ((minR[i] - minL[i] - 1) * v[i] > ans)
            ans = (minR[i] - minL[i] - 1) * v[i];
    }
    return ans;
}
int main()
{
    using namespace std;
    // vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    vector<int> v = {31, 41, 48, 59, 79};
    // areaOfHistogramBruteForce(v);
    std::cout << areaOfHistogram({2, 1, 5, 6, 2, 3});
    STOCK_SPAN(v);
    // NearestGreatestRIGHT(v);
    // NearestSmallestRIGHT(v);
    return 0;
}