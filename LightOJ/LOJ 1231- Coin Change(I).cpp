#include<bits/stdc++.h>
using namespace std;

int coin[52], c[52], dp[52][22][1005], n;

int coin_change(int i, int taken, int amount)
{
    int j, ret1= 0, ret2= 0;
    if(dp[i][taken][amount]!= -1) return dp[i][taken][amount];
    if(i>=n)
    {
        if(amount== 0)
            return 1;
        else return 0;
    }
    if(amount== 0) return 1;
    if(amount- coin[i]>= 0 && taken< c[i])
        ret1= coin_change(i, taken+1, amount- coin[i]);
    else ret1= 0;
    ret2= coin_change(i+1, 0, amount);

    return dp[i][taken][amount]= (ret1+ret2)%100000007;
}

int main()
{
    int t, tc= 0, k, i;
    scanf("%d", &t);

    while(t--)
    {
        memset(dp, -1, sizeof(dp));

        scanf("%d%d", &n, &k);
        for(i= 0; i<n; i++)
            scanf("%d", &coin[i]);

        for(i= 0; i<n; i++)
            scanf("%d", &c[i]);

        printf("Case %d: %d\n", ++tc, coin_change(0,0, k));

    }

    return 0;
}
