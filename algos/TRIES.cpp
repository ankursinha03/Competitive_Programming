#include <bits/stdc++.h>
using namespace std;

struct Node
{
    map<char, Node> children;
    bool isWord = false;
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node;
    }
    void insert(string s)
    {
        Node *n = root;
        for (int i = 0; i < s.length(); i++)
        {

            if (n->children.find(s[i]) == n->children.end())
            {
                Node a;
                if (i == s.length() - 1)
                {
                    a.isWord = true;
                }
                n->children[s[i]] = a;
                n = &n->children[s[i]];
            }
            else
            {
                n = &n->children[s[i]];
                if (i == s.length() - 1)
                {
                    n->isWord = true;
                }
            }
        }
    }
    bool find(string s)
    {
        Node *n = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (n->children.find(s[i]) == n->children.end())
            {
                return false;
            }
            n = &n->children[s[i]];
            if (i == s.length() - 1)
            {
                if (n->isWord)
                {
                    return true;
                }
                return false;
            }
        }
        return false;
    }
};

int main()
{
    using namespace std;
    Trie trie;
    trie.insert("abcd");
    trie.insert("baba");
    trie.insert("ab");
    std::cout << trie.find("ab");
    std::cout << trie.find("abc");
    std::cout << trie.find("abcd");
    std::cout << trie.find("ba");
    std::cout << trie.find("baba");
    std::cout << trie.find("abcde");
    return 0;
}