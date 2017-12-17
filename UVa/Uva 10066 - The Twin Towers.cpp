#include<bits/stdc++.h>
using namespace std;

int a[102], b[102], n1, n2;
int dp[102][102];

int lcs(int i, int j)
{
    if(dp[i][j]!= -1) return dp[i][j];
    if(i== n1 || j== n2) return 0;
    if(a[i]== b[j])
        dp[i][j]= 1+ lcs(i+1, j+1);
    else
    {
        dp[i][j]= max(lcs(i, j+1), lcs(i+1, j));
    }
    return dp[i][j];
}

int main()
{
    int i, tc= 0;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d %d", &n1, &n2) && (n1!= 0 && n2!=0))
    {
        for(i= 0; i<n1; i++)
            scanf("%d", &a[i]);
        for(i= 0; i<n2; i++)
            scanf("%d", &b[i]);
        memset(dp, -1, sizeof(dp));
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++tc, lcs(0, 0));
    }
    return 0;
}
