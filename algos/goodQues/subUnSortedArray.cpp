#include <iostream>
#include <vector>
using namespace std;

vector<int> subUnsort(vector<int> &A)
{
    vector<int> ans;
    int n = A.size();
    int i = 0, j = n - 1;
    while (i < n - 1 and A[i] <= A[i + 1])
    {
        i++;
    }
    while (j > 0 and A[j] >= A[j - 1])
    {
        j--;
    }
    if (i == n - 1)
    { // if array is already sorted, output -1
        ans.push_back(-1);
        return ans;
    }
    int mn = A[i + 1], mx = A[i + 1];
    for (int k = i; k <= j; k++)
    {
        mx = max(mx, A[k]);
        mn = min(mn, A[k]);
    }
    int l = 0, r = n - 1;
    while (A[l] <= mn and l <= i)
    {
        l++;
    }
    while (A[r] >= mx and r >= j)
    {
        r--;
    }
    ans.push_back(l);
    ans.push_back(r);
    return ans;
}
vector<int> UNSorted(vector<int> v)
{
    int i = 0;
    int j = v.size() - 1;
    vector<int> ans;
    while (i < v.size() - 1 && v[i] <= v[i + 1])
    {
        i++;
    }
    if (i == v.size() - 1)
    {
        ans.push_back(-1);
        return ans;
    }
    while (j >= 0 && v[j - 1] <= v[j])
    {
        j--;
    }
    int max, min;
    max = INT_MIN;
    min = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        if (v[k] > max)
            max = v[k];
        if (v[k] < min)
            min = v[k];
    }
    int b1, b2;
    for (int p = 0; p < i; p++)
    {
        if (v[p] > min)
        {
            b1 = p;
            break;
        }
        else
        {
            b1 = i;
        }
    }
    ans.push_back(b1);
    for (int q = v.size() - 1; q >= j; q--)
    {
        if (v[q] < max)
        {
            b2 = q;
            break;
        }
        else
        {
            b2 = j;
        }
    }
    ans.push_back(b2);
    return ans;
}

int main()
{

    vector<int> a = {16, 6, 18, 17, 13, 6, 18, 16, 6, 15, 15, 18, 16, 13, 16, 16, 6, 18, 15, 15};
    vector<int> ans;
    ans = subUnsort(a);
    for (int x : ans)
        std::cout << x << " ";
    printf("\n");
    printf("\n");
    ans = UNSorted(a);
    for (int x : ans)
        std::cout << x << " ";

    return 0;
}