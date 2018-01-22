#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, tc= 0, ax, ay, bx, by, cx, cy, dx, dy;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
        dx= ax+cx- bx;
        dy= ay+cy- by;
        double area= 0.5* (((ax*by)+(bx*cy)+ (cx*dy)+ (dx*ay))- ((ay*bx)+(by*cx)+(cy*dx)+(dy*ax)));
        printf("Case %d: %d %d %.0lf\n", ++tc, dx, dy, fabs(area));

    }
    return 0;
}
