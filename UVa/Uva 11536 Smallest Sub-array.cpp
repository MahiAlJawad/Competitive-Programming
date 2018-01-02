#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t, tc= 0, n, m, k, i;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld%lld", &n, &m, &k);
        vector<long long> v;
        for(i= 0; i<=3; i++) v.push_back(i);
        for(i= 4; i<=n; i++)
        {
            long long x= ((v[i-1]+v[i-2]+v[i-3])%m)+1;
            v.push_back(x);
        }
        map<long long, long long> mp;
        vector<long long> d;
        long long b= 1;
        for(i= 1; i<=n; i++)
        {
            if(v[i]<=k) mp[v[i]]++;
            if(mp.size()>= k)
            {
                d.push_back((i-b)+1);
                while(1)
                {
                   mp[v[b]]--;
                   if(mp[v[b]]<= 0) mp.erase(v[b]);
                   if(mp.size()<k)
                   {
                       d.push_back((i-b)+1);
                       b++;
                       break;
                   }
                   b++;
                }
            }
        }
        long long dsize= d.size();
        if(dsize== 0) printf("Case %lld: sequence nai\n", ++tc);
        else
        {
            long long mn= 1e8;
            for(i= 0; i<dsize; i++)
            {
                if(d[i]<mn) mn= d[i];
            }
            printf("Case %lld: %lld\n", ++tc, mn);
        }

    }
    return 0;
}
