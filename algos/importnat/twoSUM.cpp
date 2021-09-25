#include <bits/stdc++.h>

using namespace std;
int Pair(vector<int> A, int B)
{
    unordered_map<int, int> s;
    for (auto x : A)
        s[x]++;

    for (int x : A)
    {
        int d = x - B;

        if (s.find(d) != s.end())
        {
            if (s[d] == 1)
                continue;
            return 1;
        }
    }
    return 0;
}

void bf(vector<int> a, int k)
{
    for (int x : a)
    {
        for (int y : a)
        {
            if (x - y == k)
            {
                std::cout << x << " " << y;
                return;
            }
        }
    }
    std::cout << 0;
}

int main()
{
    using namespace std;

    vector<int> k = {478, 358, -38, -536, 705};
    cout << Pair(k, 320);
    printf("\n");
    bf(k, -466);
    return 0;
}
