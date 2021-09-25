#include <iostream>
#include <vector>
using namespace std;

bool containsPattern(vector<int> &arr, int m, int k)
{
    if (m * k > arr.size())
        return false;
    int count = 0;
    for (int i = 0; i < arr.size() - m; i++)
    {
        if (arr[i] != arr[i + m])
            count = 0;
        else
        {
            count++;
            if (count == (k - 1) * m)
                return true;
        }
    }
    return false;
}
int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}