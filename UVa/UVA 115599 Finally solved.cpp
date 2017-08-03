#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n, b, h, w, i, j, x[20], cost[20], p, c, m, flag;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d%d%d%d", &n, &b, &h, &w)== 4)
    {
        for(i= 1; i<= h; i++)
        {
            scanf("%d", &p);
            c= p*n;
            for(j= 1; j<= w; j++)
            {
                scanf("%d", &x[j]);
            }
            flag= 0;
            for(j= 1; j<=w; j++)
            {
                if(x[j]>= n)
                {
                    flag= 1;
                    break;
                }
            }
            if(flag== 1 && (c<=b))
                cost[i]= c;
            else
            {
                cost[i]= 1000000;
            }

        }
        m= cost[1];
        for(i=2; i<= h; i++)
        {
            if(cost[i]< m)
                m= cost[i];
        }
        if(m== 1000000)
            printf("stay home\n");
        else
            printf("%d\n", m);
    }


    return 0;
}


