#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, tc= 0, m, x1, y1, x2, y2, x, y;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        scanf("%d", &m);
        printf("Case %d:\n", ++tc);
        while(m--)
        {
            scanf("%d%d", &x, &y);
            if(x>x1 && x<x2 && y>y1 && y<y2)
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
