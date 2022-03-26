class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> res; 
        int n=nums.size();
        sort(nums.begin(), nums.end()); 
        
        for (int i = 0; i < n-2; i++) {
            
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                
                int lo = i+1, hi =n-1, sum = 0 - nums[i];
                
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        res.push_back({nums[lo],nums[hi],nums[i]});
                        
                        while (lo < hi && nums[lo] == nums[lo+1])
                        {
                            lo++;
                        }
                        while (lo < hi && nums[hi] == nums[hi-1])
                        {
                            hi--;
                        }
                        lo++; hi--;
                    } 
                    else if (nums[lo] + nums[hi] < sum)
                    {
                        lo++;
                    }
                    else 
                    {
                        hi--;
                    }
               }
            }
        }
        return res;
    }
};