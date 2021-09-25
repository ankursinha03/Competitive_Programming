#include <bits/stdc++.h>
using namespace std;

void TOH(stack<int> s, stack<int> h, stack<int> d)
{
    if (s.size() == 1)
    {
        d.push(s.top());
        s.pop();
        return;
    }
    else
    {
    }
}
void towerOfHanoi(int n = 3, char from_rod = 'A', char to_rod = 'C', char aux_rod = 'B')
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
int main()
{
    using namespace std;
    towerOfHanoi();
    stack<int> s({7, 6, 5, 4, 3, 2, 1});
    stack<int> h;
    stack<int> d;
    TOH(s, h, d);
    return 0;
}