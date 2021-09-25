#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B)
{
    int ans = INT_MIN;
    int n = A.size();
    // for(int p=0;p<=B;p++){
    //     int a=0,b=0;
    //     for(int i=0;i<p;i++){
    //         a+=A[i];
    //     }
    //     for(int i=n-(B-p);i<n;i++){
    //         b+=A[i];
    //     }
    //     if(ans<a+b){
    //         ans=a+b;
    //     }
    // }
    int p1 = 0;
    for (int i = 0; i < B; i++)
    {
        p1 += A[i];
    }

    int k = B - 1;
    int j = n - 1;
    while (k != 0)
    {
        //cout<<k<<" ";
        ans = max(ans, p1);
        p1 -= A[k];
        p1 += A[j];
        k--;
        j++;
    }

    ans = max(ans, p1);
    return ans;
}
int main()
{
    using namespace std;
    vector<int> v = {-533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701, 35, 894, -297, 811, 322, -667, 673, -336, 141, 711, -747, -132, 547, 644, -338, -243, -963, -141, -277, 741, 529, -222, -684, 35};
    std::cout << solve(v, 48);
    return 0;
}