#include <bits/stdc++.h>
using namespace std;

void printSubSeq(string s, string ans)
{
    if (s.empty())
    {
        std::cout
            << ans << " ";
    }
    else
    {
        string f(s.begin(), s.begin() + 1);
        string l(s.begin() + 1, s.end());
        printSubSeq(l, ans + f);
        printSubSeq(l, ans);
    }
}
void print1toN(int N)
{
    if (N == 1)
    {
        std::cout << 1 << " ";
    }
    else
    {
        int n = N;
        print1toN(--n);
        std::cout << N << " ";
    }
}
void printNto1(int N)
{
    if (N == 1)
    {
        std::cout << 1 << " ";
    }
    else
    {

        std::cout << N << " ";
        printNto1(N - 1);
    }
}
stack<int> sort(stack<int> s)
{
    if (s.size() == 1)
    {
        return s;
    }
    else
    {
        int t = s.top();
        s.pop();
        s = sort(s);
        if (s.top() <= t)
        {
            s.push(t);
        }
        else
        {
            stack<int> buff;
            while (!s.empty() && s.top() > t)
            {
                buff.push(s.top());
                s.pop();
            }
            s.push(t);
            while (!buff.empty())
            {
                s.push(buff.top());
                buff.pop();
            }
        }
    }
    return s;
}
void insert(stack<int> &st, int n)
{
    if (st.empty())
    {
        st.push(n);
    }
    else
    {
        int nn = st.top();
        st.pop();
        insert(st, n);
        st.push(nn);
    }
}
stack<int> reverseIT(stack<int> s)
{
    if (s.size() == 1)
    {
        return s;
    }
    else
    {
        int t = s.top();
        s.pop();
        s = reverseIT(s);
        insert(s, t);
        return s;
    }
}

void doit(deque<int> q, deque<int> r, vector<vector<int>> &ans)
{
    if (r.empty())
    {
        vector<int> t(q.begin(), q.end());
        ans.push_back(t);
    }
    else
    {

        q.push_back(r.front());
        r.pop_front();
        doit(q, r, ans);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    if (nums.size() == 1)
    {
        ans.push_back(nums);
        return ans;
    }
    else
    {
        deque<int> q;
        deque<int> r(nums.begin(), nums.end());

        doit(q, r, ans);
    }
    return ans;
}
void printCasePermute(string input, string output = "")
{
    if (input.empty())
    {
        std::cout << output << " ";
    }
    else
    {
        //without
        char w = input[0];
        if (isalpha(w))
        {
            string oP = output;
            oP += w;
            string iP(input.begin() + 1, input.end());
            printCasePermute(iP, oP);

            w = input[0];
            w = w ^ 32;
            string oP2 = output;
            oP2 += w;
            printCasePermute(iP, oP2);
        }
        else
        {
            string oP = output;
            oP += w;
            string iP(input.begin() + 1, input.end());
            printCasePermute(iP, oP);
        }
    }
}
void printBalPARA(int o, int c, string out)
{
    if (c < 0 || o < 0)
        return;
    if (o == 0 && c == 0)
    {
        std::cout << out << " ";
    }
    else
    {
        if (o == c)
        {
            out += '(';
            o--;
            printBalPARA(o, c, out);
        }
        else
        {

            o--;
            string onn = out;
            onn += "(";
            printBalPARA(o, c, onn);
            o++;
            c--;
            string on = out;
            on += ")";
            printBalPARA(o, c, on);
        }
    }
}

void seqBinary(int n, int n0, int n1, string s, vector<string> &ans)
{
    if (n0 + n1 == n)
    {
        ans.push_back(s);
        return;
    }
    if (n < 0 || n0 > n || n1 > n)
    {
        return;
    }
    else
    {
        if (!(n1 >= n0 + 1))
        {
            n1++;
            s += "1";
            seqBinary(n, n0, n1, s, ans);
        }
        else
        {
            n0++;
            string k = s;
            k += "0";
            seqBinary(n, n0, n1, k, ans);

            n0--;
            string e = s;
            e += "1";
            n1++;
            seqBinary(n, n0, n1, e, ans);
        }
    }
}

vector<string> NBitBinary(int N)
{
    vector<string> ans;
    seqBinary(N, 0, 0, "", ans);
}

int main()
{
    using namespace std;

    NBitBinary(3);
    printf("\n");

    printBalPARA(3, 3, "");
    printf("\n");
    printCasePermute("AbC");
    printf("\n");
    printCasePermute("Ab1C");

    // printf("\n");
    // deque<int> f = {1, 2, 3, 4, 65, 564, 6, 1};
    // vector<int> t{1, 2, 3};
    // permute(t);
    // // print1toN(7);
    // // printf("\n");
    // // printNto1(7);
    // // printf("\n");
    // printSubSeq("ABCD", "");
    // stack<int> s;
    // s.push(7);
    // s.push(17);
    // s.push(27);
    // s.push(-7);
    // s.push(76);
    // s.push(87);
    // s.push(0);
    // s.push(2);
    // s.push(1);
    // s.push(8);
    // s = sort(s);
    // s = reverseIT(s);

    return 0;
}