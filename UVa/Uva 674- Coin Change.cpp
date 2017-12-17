#include<bits/stdc++.h>
using namespace std;

int coin[]= {1, 5, 10, 25, 50};
int dp[6][7500];

int coin_change(int i, int amount)
{
    if(i>4)
    {
        if(amount== 0) return 1;
        else return 0;
    }
    if(amount== 0) return 1;

    if(dp[i][amount]!= -1) return dp[i][amount];
    int ret1= 0, ret2= 0;
    if(amount-coin[i]>= 0)
    {
        ret1= coin_change(i, amount- coin[i]);
    }
    else ret1= 0;

    ret2= coin_change(i+1, amount);

    return dp[i][amount]= ret1+ret2;
}


int main()
{
    int make;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d", &make)== 1)
    {
        printf("%d\n", coin_change(0, make));
    }

    return 0;
}
