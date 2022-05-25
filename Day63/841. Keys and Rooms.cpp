class Solution {
public:
    void dfs(vector<int> &visited,vector<vector<int>>& rooms,int curroom)
    {
        visited[curroom]=1;
        for(int i=0;i<rooms[curroom].size();i++)
        {
            if(!visited[rooms[curroom][i]])
            {
                 dfs(visited,rooms,rooms[curroom][i]);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,0);
        dfs(visited,rooms,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        return true;
    }
};