#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MAXPRODUCTSUBARRAY(vector<int> v)
{
    int numofNEG = 0;
    int currProduct = 1;
    int ans = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            currProduct *= v[i];
            if (currProduct > ans)
                ans = currProduct;
        }
        else if (v[i] < 0)
        {
            numofNEG = 0;
            for (int k = i + 1; k < n; k++)
            {
                if (v[k] == 0)
                {
                    break;
                }
                if (v[k] < 0)
                    numofNEG++;
            }
            if (numofNEG >= 1 || currProduct < 0)
                currProduct *= v[i];
            if (currProduct > ans)
                ans = currProduct;
        }
        else
        {
            currProduct = 1;
        }
    }
    return ans;
}

int main()
{
    using namespace std;
    vector<int> v = {-20, -40, 0, -2, 0, 500};
    std::cout << MAXPRODUCTSUBARRAY(v);

    return 0;
}
