#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int main()
{
    int t, i, j, a[15], y;
    double n, x;
    cin>> t;
    for(i= 1; i<=t; i++)
    {
        cin>> n;
        for(j= 1; j<=n; j++)
            scanf("%d", &a[j]);

        x= n/2;
        y= ceil(x);
        printf("Case %d: %d\n", i, a[y]);
    }
    return 0;
}
