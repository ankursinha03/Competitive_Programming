#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    list<pair<int, int>> ddl;
    map<int, list<pair<int, int>>::iterator> mp;
    int maxSize;
    int curr;

public:
    LRUCache(int capacity)
    {
        maxSize = capacity;
        curr = 0;
    }

    int get(int key)
    {
        auto it = mp.find(key);
        if (it == mp.end())
            return -1;
        int ans = it->second->second;
        ddl.erase(it->second);
        ddl.push_front({key, ans});
        mp.erase(key);
        mp.insert({key, ddl.begin()});
        return ans;
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end())
        {
            if (curr < maxSize)
            {
                ddl.push_front({key, value});
                mp.insert({key, ddl.begin()});
                curr++;
            }
            else
            {
                auto bk = ddl.back();
                ddl.pop_back();
                mp.erase(bk.first);
                ddl.push_front({key, value});
                mp.insert({key, ddl.begin()});
            }
        }
        else
        {
            auto it = mp.find(key);
            ddl.erase(it->second);
            ddl.push_front({key, value});
            mp.erase(key);
            mp.insert({key, ddl.begin()});
        }
    }
};
int main()
{
    using namespace std;
    // LRUCache lru(2);
    // lru.put(1, 1);
    // lru.put(2, 2);
    // std::cout << lru.get(1);
    // lru.put(3, 3);
    freq_t
        // std::cout << " " << lru.get(2);
        // lru.put(4, 4);
        // std::cout << " " << lru.get(1);
        // std::cout << " " << lru.get(3);
        // std::cout << " " << lru.get(4);
        LRUCache lru(2);
    lru.put(2, 1);
    lru.put(2, 2);
    std::cout << lru.get(2);
    lru.put(1, 1);
    //std::cout << " " << lru.get(2);
    lru.put(4, 1);
    std::cout << " " << lru.get(2);
    //std::cout << " " << lru.get(3);
    //std::cout << " " << lru.get(4);
    return 0;
}