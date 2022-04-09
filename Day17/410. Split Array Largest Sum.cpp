class Solution {
public:
    int find_parts(vector<int>& nums,int sum)
    {
        int parts=1;
        int temp_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]+temp_sum>sum)//if temp_sum exceed the sum then put element into new subarray 
            {
                parts++;
                temp_sum=nums[i];
            }
            else
            {
                temp_sum+=nums[i];
            }
        }
        return parts;
    }
    int splitArray(vector<int>& nums, int m) {
      int sum=0;
        int max_ele=0;
       for(int i=0;i<nums.size();i++)
       {
           sum+=nums[i];
           max_ele=max(max_ele,nums[i]);
       }
       int low=max_ele;//minimum sum is atleast one element in array and it is maximum among all.
       int high=sum;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int parts=find_parts(nums,mid);
         
            if(parts<=m)
            {

                 ans=mid;
                 high=mid-1;//decreasing sum to minimize largest sum
               
            }
            else
            {
                  low=mid+1;
                
            }
            
        }
          
        return ans;
    }
};