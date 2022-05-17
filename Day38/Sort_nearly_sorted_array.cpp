//time:O((n-k)*logk)

#include<bits/stdc++.h>
using namespace std;
void sortarr(vector<int> &arr,int k)
{
    vector<int>ans;
    int n=arr.size();
    int sz=(n==k)?k:k+1;//if array size is k else k+1 element pushed which includes first element who shifted k
    priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.begin()+k);


    for(int i=k+1;i<n;i++)
    {
        ans.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }
     while(!pq.empty())
     {
         ans.push_back(pq.top());
         pq.pop();
     }
    cout<<"sorted ans:\n";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }


}
int main()
{
vector<int>arr= {6, 5, 3, 2, 8, 10, 9};
int k=3;
sortarr(arr,k);
return 0;
}