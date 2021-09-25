#include <iostream>
#include <vector>
void LRsum(std::vector<int> v)
{
    int Lsum = 0;
    int Rsum = 0;
    int i = -1, j = (int)v.size();
    while (i < j)
    {

        if (Lsum < Rsum)
        {
            i++;
            Lsum += v[i];
        }
        else if (Lsum == Rsum)
        {
            i++;
            j--;
            Lsum += v[i];
            Rsum += v[j];
        }
        else if (Lsum > Rsum)
        {
            j--;
            Rsum += v[j];
        }
    }
    if (i == j && Lsum == Rsum)
        std::cout << i;
    else
        std::cout << -1;
}
int main()
{
    using namespace std;
    vector<int> v = {-1, -1, -1, -1, -1, 0};
    LRsum(v);

    return 0;
}
