class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<time.size();i++)
        {
            int x=time[i]%60;
            if(m.find(60-x)!=m.end())
            {
                ans+=m[60-x];
            }
            else if(x==0)
            {
                ans+=m[0];
            }
            m[x]++;
        }
        return ans;
    }
};