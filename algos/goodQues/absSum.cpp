#include <iostream>
#include <vector>
//absolute diff
//|a[i]-a[j]|+|i-j|
//this can broken down into different + or -
//case  1 (a[i]+i)
//case 2 (a[i]-i)

int MAXDIFF(std::vector<int> v)
{
    int MAX1, MAX2, MIN2, MIN1;
    MAX1 = MAX2 = INT_MIN;
    MIN1 = MIN2 = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        MAX1 = (MAX1 < v[i] + i) ? v[i] + i : MAX1;
        MIN1 = (MIN1 > v[i] + i) ? v[i] + i : MIN1;
        MAX2 = (MAX2 < v[i] - i) ? v[i] - i : MAX2;
        MIN2 = (MIN2 > v[i] - i) ? v[i] - i : MIN2;
    }
    return std::max(MAX1 - MIN1, MAX2 - MIN2);
}
int main()
{
    using namespace std;
    vector<int> v = {1, 3, -1};
    cout << MAXDIFF(v);

    return 0;
}
