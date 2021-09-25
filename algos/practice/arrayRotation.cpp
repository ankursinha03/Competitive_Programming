#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void Rotate(vector<int> &v, int k)
{
    int t;
    while (k--)
    {
        t = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            v[i - 1] = v[i];
        }
        v.back() = t;
    }
}
int LargestSubARRAY(vector<int> &v)
{
    int i = 0, j = 0;
    unordered_map<int, int> map;
    map[0] = 0;
    map[1] = 0;
    int size = 0;
    while (j < v.size())
    {
        map[v[j]]++;
        if (map[0] != map[1])
        {

            j++;

            continue;
        }
        else if (map[0] == map[1])
        {
            if (j - i + 1 > size)
                size = j - i + 1;
            j++;
            if (j == v.size())
                break;
            if (v[j] == v[i])
            {
                i++;
                map[v[j]]--;
            }
        }
    }
    return size;
}
int main()
{
    using namespace std;
    vector<int> v = {0, 0, 1, 1, 0};
    // Rotate(v, 2);
    // for (int x : v)
    //     std::cout << x << " ";
    std::cout << LargestSubARRAY(v);
    return 0;
}
