class Solution {
public:
    int sum_sqr_digit(int n)
    {
        int sum=0;
        while(n>0)
        {
         sum+=(n%10)*(n%10);
         n/=10;
        }
        return sum;
    }
    bool isHappy(int n) 
    {
        while(n!=1 && n!=4)
        {
            n=sum_sqr_digit(n);
        }
       return n==1;
    }
};