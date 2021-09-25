#include <bits/stdc++.h>

int main()
{
    using namespace std;
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        printf("\n");
        std::cout << rand() % 10;
    }

    for (int i = 0; i < 10; i++)
    {
        int k = rand() % 11;
        cout << k << " ";
    }

    return 0;
}
