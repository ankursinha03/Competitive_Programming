#include <iostream>
#include <vector>
using namespace std;

int FindMaxSum(vector<int> arr, int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for (i = 1; i < n; i++)
    {
        excl_new = (incl > excl) ? incl : excl;
        incl = excl + arr[i];
        excl = excl_new;
    }

    return ((incl > excl) ? incl : excl);
}
int maxSum(vector<int> v)
{
    const int n = v.size();
    int select = v[0];
    int reject = 0;

    for (int i = 1; i < n; i++)
    {
        int temp = max(select, reject);
        select = reject + v[i];
        reject = temp;
    }
    return max(reject, select);
}
int main()
{
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout << FindMaxSum(arr, arr.size()) << " " << maxSum(arr);
}
