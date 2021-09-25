#include <iostream>
#include <map>

struct comp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    using namespace std;

    map<int, char, comp> maped;
    maped[5] = 'a';
    maped[12] = 'b';
    maped.insert(pair<int, char>(10, 'k'));

    for (pair<int, char> p : maped)
    {
        std::cout << p.first << " " << p.second << " ";
    }
    std::cout << std::endl;

    auto it = maped.find(12);

    std::cout << it->first << " " << it->second;
    std::cout << std::endl;

    maped.erase(5);
    cout << "edfgh " << maped[5];
    return 0;
}
