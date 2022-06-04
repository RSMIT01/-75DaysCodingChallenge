class Solution {
public:
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
    bool getend()
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

    bool insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if(word[i]=='/')
            {
                continue;
            }
            if (!node->containskey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            if(word[i+1]=='/' && node->end)
            {
                return false;
            }
        }
        node->setend();
        return true;
    }


    
};
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans;
        Trie trie;
        for(int i=0;i<folder.size();i++)
        {
            if(trie.insert(folder[i]))
            {
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};