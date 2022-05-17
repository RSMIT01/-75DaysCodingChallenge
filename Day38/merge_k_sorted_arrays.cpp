//time:O(n*k*logk)

#include<bits/stdc++.h>
using namespace std;
void sortk(vector<vector<int>> &arr,int k)
{
    vector<int>idx(k,0);
    vector<int>ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int i=0;i<k;i++)
    {
        pq.push({arr[i][0],i});
    }
    


    while(!pq.empty())
    {
        pair<int,int>cur=pq.top();
        pq.pop();
        ans.push_back(cur.first);
        if(idx[cur.second]+1<arr[cur.second].size())
        {
            idx[cur.second]+=1;
            int i=idx[cur.second];
            pq.push({arr[cur.second][i],cur.second});
        }
    }
    cout<<"merged ans:\n";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}
int main()
{
vector<vector<int>>arr= {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
int k=3;
sortk(arr,k);

return 0;
}