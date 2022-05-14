class Solution {
public:
    // Catalan Number Series: Cn = (2n)! / ((n + 1)! * n!)
    // https://leetcode.com/problems/unique-binary-search-trees/discuss/2032112/C%2B%2B-%3A-Using-Catalan-Series
    long solve(int r)
    {
        int n=r<<1;
        long ans=1;
        for(int i=0;i<r;i++)
        {
            ans*=(n-i);
            ans/=i+1;
        }
        return ans;
    }
    int numTrees(int n) {
        return (solve(n))/(n+1);
    }
};