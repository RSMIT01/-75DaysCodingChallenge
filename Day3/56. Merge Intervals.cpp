class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int res=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[res][1]>=intervals[i][0])
            {
                intervals[res][1]=max(intervals[res][1],intervals[i][1]);
                   intervals[res][0]=min(intervals[res][0],intervals[i][0]);
             }
            else
            {
                res++;
                intervals[res][0]=intervals[i][0];
                 intervals[res][1]=intervals[i][1];
            }
        }
        int j=intervals.size()-1;
        while(j>res)
        {
            intervals.pop_back();
            j--;
        }
         return intervals;
    }
       
};