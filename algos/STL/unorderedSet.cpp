#include <iostream>
#include <unordered_set>
//constant insertion and find time

int main()
{
    using namespace std;
    unordered_set<int> uS;
    uS.insert(3);
    uS.insert(5);
    uS.insert(55);
    uS.insert(2);
    uS.insert(2);
    for (auto x : uS)
        std::cout << x; //no order
    auto it = uS.find(2);
    it == uS.end() ? (printf("not")) : printf("found");

    return 0;
}
