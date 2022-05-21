class Solution {
public:
     void solve(vector<int>& candidates,  vector<int> &subset, vector<vector<int>> &ans,int target,int idx)
    {
         
         if(target==0)
        {
           ans.push_back(subset);
               return;
        }
         for(int i=idx;i<candidates.size();i++)
         {
             if(i!=idx && candidates[i]==candidates[i-1])
             {
               continue;
             }
             if(candidates[i]>target)
             {
                break;
             }
       
           subset.push_back(candidates[i]);
            solve(candidates,subset,ans,target-candidates[i],i+1);
            subset.pop_back();
       
         }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<int>subset;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        solve(candidates,subset,ans,target,0);
        return ans;
    }
};