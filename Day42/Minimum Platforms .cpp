class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int curplatforms=1;
    	int i=1;
    	int j=0;
    	int platforms=1;
    	while(i<n && j<n)
    	{
    	    
    	    //already available train on platform
    	    if(arr[i]<=dep[j])
    	    {
    	        curplatforms++;
    	        i++;
    	    }
    	    //release platform train is went.
    	    else if(arr[i]>dep[j])
    	    {
    	        curplatforms--;
    	        j++;
    	    }
    	    platforms=max(platforms,curplatforms);
    	}
    	return platforms; 
    }
};