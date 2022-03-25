class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //     unordered_map<int,int>m;
    //     for(auto it:nums)
    //     {
    //         m[it]++;
    //     }
    //     for(auto it:m)
    //     {
    //         if(it.second>(nums.size()/2))
    //         {
    //             return it.first;
    //         }
    //     }
    //     return -1;
        
        
        
   // MOORE'S VOTING ALGORITHM
        int n=nums.size();
        int maj=nums[0];
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==maj)
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count==0)
            {
                maj=nums[i];
                count=1;
            }
        }
        return maj;
             }
};