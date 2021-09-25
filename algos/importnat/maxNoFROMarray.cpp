#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
using namespace std;

bool CMP(string a, string b)
{
    return a + b > b + a;
}
string MaxElement(vector<int> v)
{
    vector<string> Snum;
    for (int x : v)
        Snum.push_back(to_string(x));
    sort(Snum.begin(), Snum.end(), CMP);
    string s = "";
    for (auto k : Snum)
        s += k;
    return s;
}
int main()
{
    using namespace std;
    vector<int> arr = {12, 55, 90, 9, 65, 8, 1, 15, 10};
    cout << MaxElement(arr);

    return 0;
}
