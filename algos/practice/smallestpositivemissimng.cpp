#include <iostream>
#include <vector>
using namespace std;
void maxDiff(vector<int> v)
{
    int minVisted;
    int maxdiff = 0;
    minVisted = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < minVisted)
            minVisted = v[i];
        if (v[i] - minVisted > maxdiff)
            maxdiff = v[i] - minVisted;
    }
    cout << maxdiff;
}

int main()
{
    using namespace std;
    vector<int> v = {7, 9, 5, 6, 3, 2};
    maxDiff(v);
    return 0;
}
