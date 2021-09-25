#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    int a;
};
class B : public virtual A
{
public:
    int b;
};
class C : public virtual A
{
public:
    int c;
};
class D : public virtual B, public virtual C
{
public:
    int d;
    ~D()
    {
        std::cout << "done";
    }
};
int main()
{

    D obj;
    std::cout << sizeof(obj);
    obj.B::a = 10;
    //obj.C::a = 5;
    std::cout << obj.a;
    string k = "6589-";
    try
    {
        std::cout << stoi("*85265odfghjkl8--+");
    }
    catch (exception r)
    {
        std::cout << "fail";
    }
    return 0;
}