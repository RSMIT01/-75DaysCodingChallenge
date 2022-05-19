class Solution
{
    public:
    static bool mycomp(pair<int,int>p1,pair<int,int>p2)
    {
        return p1.second<p2.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
         vector<pair<int,int>>activity;
      for(int i=0;i<n;i++)
      {
          activity.push_back({start[i],end[i]});
      }
      sort(activity.begin(),activity.end(),mycomp);
      int ans=1;
      int prev=activity[0].second;
      for(int i=1;i<n;i++)
      {
          if(prev<activity[i].first)
          {
              ans++;
              prev=activity[i].second;
          }
      }
      return ans;
    }
        
};