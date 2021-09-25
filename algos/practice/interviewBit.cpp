#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> &A)
{
    auto a = minmax_element(A.begin(), A.end());
    return *a.first + *a.second;
}

int main()
{
    using namespace std;
    vector<int> v;
    return 0;
}