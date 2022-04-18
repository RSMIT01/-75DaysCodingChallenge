class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset <int, greater <int> > m;  
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            m.insert(nums[i]);
        }
        for(int i=k;i<nums.size();i++)
        {
            ans.push_back(*m.begin());
            m.erase(m.find(nums[i-k]));
            m.insert(nums[i]);
        }
         ans.push_back(*m.begin());
        return ans;
    }
};