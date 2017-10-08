#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, tc= 0, i, j, count, x, y;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w",  stdout);
    while(scanf("%d%d ", &n, &m)== 2 && n!=0 && m!= 0)
    {
        tc++;
        char c[103][103];
        for(i= 1; i<= n; i++)
        {
            for(j= 1; j<=m; j++)
            {
                if(j== m) scanf("%c ", &c[i][j]);
                else scanf("%c", &c[i][j]);
            }
        }
        if(tc!= 1) printf("\n");

        for(i= 0; i<=m+1; i++) c[0][i]= '.';
        for(i= 0; i<=n+1; i++) c[i][0]= '.';
        for(i= 0; i<= m+1; i++) c[n+1][i]= '.';
        for(i= 0; i<= n+1; i++) c[i][m+1]= '.';

        printf("Field #%d:\n", tc);
        for(i= 1; i<=n; i++)
        {
            for(j= 1; j<=m; j++)
            {
                count= 0;
                if(c[i][j]== '*') printf("*");
                else
                {
                    for(x= i-1; x<=i+1; x++)
                    {
                        for(y= j-1; y<=j+1; y++)
                        {
                            if(c[x][y]== '*') count++;
                        }
                    }
                    printf("%d", count);
                }

            }
            printf("\n");
        }
    }
    return 0;
}

