class Solution {
public:
    void arrange(multiset<int> &maxheap,multiset<int> &minheap)
    {
        if(maxheap.size()>0 && minheap.size()>0 && (*maxheap.rbegin())>(*minheap.begin()))
        {
          int cur=*maxheap.rbegin();
          minheap.insert(cur);
          maxheap.erase(maxheap.find(cur));
        }
        if(maxheap.size()>minheap.size()+1)
        {
            int cur=*maxheap.rbegin();
            minheap.insert(cur);
            maxheap.erase(maxheap.find(cur));
        }
         if(minheap.size()>maxheap.size()+1)
         {
             int cur=*minheap.begin();
            maxheap.insert(cur);
            minheap.erase(minheap.find(cur));
         }
        
    }
    double  find_median(multiset<int> &maxheap,multiset<int> &minheap)
    {
        
        if(maxheap.size()==minheap.size())
        {
              int val1=(*maxheap.rbegin());
              int val2=(*minheap.begin());
            
            
            return (double)((long long)val1+(long long)val2)*0.5;
        }
    
        return (maxheap.size()>minheap.size())?*maxheap.rbegin():*minheap.begin();
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
         vector<double>ans;
         int n=nums.size();
         multiset<int>maxheap;
        multiset<int>minheap;
        for(int i=0;i<k;i++)
        {
             maxheap.insert(nums[i]);
             arrange(maxheap,minheap); 
        }
      ans.push_back(find_median(maxheap,minheap));
        
      for(int i=k;i<n;i++)
      {
          
          if(maxheap.find(nums[i-k])!=maxheap.end())
          {
              maxheap.erase(maxheap.find((nums[i-k])));
          }
          else if(minheap.find(nums[i-k])!=minheap.end())
          {
              minheap.erase(minheap.find((nums[i-k])));
          }
          arrange(maxheap,minheap);
          maxheap.insert(nums[i]);
          arrange(maxheap,minheap);
            ans.push_back(find_median(maxheap,minheap));
      }
        
        return ans;
    }
};