#include <bits/stdc++.h>
using namespace std;

bool isHappy(int n)
{
    unordered_set<int> st;
    while (n != 1)
    {
        if (n == 0)
            return 0;
        int k = log10(n);
        vector<int> d;
        for (int i = k; i >= 0; i--)
        {
            int fac = pow(10, i);
            d.push_back(n / fac);
            n = n % fac;
        }
        int sum = 0;
        for (int x : d)
        {
            sum += x * x;
        }

        if (st.find(sum) == st.end())
        {
            st.insert(sum);
            n = sum;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    using namespace std;
    std::cout << isHappy(19);
    return 0;
}