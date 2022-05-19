class Solution
{
    public:

   static bool mycomp(pair<int,int>p1,pair<int,int>p2)
    {
        return p1.second<p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
      vector<pair<int,int>>meet;
      for(int i=0;i<n;i++)
      {
          meet.push_back({start[i],end[i]});
      }
      sort(meet.begin(),meet.end(),mycomp);
      int ans=1;
      int prev=meet[0].second;
      for(int i=1;i<n;i++)
      {
          if(prev<meet[i].first)
          {
              ans++;
              prev=meet[i].second;
          }
      }
      return ans;
    }
};