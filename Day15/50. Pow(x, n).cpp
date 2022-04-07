class Solution {
public:
    
    double solve(double x,long n)// Binary Exponentiation
    {
        if(n==0)
        {
            return 1;
        }
       else if(n<0)
        {
            return solve(1/x,-n);
        }
        else if(n%2==0)
        {
            n/=2;
            return solve(x*x,n);
        }
        else if(n%2==1)
        {
            n/=2;
            return x*solve(x*x,n);
        }
        return 0;
    }
    double myPow(double x,int n){
         return solve(x,(long)n);
    }
};