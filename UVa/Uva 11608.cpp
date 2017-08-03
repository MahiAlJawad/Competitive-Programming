#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int a[13], b[13], n, p, i, c= 0;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &n)== 1 && n>=0)
    {
        p= n;
        for(i= 1; i<=12; i++)
            scanf("%d", &a[i]);
        for(i= 1; i<=12; i++)
            scanf("%d", &b[i]);
        printf("Case %d:\n", ++c);
        for(i= 1; i<=12; i++)
        {
            if(p>=b[i])
            {
                printf("No problem! :D\n");
                p-=b[i];
            }
            else
                printf("No problem. :(\n");
            p+= a[i];
        }
    }
}
