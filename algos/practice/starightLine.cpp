#include <iostream>
#include <vector>
using namespace std;
bool checkStraightLine(vector<vector<int>> &v)
{
    if (v.size() == 2)
        return true;
    if (v[1][0] - v[0][0] == 0)
    {
        for (int i = 2; i < v.size(); i++)
        {
            if (v[i][0] != v[0][0])
                return false;
        }
        return false;
    }
    float slope = (float)(v[1][1] - v[0][1]) / (v[1][0] - v[0][0]);
    for (int i = 2; i < v.size(); i++)
    {
        float dy = v[i][1] - v[0][1];
        float dx = v[i][0] - v[0][0];
        float dz;
        dz = dy / dx;
        if (dz != slope)
            return false;
    }
    return true;
}

int main()
{
    using namespace std;

    vector<vector<int>> v = {{0, 0}, {0, 1}, {0, -1}};

    std::cout << checkStraightLine(v);
    return 0;
}
