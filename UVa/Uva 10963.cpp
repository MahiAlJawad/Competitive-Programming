#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t, n, i, a, b, flag;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int d[n+10];
        for(i=1; i<=n; i++)
        {
            scanf("%d%d", &a, &b);
            d[i]= abs(a-b)+1;
        }
        flag= 1;
        for(i= 1; i<=n-1; i++)
        {
            if(d[i]!= d[i+1])
            {
                flag= 0;
                break;
            }
        }
        if(flag== 1)
            printf("yes\n");
        else
            printf("no\n");
        if(t!= 0)
            printf("\n");

    }
    return 0;
}
