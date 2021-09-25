#include <bits/stdc++.h>
using namespace std;

int sqrt(int A)
{
    int ans = 0;
    int prevans;
    float s = 1;
    float e = A / 2;
    if (A == 0)
        return 0;
    if (A == 1 || A == 2 || A == 3)
        return 1;
    float m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (m * m == A)
            return floor(m);
        if (m * m > A)
        {
            e = m;
        }
        else
        {
            s = m;
        }
        if (floor(m) == floor(s) || floor(m) == floor(e))
            return floor(m);
    }
    return e;
}
int main()
{
    using namespace std;
    sqrt(409293341);
    return 0;
}