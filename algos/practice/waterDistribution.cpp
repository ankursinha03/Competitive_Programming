#include <iostream>

void vol(int water, int i)
{
    int index = 1;
    while (index <= i)
    {

        if (index == i)
        {
            if (water / index >= 1)
            {
                std::cout << 1;
            }
            else
            {
                std::cout << (float)water / index;
            }
        }
        water = water - index;
        index++;
    }
}
int main()
{
    using namespace std;
    vol(8, 4);

    return 0;
}
