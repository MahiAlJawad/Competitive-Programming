#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t, n, a, b, x, y, i;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin>> t;
    for(i= 1; i<=t; i++)
    {
        scanf("%d%d%d", &n, &a, &b);
        x= n-a;
        if(x>b)
            y= a+b;
        else
            y= (b-x)%n;
        if(y== 0)
            y= n;
        printf("Case %d: %d\n", i, y);
    }
    return 0;
}
