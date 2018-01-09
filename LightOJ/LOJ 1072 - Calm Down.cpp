#include<bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
int main()
{
    long long t, tc= 0;
    double R, r, n, ans, x;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lf%lf", &R, &n);
        x= sin(pi/n);
        ans= (R*x)/(1+x);
        if(ceil(ans)== ans) printf("Case %lld: %.0lf\n", ++tc, ans);
        else printf("Case %lld: %.10lf\n", ++tc, ans);
    }
    return 0;
}

