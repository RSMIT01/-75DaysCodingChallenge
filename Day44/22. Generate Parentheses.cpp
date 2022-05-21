class Solution {
public:
    void solve(int n,int open,int close,vector<string> &res,string cur)
    {
        if(open==n && close==n)
        {
            res.push_back(cur);
            return;
        }
        if(open<n)
        {
            solve(n,open+1,close,res,cur+'(');
        }
        if(close<open)
        {
            solve(n,open,close+1,res,cur+')');
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve(n,0,0,res,"");
        return res;
    }
};