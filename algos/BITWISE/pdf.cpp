#include <bits/stdc++.h>
using namespace std;

void R_rotate(int &n, int pos)
{
    n = (n >> pos) | (n << (32 - pos));
}
void L_rotate(int &n, int pos)
{
    n = (n << pos) | (n >> (32 - pos));
}

void absd(int &n)
{
    int k = ~n + 1;
    n = k;
}
int main()
{
    using namespace std;
    int d;
    // d = 16;
    // R_rotate(d, 2);
    // std::cout << d;
    // printf("\n");
    // L_rotate(d, 2);
    // std::cout << d;

    d = -55;
    absd(d);
    std::cout << d;
    return 0;
}