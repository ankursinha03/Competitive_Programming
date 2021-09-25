#include <bits/stdc++.h>
using namespace std;

int activityNotifications(vector<int> expenditure, int d)
{
    int n = expenditure.size();
    if (n == d)
        return 0;
    list<int> ll;
    for (int i = 0; i < d; i++)
    {
        ll.push_back(expenditure[i]);
    }
    ll.sort();
    int median;
    if (d % 2)
    {
        median = *next(ll.begin(), d / 2);
    }
    else
    {
        int k = d / 2;
        median = *next(ll.begin(), k) + *next(ll.begin(), k + 1);
        median /= 2;
    }
    int count = 0;
    for (int i = d; i < n; i++)
    {
        if (expenditure[i] >= 2 * median)
            count++;
        ll.pop_front();

        if (ll.back() < expenditure[i])
        {
            ll.push_back(expenditure[i]);
        }
        else
        {
           auto it = lower_bound(ll.begin(),ll.end(),expenditure[i]);
            ll.insert(it, expenditure[i]);
        }

        if (d % 2)
        {
            median = *next(ll.begin(), d / 2);
        }
        else
        {
            int k = d / 2;
            median = *next(ll.begin(), k) + *next(ll.begin(), k + 1);
            median /= 2;
        }
    }
    return count;
}
vector<int> base2To6Hire2020(vector<bool> base2)
{
    int decimal = 0;
    int n = base2.size();
    for (int i = 0; i < n; i++)
    {
        if (base2[i])
            decimal += pow(2, i);
    }
    vector<int> ans;

    while (decimal > 0)
    {
        int k = decimal % 6;
        ans.push_back(k);
        decimal /= 6;
    }

    return ans;
}
int ans = 0;
void count(string temp, int caffe, int f)
{
    if (caffe < 0)
        return;
    if (f < 0)
        return;
    if (f == 0)
    {
        ans++;
    }

    count(temp + 'R', caffe, f - 1);
    count(temp + 'C', caffe - 1, f - 1);
    if (temp.empty())
        count(temp + 'O', caffe, f - 1);
    else if (temp.size() < 2)
    {
        count(temp + 'O', caffe, f - 1);
    }
    else
    {
        string k = temp.substr(temp.length() - 2);
        if (k != "OO")
            count(temp + 'O', caffe, f - 1);
    }
}
int FY22CampusAllPossibleBuildings(int floors)
{
    string temp = "";
    count(temp, 1, floors);
    return ans;
}
int main()
{
    using namespace std;
    vector<int> vv = {2, 3, 4, 2, 3, 6, 8, 4, 5};
    activityNotifications(vv, 5);
    std::cout << FY22CampusAllPossibleBuildings(2);
    vector<bool> v = {0, 0, 1, 1};
    base2To6Hire2020(v);
    return 0;
}