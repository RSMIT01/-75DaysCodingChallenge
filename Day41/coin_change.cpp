#include<bits/stdc++.h>
using namespace std;
int main()
{
int amount;
cin>>amount;
vector<int>coins={ 1, 2, 5, 10, 20,50, 100, 500, 1000};
sort(coins.begin(),coins.end());
int n=coins.size(),ans_coin=0,i=n-1;
while(i>=0 && amount)
{
    if(amount-coins[i]>=0)
    {
        amount-=coins[i];
        ans_coin++;
    }
    else{
        i--;
    }
}
cout<<ans_coin;
return 0;
}