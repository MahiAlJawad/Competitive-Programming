#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t, tc= 0;
    ll n, i;
    scanf("%d", &t);

    while(t--)
    {
        map<int, int> m;
        scanf("%lld", &n);
        while(n)
        {
            m[n%2]++;
            n/= 2;
        }
        if(m[1]%2== 0) printf("Case %d: even\n", ++tc);
        else printf("Case %d: odd\n", ++tc);
    }
    return 0;
}
