#include <bits/stdc++.h>
using namespace std;
void fn()
{
    static int bb = 2;
    bb++;
    std::cout << bb;
}
class papa
{
    string pop;

public:
    papa(string s)
    {
        pop = "dada";
    }
};
class person
{
    string name;

public:
    person(string name)
    {
        this->name = name;
    }

    void virtual display_name()
    {
        std::cout << name << "\n";
    }
    void update(string name)
    {
        this->name = name;
    }
};
class employee : public person, public papa
{

    int id;
    int cost;

public:
    // void display_name() override
    // {
    //     cout << "dsd";
    // }
    employee(string s) : papa("POPO"), person(s)
    {
        id = 10;
        cost = 10;
    }
};
int main()
{
    using namespace std;
    person p1("person 1");
    person p2(p1);
    person p3 = p2;
    static int bb = 5;
    fn();
    cout << bb;
    p1.display_name();
    p2.display_name();
    p3.display_name();
    employee ee("QW");
    ee.display_name();
    int a = 90;
    delete &a;

    unique_ptr<person> ptr(new person("fff"));
    std::cout << "sf";
    ptr->update("HOLA");
    ptr->display_name();
    return 0;
}