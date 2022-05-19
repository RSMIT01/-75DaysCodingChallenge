class Solution 
{
    public:
 
    static bool mycomp(Job j1,Job j2)
    {
        return j1.profit>j2.profit;
    }
    
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int maxdead=INT_MIN,maxprofit=0,jobdone=0;
        for(int i=0;i<n;i++)
        {
            maxdead=max(maxdead,arr[i].dead);
        }
        vector<int>slot(maxdead+1,-1);
        sort(arr,arr+n,mycomp);
        for(int i=0;i<n;i++)
        {
           
            for(int j=arr[i].dead;j>0;j--)
            {
                if(slot[j]==-1)
                {
                    maxprofit+=arr[i].profit;
                    slot[j]=arr[i].id;
                    jobdone++;
                    break;
                }
            }
        }
        return {jobdone,maxprofit};
    } 
};