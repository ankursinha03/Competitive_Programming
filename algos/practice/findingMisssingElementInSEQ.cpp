#include <iostream>
#include <vector>

long MISSING(std::vector<int> a)
{
    long sum = 0;
    for (auto x : a)
    {
        sum += x;
    }
    return ((int)a.size() + 2) * ((int)a.size() + 1) * 0.5 - sum;
}

int main()
{
    using namespace std;
    vector<int> k = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    cout << MISSING(k);

    return 0;
}
