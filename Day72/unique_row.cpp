#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[2];
    bool end = false;

    bool containskey(int val)
    {
        return (links[val] != NULL);
    }

    void put(int val, Node *node)
    {
        links[val] = node;
    }

    Node *get(int val)
    {
        return links[val];
    }

    void setend()
    {
        end = true;
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

    void insert(vector<int> &row)
    {
        Node *node = root;
        for (int i = 0; i < row.size(); i++)
        {
            if (!node->containskey(row[i]))
            {
                node->put(row[i], new Node());
            }
            node = node->get(row[i]);
        }
        node->setend();
    }
    void find_uniq(Node *node, vector<vector<int>> &ans, vector<int> &uniq)
    {
        if (node == NULL)
        {
            return;
        }
        if (node->isend())
        {
            ans.push_back(uniq);
        }
        for (int i = 0; i < 2; i++)
        {

            if (node->containskey(i))
            {
                uniq.push_back(i);
                find_uniq(node->get(i), ans, uniq);
                uniq.pop_back();
            }
        }
    }
    void printrow()
    {
        vector<int> uniq;
        vector<vector<int>> ans;
        find_uniq(root, ans, uniq);
        for (auto it : ans)
        {
            for (auto i : it)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Trie trie;
    vector<vector<int>> arr = {{0, 1, 0, 0, 1}, {1, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {1, 0, 1, 0, 0}};
    for (int i = 0; i < arr.size(); i++)
    {
        trie.insert(arr[i]);
    }
    trie.printrow();

    return 0;
}