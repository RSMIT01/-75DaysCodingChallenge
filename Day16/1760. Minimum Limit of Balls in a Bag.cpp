class Solution {
public:
    int find_operations(int bagsize,vector<int>& nums)
    {
        int op=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==bagsize)//if equal then no need do divide 
            {
                continue;
            }
            else if(nums[i]%bagsize==0)//if dividable in equal size
            {
                op+=((nums[i]/bagsize)-1);
            }
            else //if not dividable then one part is more so it takes one extra operation
            {
                op+=(nums[i]/bagsize);
            }
        }
        return op;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
       int low=1;
       int high=INT_MIN;
        for(auto it:nums)
        {
            high=max(high,it);
        }
         int penalty =INT_MAX;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(find_operations(mid,nums)<=maxOperations)
            {
                penalty=mid;
                high=mid-1; //if we found less or equal operation then try to decrease bagsize to minimize penalty 
            }
            else
            {
                  low=mid+1;
                
            }
        }
        return penalty ;
    }
};