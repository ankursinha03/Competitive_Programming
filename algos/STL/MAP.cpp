#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    using namespace std;
    map<int, float> Omap; //Maps are typically implemented as binary search trees.
                          //the first parameter is the key
    Omap.insert({1, 7.25});
    pair<int, float> p;
    p.first = 2;
    p.second = 8.75;
    Omap.insert(p); //insert O(logn)
    p.first = 7;
    p.second = 9.256;
    Omap.insert(p);
    auto it = Omap.find(1); //logn
    std::cout << it->first << " " << it->second;
    for (auto x : Omap)
        std::cout << x.first << " " << x.second << endl;

    unordered_map<int, float> UoMap; //organized into buckets depending on their hash values
                                     //to allow for fast access to individual elements directly by their key values (with a constant average time complexity on average).

    UoMap.insert({{5, 2.25}, {65, 2.2564}});
    p.first = 2;
    p.second = 8.75;
    UoMap.insert(p); //avg case constant worst: linear o(n) there might be a rehash : A rehash is the reconstruction of the hash table
    p.first = 7;
    p.second = 9.256;
    UoMap.insert(p);        //Each element is inserted only if its key is not equivalent to the key of any other element already in the container (keys in an unordered_map are unique).
    auto i = UoMap.find(5); // avg: O(1)     worst: O(k) k is container size
    printf("\n");
    printf("\n");
    std::cout << i->second;
    for (auto x : UoMap)
        std::cout << x.first << " " << x.second << endl;
    std::cout << "\n TEST";
    UoMap[2]++;
    printf("\n");

    UoMap[10]++;
    for (auto x : UoMap)
        std::cout << x.first << " " << x.second << endl;
    //coming to multimap in both map and unordered map the key(the first para) must be unique
    //but if we have to store val which can have duplicate keys

    multimap<int, float> MM; //Multimaps are typically implemented as binary search trees
    //slower than unordered_multimap
    printf("\n");
    printf("\n");
    MM.insert({5, 6.25});
    p.first = 7;
    p.second = 10.23;
    MM.insert(p);
    p.first = 7;
    p.second = 8.93;
    MM.insert(p);
    p.first = 7;
    p.second = 18.9123;
    MM.insert(p);
    MM.insert({17, 9.99});
    for (auto x : MM)
        std::cout << x.first << " " << x.second << endl;
    printf("\n");
    auto itR = MM.find(7);
    std::cout << itR->first << " " << itR->second; //this function returns an iterator to a single element to the first apperared

    //using equal range to find all elements of the same key

    auto ERitr = MM.equal_range(7); //The function returns a pair, whose member first is the lower bound of the range (the same as lower_bound),
    // and second is the upper bound (the same as upper_bound).

    //equal_range is available in map also but that will contain only one element so basically useless

    printf("\n");
    for (auto i = ERitr.first; i != ERitr.second; i++)
    {
        cout << i->first << " " << i->second << endl;
    }

    //unordered_multimap
    unordered_multimap<int, float> UoMM;

    //Internally unordered_multimap are not sorted  but organized into buckets depending on their hash values
    //to allow for fast access to individual elements directly by their key values (with a constant average time complexity on average).

    //Elements with equivalent keys are grouped together in the same bucket and in such a way that an iterator can iterate through all of them.

    UoMM.insert({1, 0.25});
    p.first = 9;
    p.second = 6.3254;
    UoMM.insert(p);
    p.first = 9;
    p.second = 59.54;
    UoMM.insert(p); //O(1) when single element is to be inserted O(l) when multiple elements with same key is to be stored l: similar key
    p.first = 91;
    p.second = 59.54;
    UoMM.insert(p);
    p.first = 9;
    p.second = 78.54;
    UoMM.insert(p);
    printf("\n");
    printf("\n");
    for (auto x : UoMM)
        std::cout << x.first << " " << x.second << endl;
    auto UMMitr = UoMM.find(1); //constant or liner time complexity
    std::cout << endl
              << UMMitr->first << " " << UMMitr->second;
    printf("\n");
    printf("\n");
    auto UOMM_ER = UoMM.equal_range(9);
    for (auto i = UOMM_ER.first; i != UOMM_ER.second; i++)
    {
        std::cout << i->first << " " << i->second << endl;
    }

    return 0;
}
