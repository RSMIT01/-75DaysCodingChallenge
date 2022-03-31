class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int pair=0;
       unordered_map<int,int>s;
        for(int i=0;i<nums.size();i++)
        {
             s[nums[i]]++;
        }
        if(k==0)
        {
            for(auto i:s)
            {
                if(i.second>1)
                {
                    pair++;
                }
            }
        }
        else
        {
            for(auto i:s)
            {
                if(s.find(i.first-k)!=s.end())
                {
                    pair++;
                }
            }
        }
        return pair;
    }
};