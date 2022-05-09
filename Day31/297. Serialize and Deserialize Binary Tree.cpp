/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void ser(TreeNode* root,string &s)
    {
        if(!root)
        {
            s+="n,";
            return;
        }
        s+=to_string(root->val)+",";
        ser(root->left,s);
        ser(root->right,s);
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string s="";
        ser(root,s);
        return s;
    }

    
     TreeNode* deser(vector<string> &nodes,int &idx)
     {
         if(nodes[idx]=="n")
         {
             idx++;
             return NULL;
         }
         TreeNode* root=new TreeNode(stoi(nodes[idx++]));
         root->left=deser(nodes,idx);
         root->right=deser(nodes,idx);
         return root;
     }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       vector<string>nodes;
        string cur="";
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==',')
            {
                nodes.push_back(cur);
                cur="";
                continue;
            }
            cur+=data[i];
        }
       int idx=0;
       return deser(nodes,idx);      
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));