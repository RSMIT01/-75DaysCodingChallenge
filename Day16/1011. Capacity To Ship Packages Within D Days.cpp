class Solution {
public:
    int find_days(int capacity,vector<int>& weights)
    {
        int days=1;
        int cur_weight=0;
        for(int i=0;i<weights.size();i++)
        {
            if(cur_weight+weights[i]>capacity)//if by adding weight[i] exceed the capacity then ship it on next day
            {
                cur_weight=weights[i];
                days++;
            }
            else
            {
                cur_weight+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int high=0;
        for(auto it:weights)//we require minimum capacity as a higher weight among all. 
        {
            low=max(low,it);
            high+=it;   //maximum is to take all in one ship
        }
        int min_capacity=INT_MAX;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
             if(find_days(mid,weights)<=days)
             {
                 min_capacity=mid;  
                 high=mid-1;   //decrease to minimize capacity
             }
             else {
                 low=mid+1;
             }
        }
        return min_capacity;
    }
};