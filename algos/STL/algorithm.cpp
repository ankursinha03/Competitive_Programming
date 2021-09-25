#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    using namespace std;
    string s = "ah";
    string f = "az";
    std::cout << lexicographical_compare(s.begin(), s.end(), f.begin(), f.end());
    printf("\n");
    vector<int> v = {7, 8, 5, 8, 44, 22, 1};
    printf("\n");
    printf("\n");
    std::cout << v.end()[-2];
    printf("\n");
    printf("\n");
    next_permutation(v.begin(), v.end());
    for (int x : v)
        std::cout << x << " ";
    printf("\n");
    prev_permutation(v.begin(), v.end());
    for (int x : v)
        std::cout << x << " ";

    printf("\n");
    printf("\n");

    v = {1, 3, 2};
    do
    {
        for (auto x : v)
        {
            std::cout << x << " ";
        }
        printf("\n");

    } while (next_permutation(v.begin(), v.end()));
    printf("\n");
    printf("\n");
    prev_permutation(v.begin(), v.end());
    do
    {
        for (auto x : v)
        {
            std::cout << x << " ";
        }
        printf("\n");

    } while (prev_permutation(v.begin(), v.end()));
    for (auto x : v)
    {
        std::cout << x << " ";
    }
    printf("\n");

    s = "AB BanaNA 123";
    for (char c : s)
    {
        if (isalpha(c))
        {
            std::cout << " alpha " << c;
        }
        printf("\n");
        if (isdigit(c))
        {
            std::cout << " digit " << c;
        }
        printf("\n");
        if (isupper(c))
        {
            std::cout << " upper " << c;
        }
    }
    return 0;
}