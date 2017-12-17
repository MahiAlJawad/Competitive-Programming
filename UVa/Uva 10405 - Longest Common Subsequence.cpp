#include<bits/stdc++.h>
using namespace std;

char s1[1005], s2[1005];
int dp[1005][1005];


int lcs(int i, int j)
{
    if(dp[i][j]!= -1) return dp[i][j];
    if(s1[i]== '\0' || s2[j]== '\0') return 0;
    if(s1[i]== s2[j])
        dp[i][j]= 1+ lcs(i+1, j+1);
    else
    {
        dp[i][j]= max(lcs(i+1, j), lcs(i, j+1));
    }
    return dp[i][j];
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while(gets(s1) && gets(s2))
    {
        memset(dp, -1, sizeof(dp));
        printf("%d\n", lcs(0, 0));
    }
    return 0;
}
