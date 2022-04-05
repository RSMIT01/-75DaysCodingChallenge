class Solution {
public:
    int atmost(vector<int>& nums,int k)
    {
        unordered_map<int,int>m;
        int res=0;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())k--;
            m[nums[i]]++;
            while(k<0)
            {
                m[nums[j]]--;
                if(m[nums[j]]==0)
                {
                    k++;
                    m.erase(nums[j]);
                }
                j++;
            }
            res+=i-j+1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};