#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solve(vector<int> &A)
{

    int ans = 0;

    vector<int> maxAhead(A.size());
    maxAhead.back() = A.back();
    for (int i = A.size() - 2; i >= 0; i--)
    {
        maxAhead[i] = max(A[i], maxAhead[i + 1]);
    }
    set<int> s;
    s.insert(A[0]);

    for (int i = 1; i < A.size() - 1; i++)
    {

        if (A[i] >= maxAhead[i])
            continue;
        s.insert(A[i]);
        auto it = s.find(A[i]);
        if (it == s.begin())
        {
            continue;
        }
        it--;

        if (*it + A[i] + maxAhead[i] > ans)
            ans = *it + A[i] + maxAhead[i];
    }
    return ans;
}
int main()
{
    using namespace std;
    vector<int> v;
    return 0;
}