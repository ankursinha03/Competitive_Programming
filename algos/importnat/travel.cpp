#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem
{
    map<pair<string, string>, pair<int, int>> FromTo;
    unordered_map<int, pair<string, int>> board;

public:
    UndergroundSystem()
    {
        //wjnbfwqh
    }

    void checkIn(int id, string stationName, int t)
    {
        board.insert({id, {stationName, t}});
    }

    void checkOut(int id, string stationName, int t)
    {
        auto it = board.find(id);

        string start = (it->second).first;
        int timeTaken = t - (it->second).second;
        auto itr = FromTo.find({start, stationName});
        if (itr == FromTo.end())
        {
            FromTo.insert({{start, stationName}, {timeTaken, 1}});
        }
        else
        {
            int count = itr->second.second;
            count++;
            int time = itr->second.first;
            FromTo.erase(itr);
            FromTo.insert({{start, stationName}, {time + timeTaken, count}});
        }
        board.erase(it);
    }

    double getAverageTime(string startStation, string endStation)
    {
        double ans;
        auto it = FromTo.find({startStation, endStation});
        int time = it->second.first;
        int c = it->second.second;
        ans = (double)time / c;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
int main()
{
    using namespace std;
    UndergroundSystem us;
    us.checkIn(45, "Leyton", 3);
    us.checkIn(32, "Paradise", 8);
    us.checkIn(27, "Leyton", 10);
    us.checkOut(45, "Waterloo", 15);
    us.checkOut(27, "Waterloo", 20);
    us.checkOut(32, "Cambridge", 22);
    std::cout << us.getAverageTime("Paradise", "Cambridge");
    us.getAverageTime("Leyton", "Waterloo");

    us.checkIn(10, "Leyton", 24);
    us.getAverageTime("Leyton", "Waterloo");
    us.checkOut(10, "Waterloo", 38);
    us.getAverageTime("Leyton", "Waterloo");
    return 0;
}