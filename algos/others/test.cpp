#include <iostream>
#include <string>
using namespace std;

struct stud
{
    int a;
    int b;
};

template <typename T>
void increase(T &a);

template <>
void increase<stud>(stud &s);

template <>
void increase<string>(string &s);

int main()
{

    int n;
    double x;
    char ch;
    string str;
    stud s;

    cin >> n >> x >> ch;
    cin >> s.a >> s.b;
    cin >> str;

    increase(n);
    increase(x);
    increase(str);
    increase(ch);
    increase(s);
    printf("\n");
    cout << n;
    printf("\n");
    cout << x;
    printf("\n");
    cout << ch;
    printf("\n");
    cout << s.a << " " << s.b;
    printf("\n");
    cout << str;

    return 0;
}

template <typename T>
void increase(T &a)
{

    a++;
}

template <>
void increase<string>(string &s)
{

    for (int i = 0; i <= s.size(); i++)
    {
        ++s[i];
    }
}

template <>
void increase<stud>(stud &s)
{

    s.a++;
    s.b++;
}