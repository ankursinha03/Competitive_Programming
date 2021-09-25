#include <iostream>
#include <vector>
using namespace std;

int MOOR_VTOING_ALGO(vector<int> v) //this algorithm only works if there is one element in the vector that repeats more than n/2
{
    //for getting the element which occurs more than n/2

    int assumedMaxFreqElement = v[0];
    int count = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == assumedMaxFreqElement)
            count++;
        else
            count--;
        if (count < 0)
        {
            count = 0;
            assumedMaxFreqElement = v[i];
        }
    }
    count = 0;
    for (int x : v)
        if (x == assumedMaxFreqElement)
            count++;
    if (count <= v.size() * 0.5) //this step is just to count of the element that occurs most number of time
        return -1;
    return assumedMaxFreqElement;
}

int maxRepElement(vector<int> v) //only work if the elements are less than the numerical val of the array
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        v[v[i] % (int)v.size()] += (int)v.size();
    }
    int max = v[0];
    int ans = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
            ans = i;
        }
    }
    return ans;
}

int main()
{
    using namespace std;
    vector<int> v = {1, 3, 3, 5, 3, 4, 1, 7};
    std::cout << MOOR_VTOING_ALGO(v);
    printf("\n");
    std::cout << maxRepElement(v);

    return 0;
}
