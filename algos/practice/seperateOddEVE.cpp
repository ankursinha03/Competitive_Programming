#include <iostream>
#include <vector>
using namespace std;
void Distribute(float x, int R, int C)
{

    std::vector<float> g(R * 0.5 * (R + 1));

    int index = 0;
    g[0] = x;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= i; ++index, j++)
        {
            x = g[index];
            g[index] = (x >= 1.0) ? 1.0 : x;
            x = (x >= 1.0) ? (x - 1.0) : 0;
            g[index + i] += x / 2;
            g[index + i + 1] += x / 2;
        }
    }

    for (int i = 0; i < (int)g.size(); i++)
    {
        cout << (float)g[i] << " ";
    }
}
int main()
{
    int i = 2, j = 2;
    float X = 2.0;

    Distribute(6, 4, 2);
    printf("\n");

    return 0;
}