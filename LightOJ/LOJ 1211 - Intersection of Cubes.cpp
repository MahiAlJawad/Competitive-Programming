#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, tc=0, i, n;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        int x1= -1, y1= -1, z1= -1, x2= 2000, y2= 2000, z2= 2000;
        int a, b, c, d, e, f;
        scanf("%d", &n);
        for(i= 1; i<=n; i++)
        {
            scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
            x1= max(a, x1);
            y1= max(b, y1);
            z1= max(c, z1);
            x2= min(d, x2);
            y2= min(e, y2);
            z2= min(f, z2);
        }
        int ans= (x2-x1)*(y2-y1)*(z2-z1);
        printf("Case %d: ", ++tc);
        if(ans>=0)
            printf("%d\n", ans);
        else printf("0\n");

    }
    return 0;
}
