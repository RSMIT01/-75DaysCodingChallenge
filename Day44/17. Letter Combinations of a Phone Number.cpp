class Solution {
public:
    void solve(string p,string up,vector<string>&ans, vector<string>key)
    {
        if(up.empty())
        {
            ans.push_back(p);
            return;
        }
        int c=up[0]-'0';
     
       for(int i=0;i<key[c-2].size();i++)
       {
             solve(p+key[c-2][i],up.substr(1),ans,key);
       }
      
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty())
        {
            return ans;
        }
        string p="";
        vector<string>key={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(p,digits,ans,key);
        return ans;
    }
};