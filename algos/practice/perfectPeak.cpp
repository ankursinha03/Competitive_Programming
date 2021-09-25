#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int perfectPeak(vector<int> &A)
{
    int n = A.size();
    vector<int> left(n);
    vector<int> right(n);
    left[0] = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > left[i - 1])
            left[i] = A[i];
        else
            left[i] = left[i - 1];
    }
    right[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < right[i + 1])
            right[i] = A[i];
        else
            right[i] = right[i + 1];
    }
    for (int j = 1; j < n - 1; j++)
    {
        if (A[j] == left[j] && A[j] < right[j + 1])
            return 1;
    }
    return 0;
}
int main()
{
    using namespace std;
    vector<int> v = {9895, 30334, 17674, 23812, 20038, 25668, 6869, 1870, 4665, 27645, 7712, 17036, 31323, 8724, 28254, 28704, 26300, 25548, 15142, 12860, 19913, 32663, 32758};
    std::cout << perfectPeak(v);
    return 0;
}