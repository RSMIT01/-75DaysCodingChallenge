class Solution {
public:
    
    bool solve(string s,vector<string> &B,unordered_map<string,bool> &m)
    {
        if(s.empty())
        {
            return true;
        }
        if(m.find(s)!=m.end())
        {

            return m[s];
        }
        for(int i=0;i<B.size();i++)
        {
            if(B[i]==s.substr(0,B[i].size()))
            {
                
                if(solve(s.substr(B[i].size()),B,m))
                {
                   
                    return m[s]=true;
                }
            }
        }
        
        return  m[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>m;
       return solve(s,wordDict,m);
    }
};