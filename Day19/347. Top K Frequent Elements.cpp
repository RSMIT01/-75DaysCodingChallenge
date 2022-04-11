class Solution {
public:
    
    struct mycomp{
      bool operator()(pair<int,int> &p1,pair<int,int> &p2)
        {
            if(p2.second<p1.second)
            {
                return true;
            }
            return false;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //build a min heap 
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp>pq;
        unordered_map<int,int>m;
        for(auto it :nums)
        {
            m[it]++;
        }
        for(auto it:m)
        {
            pq.push({it.first,it.second});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        //at the end pq has only k elements which are most frequent.
        vector<int>ans;
         while(!pq.empty())
         {
             ans.push_back(pq.top().first);
             pq.pop();
         }
        return ans;
    }
};