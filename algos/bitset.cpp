#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> nums)
{
    bitset<1000001> bs;
    for (int i = 0; i < nums.size(); i++)
    {
        bs[nums[i]] = !bs[nums[i]];
    }
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (bs[i])
            ans.push_back(i);
    }
    return ans;
}

vector<int> singleNumberUsingXor(vector<int>v) 
    {
       int totalXor=0;
       
       for(int x:v){
           totalXor^=x;
       }
       
       int k = log2(totalXor&-totalXor)+1;
       int a=0;
       for(int x:v){
           if(x&(1<<(k-1))){
               a^=x;
           }
       }
       int b=totalXor^a;
       if(a<b)
       return {a,b};
       return{b,a};
    }
int main()
{
    using namespace std;
    vector<int> v = {1, 2, 3, 2, 1, 4};
    singleNumber(v);
    return 0;
}