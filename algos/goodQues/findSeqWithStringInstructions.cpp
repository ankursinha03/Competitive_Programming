#include <iostream>
#include <vector>
#include <string>
// Given a positive integer n and a string s consisting only of letters D or I,
// you have to find any permutation of first n positive integer that satisfy the given input string.

// D means the next number is smaller, while I means the next number is greater.

using namespace std;
vector<int> Seq(string S)
{
    int n = S.length();
    vector<int> ans(n + 1);
    int a = 1;
    int b = n + 1;
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] = (S[i] == 'D') ? b-- : a++; //after allocation the val is changed!!
    }
    return ans;
}
int main()
{
    using namespace std;
    string s = "DDDI";
    vector<int> x;
    x = Seq(s);
    for (int a : x)
        std::cout << a << " ";

    return 0;
}
