class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //build a min heap 
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>m;
        for(auto it :nums)
        {
            m[it]++;
        }
        for(auto it:m)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        //at the end pq has only k elements which are most frequent.
        vector<int>ans;
         while(!pq.empty())
         {
             ans.push_back(pq.top().second);
             pq.pop();
         }
        return ans;
    }
};