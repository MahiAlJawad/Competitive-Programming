#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t, i, c, j, a[3700], n, p, h[105];
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &p);
        for(i= 0; i<=n; i++)
            a[i]= 0;
        for(i= 1; i<=p; i++)
            scanf("%d", &h[i]);
        for(i= 1; i<=p; i++)
        {
            for(j= h[i]; j<=n; j+=h[i])
            {
                a[j]= 1;
            }
        }
        c= 0;
        for(i= 1; i<=n; i++)
        {
            if((a[i]== 1) && (i%7!= 0) && ((i+1)%7!=0))
                c++;
        }
        printf("%d\n", c);
    }
    return 0;
}
