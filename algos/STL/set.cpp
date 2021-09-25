#include <iostream>
#include <set>

int main()
{
    using namespace std;
    set<int> S;
    S.insert(10);
    S.insert(5);
    S.insert(3);
    S.insert(15); //there is some order in the elements;
    S.insert(1);
    S.insert(8);
    S.insert(7);
    S.insert(20); //there is some order in the elements;
    auto itr = lower_bound(S.begin(), S.end(), 13);
    std::cout << *prev(itr);
    // for (auto x : S)
    //     cout << x << " ";
    // if (S.find(3) == S.end())
    //     std::cout << "\n3 not found";
    // else
    //     std::cout << "\nFound 3";
    // if (S.find(1) == S.end())
    //     std::cout << "\nNOT found";
    // auto it = S.find(5);
    // printf("\n");
    // std::cout << "sdlkg ";
    // auto itz = S.find(7);
    // std::cout << *(itz);
    // printf("\n");
    // S.insert(it, 25);
    // printf("\n");
    // for (auto x : S)
    //     cout << x << " ";
    // printf("\n");

    // printf("\n");
    // auto it1 = S.begin();
    // std::cout << *it1;
    // printf("\n");
    // std::cout << *(++S.begin());
    // printf("\n");
    // auto it2 = S.end();
    // std::cout << *--it2;

    // multiset<int> x;
    // x.insert(1);
    // x.insert(7);
    // x.insert(5);
    // x.insert(9);
    // x.insert(1);
    // x.insert(2);
    // x.insert(5);
    // x.insert(1);
    // printf("\n");
    // printf("\n");
    // for (auto p : x)
    //     std::cout << p;
    // auto itsw = x.find(1);
    // x.erase(itsw);
    // printf("\n");
    // for (auto p : x)
    //     std::cout << p;
    // itsw = x.find(9);
    // std::cout << endl
    //           << (itsw == --x.end());
}