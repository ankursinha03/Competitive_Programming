#include <bits/stdc++.h>
using namespace std;

string decodeString(string s)
{
    stack<string> st;
    const int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            string t = "";
            while (isdigit(s[i]))
            {
                t = t + s[i];
                i++;
            }
            st.push(t);
            i--;
        }
        else if (s[i] == '[')
        {
            string t = "";
            t += (char)s[i];
            st.push(t);
        }
        else if (isalpha(s[i]))
        {
            string temp = "";
            while (isalpha(s[i]))
            {
                temp += s[i];
                i++;
                if (i == n)
                    break;
            }
            i--;
            st.push(temp);
        }
        else
        {
            string temp = "";

            while (st.top() != "[")
            {
                string tempo = st.top();
                reverse(tempo.begin(), tempo.end());
                temp += tempo;
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            st.pop();
            int k = stoi(st.top()) - '0';
            cout << k << " " << st.top() << "\n";
            st.pop();
            string t = "";
            for (int j = 1; j <= k; j++)
            {
                t += temp;
            }
            st.push(t);
        }
    }
    string ans = "";

    while (!st.empty())
    {
        string temp = st.top();
        reverse(temp.begin(), temp.end());
        ans += temp;
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    using namespace std;
    decodeString("100[leetcode]");
    return 0;
}