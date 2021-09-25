#include <iostream>
#include <vector>
#include <cmath>

void Swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void heapInsert(std::vector<int> &heap, int k, int i)
{
    heap[i] = k;
    int pos = floor(i / 2);
    while (floor(pos) != 0)
    {
        if (heap[pos] < heap[i])
        {
            Swap(heap[pos], heap[i]);
        }
        pos = pos / 2;
        i = i / 2;
    }
}
void heapDelete(std::vector<int> &heap, int l)
{
    Swap(heap[1], heap[l]);
    int c1, c2;
    int i = 1;
    c1 = 2 * i;
    c2 = 2 * i + 1;

    while (c1 < l || c2 < l)
    {

        if (c1 < l && c2 < l)
        {
            int max, pos;
            if (heap[c1] > heap[c2])
            {
                max = heap[c1];
                pos = c1;
            }
            else
            {
                max = heap[c2];
                pos = c2;
            }
            if (heap[i] < max)
            {
                Swap(heap[i], heap[pos]);
                i = pos;
                c1 = 2 * i;
                c2 = 2 * i + 1;
            }
        }
        else if (c1 < l)
        {
            if (heap[i] < heap[c1])
            {
                Swap(heap[i], heap[c1]);
                i = c1;
                c1 = 2 * i;
                c2 = 2 * i + 1;
            }
            break;
        }
    }
}
void display(std::vector<int> &heap, int k)
{
    printf("\n");
    for (int i = 1; i <= k; i++)
    {
        std::cout << heap[i] << " ";
    }
}
int main()
{
    using namespace std;
    int n;
    cout << "enter n: ";
    cin >> n;
    vector<int> myheap(n + 1);
    int k;

    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        heapInsert(myheap, k, i);
        display(myheap, i);
    }
    int last = n;
    printf("\n");
    for (int i = 1; i <= n; i++)
    {

        heapDelete(myheap, last);

        display(myheap, n);
        last--;
    }

    return 0;
}
