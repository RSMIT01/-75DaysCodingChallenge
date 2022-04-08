class Solution {
public:
    
        // for 10 in first iteration 10-6=4 && ans=2
        // in second iteration 4-3=1 && ans=3;
        int divide(int dividend, int divisor)
    {
          
        if(dividend==INT_MIN && divisor==-1)
        {
            return INT_MAX;
        }
        int sign=1;
        if((dividend>0)^(divisor>0))  //if both have different sign then -ve
        {
            sign=-1;
        }
        long long num=abs(dividend),div=abs(divisor),ans=0;
        while(num>=div)
        {
            long long q=1;
            long long cur_div=div;
            while(cur_div<<1 <=num)
            {
                cur_div<<=1;
                q<<=1;
            }
            ans+=q;
            num-=cur_div;
        }
       return ans*sign;
    }
};