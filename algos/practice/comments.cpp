#include <bits/stdc++.h>
using namespace std;

vector<string> removeComments(vector<string> &source)
{
    vector<string> ans;

    bool block = 0;
    string temp = "";
    for (string line : source)
    {
        if (line.length() == 0)
            continue;

        for (int i = 0; i < line.length(); i++)
        {
            if (!block && i + 1 < line.length() && line[i] == '/' && line[i + 1] == '/')
                break;
            else if (!block && i + 1 < line.length() && line[i] == '/' && line[i + 1] == '*')
                block = 1, i++;
            else if (block && i + 1 < line.length() && line[i] == '*' && line[i + 1] == '/')
                block = 0, i++;
            else if (!block)
                temp += line[i];
        }
        if (!temp.empty() and !block)
        {
            ans.push_back(temp);
            temp = "";
        }
    }

    return ans;
}

int main()
{
    using namespace std;
    vector<string> source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
    removeComments(source);
    return 0;
}