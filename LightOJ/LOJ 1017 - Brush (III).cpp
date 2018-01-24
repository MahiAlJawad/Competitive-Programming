/******************************************************************************************************************************
*** "In the name of Allah(swt), the most gracious, most merciful. Allah(swt) blesses with knowledge to whom he wants."      ***
***     Author     : Mahi Al Jawad                                                                                          ***
***     University : Dept. of CSE, IIUC                                                                                     ***
***     github     : https://github.com/MahiAlJawad                                                                         ***
***     Email      : br.mahialjawad@gmail.com                                                                               ***
***     facebook   : https://www.facebook.com/jawad.wretched                                                                ***
*******************************************************************************************************************************/

#include<bits/stdc++.h>
#define fin(in) freopen("in.txt", "r", stdin)
#define fout(out) freopen("out.txt", "w", stdout)
#define pb push_back
#define lng long long
#define pi acos(-1.0)
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c));//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
#define forit(it,s) for(__typeof((s).end()) it=(s).begin(); it!= (s).end(); it++)
#define gcd(a,b) __gcd(a,b)
#define string_reverse(s) reverse(s.begin(), s.end())//Vector also can be reversed with this function

using namespace std;

lng k, n, w;
lng a[105];
lng dp[105][105];
lng brush(lng i, lng x)
{
    if(i>= n+1) return 0;
    if(dp[i][x]!= -1) return dp[i][x];
    lng profit1, profit2;
    if(x+1<=k)
    {
        lng j;

        lng p= 1;
        for(j= i+1; j<=n; j++)
        {
            if(a[i]+w<a[j])
            {
                break;
            }
            p++;
        }
        profit1= p+ brush(j, x+1);

    }
    else return 0;

    profit2= brush(i+1, x);

    return dp[i][x]= max(profit1, profit2);
}
int main()
{
    lng t, tc= 0, i, x, y;
    //fin(in);
    //fout(out);
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld%lld", &n, &w, &k);
        memset(a, 0, sizeof(a));
        memset(dp, -1, sizeof(dp));
        for(i= 1; i<=n; i++)
        {
            scanf("%lld%lld", &x, &y);
            a[i]= y;
        }
        a[0]= INT_MIN;
        sort(a, a+(n+1));
        lng ans= brush(1, 0);
        printf("Case %lld: %lld\n", ++tc, ans);
    }
    return 0;
}

