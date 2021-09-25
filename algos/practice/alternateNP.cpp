#include <iostream>
#include <vector>
using namespace std;
void Swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void Rearrange(vector<int> v)
{

    int i = 0, j = 1;
    while (i < v.size() - 1 && j < v.size())
    {
        if (v[i] > 0 && i % 2 == 0)
        {
            i++;
            j++;
        }
        else if (v[i] > 0 && i % 2 != 0)
        {
            if (v[j] < 0)
            {
                swap(v[i], v[j]);
            }
            else
            {
                j++;

                continue;
            }
            i++;
            j = i + 1;
        }
        else if (v[i] < 0 && i % 2 != 0)
        {
            i++;
            j = i + 1;
        }
        else if (v[i] < 0 && i % 2 == 0)
        {
            if (v[j] > 0)
            {
                swap(v[i], v[j]);
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
    }
    for (int x : v)
        std::cout << x << " ";
}
int main()
{
    using namespace std;
    vector<int> v = {-1, 2, 3, 4, -5};
    Rearrange(v);

    return 0;
}
