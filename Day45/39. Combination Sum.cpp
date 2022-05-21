class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>> &combinations, vector<int> &temp,int target,int i)
    {
        if(i==candidates.size())
        {
            if(target==0)
            {
                combinations.push_back(temp);
            }
            return;
        }
        if(candidates[i]<=target)
        {
            temp.push_back(candidates[i]);
            solve(candidates,combinations,temp,target-candidates[i],i);
            temp.pop_back();
        }
        solve(candidates,combinations,temp,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int>temp;
        vector<vector<int>>combinations;
        solve(candidates,combinations,temp,target,0);
        return combinations;
    }
};