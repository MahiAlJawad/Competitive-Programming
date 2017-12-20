#include<bits/stdc++.h>
#define MX 102
using namespace std;
int dp[MX][MX];
int nCr(int n, int r)
{
    if(n== r) return 1;
    if(r== 1) return n;
    if(dp[n][r]!= -1) return dp[n][r];
    return dp[n][r]= nCr(n-1, r-1)+nCr(n-1, r);
}
int main()
{
    int n= 6, r= 4;
    memset(dp, -1, sizeof(dp));
    cout<<n<< "C"<<r<<"= "<<nCr(n, r)<<endl;
    return 0;
}
