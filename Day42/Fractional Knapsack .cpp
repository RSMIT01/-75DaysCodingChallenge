class Solution
{
    public:
   
    static bool mycomp(Item i1,Item i2)
    {
        double a=(double)i1.value/(double)i1.weight;
        double b=(double)i2.value/(double)i2.weight;
        return a<b;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        sort(arr,arr+n,mycomp);
        
        int i=n-1;
        double ans=0;
        while(i>=0 && W!=0)
        {
            if(W-arr[i].weight>=0)
            {
                W-=arr[i].weight;
                ans+=arr[i].value;
            }
            else
            {
                ans+=((double)(arr[i].value)/(double)(arr[i].weight))*double(W);
                W=0;
            }
            i--;
        }
        return ans;
        
    }
        
};
