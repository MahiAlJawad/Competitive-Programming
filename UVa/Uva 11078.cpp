#include<iostream>
#include<cstdio>
#include<algorithm>
int a[100005];
using namespace std;
int main()
{
    int t, i, d, grt, n, mx;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin>> t;

    while(t--)
    {
        scanf("%d", &n);
        for(i= 1; i<=n; i++)
            scanf("%d", &a[i]);
        d= a[1]-a[2];
        mx= d;
        grt= max(a[1], a[2]);

        for(i= 3; i<=n; i++)
        {
            d= grt-a[i];
            if(d>mx)
                mx= d;
            grt= max(grt, a[i]);
        }
        printf("%d\n", mx);

    }
    return 0;
}
