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
#define ll long long
#define pi acos(-1.0)
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c));//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
#define forit(it,s) for(__typeof((s).end()) it=(s).begin(); it!= (s).end(); it++)
#define gcd(a,b) __gcd(a,b)
#define string_reverse(s) reverse(s.begin(), s.end())//Vector also can be reversed with this function
using namespace std;

int a[2*1005], n;
int dp[2*1005][1005];

int house(int i, int s)
{
    int x= 0, y= 0, m= n+s;
    if(dp[i][s]!= -1) return dp[i][s];
    if(i>= m-1) return 0;
    x= a[i]+house(i+2, s);
    y= house(i+1, s);
    return dp[i][s]= max(x, y);
}
int main()
{
   int t, tc= 0, i, ans, m;
   //fin(in);
   //fout(out);
   scanf("%d", &t);
   while(t--)
   {
       memset(a, 0, sizeof(a));
       memset(dp, -1, sizeof(dp));
       scanf("%d", &n);
       for(i= 1; i<=n; i++)
       {
           scanf("%d", &a[i]);
       }
       m= 2*n;
       for( int j=1; i<= m; i++, j++)
       {
           a[i]= a[j];
       }

       ans= INT_MIN;
       for(i= 1; i<= n; i++)
       {
           ans= max(house(i, i), ans);
       }
       printf("Case %d: %d\n", ++tc, ans);
   }
   return 0;
}


