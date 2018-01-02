#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, i, x;
    while(scanf("%lld%lld", &n, &m))
    {
        map<int, int> mp;
        if(n== 0 && m== 0) break;
        for(i= 1; i<=n; i++)
        {
            scanf("%lld", &x);
            mp[x]++;
        }
        for(i= 1; i<=m; i++)
        {
            scanf("%lld", &x);
            mp[x]++;
        }
        map<int, int> :: iterator it;
        long long cnt= 0;
        for(it= mp.begin(); it!= mp.end(); it++)
        {
            if(it->second > 1)  cnt++;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
