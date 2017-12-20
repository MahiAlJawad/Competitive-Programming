#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t, tc= 0, n, i, dp[10005];
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld",&dp[0], &dp[1], &dp[2], &dp[3], &dp[4], &dp[5], &n);

        for(i= 6; i<=n; i++)
        {
            dp[i]= (dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%10000007;
        }
        printf("Case %lld: %lld\n", ++tc, dp[n]%10000007);

    }


    return 0;
}
