#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t, tc= 0, n, m;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld", &n, &m);
        ll x, ans;
        x= n/m;
        ans= (x/2)* (m*m);
        printf("Case %lld: %lld\n", ++tc, ans);
    }
    return 0;
}
