#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool end = false;

    bool containskey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setend()
    {
        end = true;
    }
    void rmvend()
    {
        end=false;
    }
    bool isend()
    {
        return end;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containskey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setend();
    }

    bool search(string s)
    {
        Node *node = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (!node->containskey(s[i]))
            {
                return false;
            }
            node = node->get(s[i]);
        }
        return (node->end);
    }

    void remove(string s)
    {
        Node *node=root;
         for (int i = 0; i < s.length(); i++)
        {
            node = node->get(s[i]);
        }
        node->rmvend();
        
    }

};

int main()
{
    Trie trie;
    trie.insert("hello");
    trie.insert("hell");
    trie.remove("hello");
    if (trie.search("hello"))
    {
        cout << "found";
    }
    else
    {
        cout<<"not found";
    }
    return 0;
}