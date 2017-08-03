#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c= 0;
    double n, r;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(scanf("%lf%lf", &r, &n)== 2)
    {
        c++;
        if(r== 0 && n== 0)
            break;
        if((n+(26*n))<r)
            printf("Case %d: impossible\n", c);
        else
            printf("Case %d: %.0lf\n", c, fabs(ceil((r-n)/n)));
    }
    return 0;
}
