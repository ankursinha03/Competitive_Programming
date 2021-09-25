#include <iostream>
#include <set>
//they implemented using bst!!
#include <algorithm>

int main()
{
    using namespace std;
    multiset<float> S;

    S.insert(10); //adding elements by value

    S.insert(4);

    int a[] = {5, 4, 7, 2, 1, 7, 8, 9};
    S.insert(a, a + 8); //adding elements based on itr

    std::set<float>::iterator ret = S.insert(14); //upon sucess it return true and the itr of the val addded or else flase and itr of existing val itr

    cout << "\nADDING 14";
    std::cout << endl;

    // if (ret.second == true)
    // {
    //     cout << "\n"
    //          << "element added sucessfully";
    // }
    // else
    // {
    //     cout << "\nelement already exist!";
    // }
    std::cout << endl;

    cout << "\nADDING 5";
    ret = S.insert(5);

    // if (ret.second == true)
    // {
    //     cout << "\n"
    //          << "element added sucessfully";
    // }
    // else
    // {
    //     cout << "\nelement already exist!";
    // }

    cout << endl;

    // auto it = ret.first; //we have tried to insert 5 which already exists so the iterator will point to the persent val of 5

    // S.insert(it, 5.25); //adding 5.25 in the itr position nlog

    // for (float x : S)
    // {
    //     cout << x << " ";
    // }

    cout << endl;

    S.erase(5); //erasing 5 log

    for (float x : S)
    {
        cout << x << " ";
    }
    cout << endl;

    auto pos = S.find(7); //return itr to the val if not found return S.end()

    cout << endl
         << *pos;
    cout << "\n"
         << S.size() << " empty? " << S.empty(); //const
    cout << endl;
    cout << S.count(55) << endl; //finding 55 which doesn't exist so it returns 0
    cout << S.count(1) << endl;  //1 exist it returns 1

    multiset<float> s2 = {5, 4, 9, 15, 66};
    auto respo = s2.equal_range(9); //return the itr of lower and upper bound

    //lower bound =>    x>=element
    //upper bound =>    x>element

    cout << endl
         << *respo.first << " " << *respo.second << endl;
    S.swap(s2);
    for (float x : S)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "\nPRINTING S in reverse! ";
    std::cout << std::endl;

    auto S_ritr = S.rbegin();
    while (S_ritr != S.rend())
    {
        cout << *S_ritr << " ";
        S_ritr++;
    }
    cout << endl;
    for (float x : s2)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << s2.count(7); //count will be varied
    std::cout << std::endl;
    S.clear();
    cout << S.empty();
    return 0;
}
