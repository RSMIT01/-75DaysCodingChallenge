class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>freq;
        priority_queue<int>pq;     
        for(char task:tasks)
        {
            freq[task]++;
        }
        for(auto i:freq)
        {
            pq.push(i.second);
        }
        int ans=0;
        while(!pq.empty())
        {
            vector<int>temp;
            for(int i=0;i<n+1;i++)
            {
                if(!pq.empty())
                {
                   temp.push_back(pq.top());
                   pq.pop(); 
                }
                
            }
             
            for(int count:temp)
            {
               if(count-1>0)
               {
                   pq.push(count-1);
               }
               
            }
            ans+=(pq.empty())?temp.size():n+1;
        }
        return ans;
    }
};