
#include <iostream>
#include <algorithm>
#include <vector>
int m = 0;
bool Sfn(int i, int j)
{
    int k = m;
    if (abs(i - k) > abs(j - k))
    {
        return true;
    }
    if (abs(i - k) == abs(j - k))
    {
        if (i > j)
            return true;
    }
    return false;
}
using namespace std;

vector<int> getStrongest(vector<int> &arr, int k)
{
    vector<int> ans;
    int mid;
    ans.assign(arr.begin(), arr.end());
    sort(ans.begin(), ans.end());

    mid = ((int)ans.size() - 1) / 2;
    m = ans[mid];
    sort(ans.begin(), ans.end(), Sfn);
    vector<int> back;
    for (int i = 0; i < k; i++)
    {
        back.push_back(ans[i]);
    }
    return back;
}

int main()
{

    int val = 2;
    vector<int> a = {-7, 22, 17, 3};
    vector<int> k;
    k = getStrongest(a, val);
    for (auto x : k)
    {
        cout << x;
    }

    return 0;
}
