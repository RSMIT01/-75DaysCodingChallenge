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

    string find_longest(string s)
    {
        string ans="";
        Node *node = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (!node->containskey(s[i]))
            {
                return ans;
            }
            ans+=s[i];
            node = node->get(s[i]);
        }
        return ans;
    }

    
};

int main()
{
    Trie trie;
  trie.insert("cater");
  trie.insert("cat");

    cout<<trie.find_longest("caterer");
    return 0;
}