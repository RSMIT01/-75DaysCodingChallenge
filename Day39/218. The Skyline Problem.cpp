class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>>arr;
        vector<vector<int>>skyline;
        
        for(int i=0;i<buildings.size();i++)
        {
            arr.push_back({buildings[i][0],-buildings[i][2]});
            arr.push_back({buildings[i][1],buildings[i][2]});
        }
        sort(arr.begin(),arr.end());
        multiset<int>pq;
        pq.insert(0);
        int height=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i].second<0)
            {
              pq.insert(-arr[i].second);
            }
            else
            {
                pq.erase(pq.find(arr[i].second));
            }
            int curheight=*pq.rbegin(); 
            
            if(curheight!=height)
            {
                
                skyline.push_back({arr[i].first,curheight});
                height=curheight;
            }
        }
        return skyline;
        
        
        
    }
};