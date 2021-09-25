#include <bits/stdc++.h>
using namespace std;

int main()
{
    using namespace std;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    //while creating new 2d vector we can initiallise its value by

    vector<vector<int>> k(10, vector<int>(10));
    auto fn = [&](int &a)
    {
        a++;
    };
    int j = -1;
    sort(v.begin(), v.end(), [&](int &a, int &b)
         { return a * j > b * j; });
    fn(v[0]);
    for (auto x : v)
        std::cout << x << " ";
    return 0;
}