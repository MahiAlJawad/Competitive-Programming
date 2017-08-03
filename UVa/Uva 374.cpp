#include<bits/stdc++.h>
using namespace std;
long long bigmod(long long a, long long b, long long m)
{
    if(b== 0) return 1%m;
    long long x= bigmod(a, b/2, m);
    x= (x*x)%m;
    if(b%2== 1) x= (x*a)%m;
    return x;
}
int main()
{
    long long b, p, m;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(scanf("%lld%lld%lld",  &b, &p, &m)== 3)
    {
        printf("%lld\n", bigmod(b, p, m));
    }
    return 0;
}
