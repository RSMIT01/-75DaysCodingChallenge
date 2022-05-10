class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1,string &s2,int m,int n)
    {
        if(m==-1 || n==-1)
        {
          return 0;
        }
        else if(dp[m][n]!=-1)
        {
           return dp[m][n];
        }
        else if(s1[m]==s2[n])
        {
            return dp[m][n]=1+solve(s1,s2,m-1,n-1);
        }
        else
        {
           return dp[m][n]=max(solve(s1,s2,m,n-1),solve(s1,s2,m-1,n));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp[text1.size()+1][text2.size()+1];
        memset(dp,-1,sizeof(dp));
        return solve(text1,text2,text1.size()-1,text2.size()-1);
    }
};