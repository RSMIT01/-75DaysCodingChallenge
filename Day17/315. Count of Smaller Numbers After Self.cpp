class Solution {
public:
    //sort in decreasing order
   void  merge(vector<pair<int,int>> &arr,int left,int right,int mid,vector<int> &count)
   {
       int n=(right-left+1);
        vector<pair<int,int>>temp(n);
        int i=left;
       int j=mid;
       int k=0;
       while((i<=mid-1) && (j<=right))
       {
           if(arr[i].first<=arr[j].first)
           {
               
               temp[k++]=arr[j++];
                
           }
           else
           {
               count[arr[i].second]+=(right-j+1);  // ex part 1:  5 3 2     part2: 4 1  here 4 is less than 5 so clear that every element form 4 to end is less than 5 so all are considered as smaller.
                temp[k++]=arr[i++];
           }
       }
       
        while(i<=mid-1)
        {
            
             temp[k++]=arr[i++];
        }
       while(j<=right)
       {
            temp[k++]=arr[j++];
       }
       int x=0;
       while(left<=right)
       {
           arr[left++]=temp[x++];
       }
   }
    void  merge_sort(vector<pair<int,int>> &arr,int left,int right,vector<int> &count)
    {
         if(left<right)
         {
             int mid=left+(right-left)/2;
             merge_sort(arr,left,mid,count);
             merge_sort(arr,mid+1,right,count);
             merge(arr,left,right,mid+1,count);
         }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>count(n,0);
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({nums[i],i});
        }
      merge_sort(arr,0,n-1,count);
        return count;
    }
};