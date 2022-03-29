class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>>res;
        int n=nums.size();
         sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int cursum=target-(nums[i]+nums[j]);
                int start=j+1;
                int end=n-1;
               while(start<end)
               {
                  if(nums[start]+nums[end]==cursum)
                  {
                      vector<int>temp;
                      temp.push_back(nums[i]);
                       temp.push_back(nums[j]);
                       temp.push_back(nums[start]);
                       temp.push_back(nums[end]);
                      res.push_back(temp);
                      while(start<end && nums[start]==temp[2])start++;//if duplicates then skip it
                      while(end>start && nums[end]==temp[3])end--;//if duplicates then skip it
                  }
                   else if(nums[start]+nums[end]<cursum)
                   {
                       start++;
                   }
                   else
                   {
                       end--;
                   }
               }
                while(j+1<n && nums[j+1]==nums[j])j++;//if duplicates then skip it
  
            }
             while(i+1<n && nums[i+1]==nums[i])i++;//if duplicates then skip it
        }
        
     
        return res;
    }
};