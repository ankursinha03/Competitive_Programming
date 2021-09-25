#include <iostream>
#include <queue>
#include <stdio.h>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<float> Q; //fifo
    Q.push(52.258);
    Q.push(41.229);
    Q.push(85.269);
    Q.push(5.2);
    Q.front() += 100;
    Q.back() += 200;
    std::cout << Q.size();
    std::cout << std::endl;
    while (!Q.empty())
    {
        std::cout << std::endl;
        std::cout << Q.front();

        Q.pop();
    }
#include <queue>

    return 0;
}
