#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
    if (haystack == "")
        return 0;
    std::size_t found = haystack.find(needle);
    return (int)found;
}
int main()
{
    string haystack = "hello", needle = "ll";

    cout << strStr(haystack, needle);

    return 0;
}
