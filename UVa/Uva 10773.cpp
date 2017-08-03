#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs= 0;
    double d, v, u;
    scanf("%d", &t);
    while(t--)
    {
       cs++;
       scanf("%lf%lf%lf", &d, &v, &u);
       if(v>=u || v== 0 ||  u== 0)
            printf("Case %d: can't determine\n", cs);
       else
        printf("Case %d: %.3lf\n", cs, fabs((d/u)-(d/sqrt(u*u- v*v))));
    }
    return 0;
}
