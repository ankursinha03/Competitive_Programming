#include <iostream>
#include <vector>

using namespace std;

void twoELEMENTS(vector<int> v)
{
    int a = 0, b = 0;
    int Xor = 0;
    for (auto x : v)
    {
        Xor ^= x;
    }
    std::cout << Xor;
    printf("\n");
    int twoComponent = Xor & ~(Xor - 1);
    cout << twoComponent;
    for (auto x : v)
    {
        if (twoComponent & x)
        {
            a ^= x;
        }
        else
        {
            b ^= x;
        }
    }
    printf("\n");
    std::cout << a << " " << b;
}

int main()
{
    using namespace std;
    vector<int> k = {3, 4, 4, 5, 6, 6};
    twoELEMENTS(k);

    return 0;
}
