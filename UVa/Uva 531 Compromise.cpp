#include<bits/stdc++.h>
using namespace std;
int n, m;
int dp[105][105];

int lcs(int i, int j, string a[], string b[])
{
    if(i== n-1 || j== m-1) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    int ans= 0;

    if(a[i]== b[j]) ans= 1+ lcs(i+1, j+1, a, b);
    else
    {
        int val1= lcs(i+1, j, a, b);
        int val2= lcs(i, j+1, a, b);
        ans= max(val1, val2);
    }
    dp[i][j]= ans;
    return dp[i][j];
}

string ans= "";
void printlcs(int i, int j, string a[], string b[])
{
    if(i== n-1 || j== m-1)
    {
        ans.erase(ans.end()-1);
        cout<<ans<<"\n";
        return;
    }
    if(a[i]== b[j])
    {
        ans+= a[i];
        ans+= " ";
        printlcs(i+1, j+1, a, b);
    }
    else
    {
        if(dp[i][j+1]> dp[i+1][j]) printlcs(i, j+1, a, b);
        else printlcs(i+1, j, a, b);
    }
}

int main()
{
    char c;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin>> c)
    {
        memset(dp, -1, sizeof(dp));
        string x= "";
        x+= c;
        while(1)
        {
            c= getchar();
            if(c== '#') break;
            x+= c;
        }
        string a[105], b[105];
        istringstream is(x);
        n= 0;
        while(is>>a[n++])
        {

        }

        x= "";
        while(1)
        {
            c= getchar();
            if(c== '#') break;
            x+= c;
        }

        istringstream iS(x);
        m= 0;
        while(iS>>b[m++])
        {

        }

        int f= lcs(0, 0, a, b);
        printlcs(0, 0, a, b);
        ans.clear();
    }
    return 0;
}
