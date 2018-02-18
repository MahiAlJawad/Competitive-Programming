#include<bits/stdc++.h>
using namespace std;
char a[103][103];
int main()
{
    int n, m, i, j;
    char c;
    scanf("%d%d", &n, &m);
    scanf("%c", &c);
    for(i= 1; i<=n; i++)
    {
        for(j= 1; j<=m; j++)
        {
            scanf("%c", &a[i][j]);
        }
        scanf("%c", &c);
    }


    bool flag= 0;

    for(i= 1; i<=n; i++)
    {
        for(j= 1; j<=m; j++)
        {
            if(j!= 1)
            {
                if(a[i][j]!= a[i][j-1])
                {
                    flag= 1;
                    //cout<<"flagged: "<<i<<" "<<j<<endl;
                    break;
                }
            }
            if(i!= 1)
            {
                if(a[i][j]== a[i-1][j])
                {
                    flag= 1;
                    //cout<<"flagged: "<<i<<" "<<j<<endl;
                    break;
                }
            }
        }
        if(flag) break;
    }
    if(flag) printf("NO\n");
    else printf("YES\n");
    return 0;
}
