class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // O(n^2)
        // int  zero=0;
        // int k=nums.size()-1;
        // for(int i=0;i<nums.size()-zero;i++)
        // {
        //     if(nums[i]==0)
        //     {
        //         for(int j=i;j<nums.size()-1-zero;j++)
        //         {
        //             nums[j]=nums[j+1];
        //         }
        //         if(nums[i]==0)
        //         {
        //             i--;
        //         }
        //         nums[k--]=0;
        //         zero++;
        //     }
        // }
        
        
        
        
  //     O(n)
         int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[j],nums[i]);
                j++;
            }
        }
    }
};