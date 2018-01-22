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
using namespace std;

int main()
{
    ll t, tc= 0, n, w, i, a, b;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &w);
        if(w%2== 1) printf("Case %lld: Impossible\n", ++tc);
        else
        {
            a= -1;
            b= -1;
            int limit= (w/2)+1;
            for(i= 2; i<=limit; i+= 2)
            {
                if(w%i== 0 && (w/i)%2== 1)
                {
                    a= w/i;
                    b= i;
                    break;
                }
            }
            if(a== -1 && b== -1)
                printf("Case %lld: Impossible\n", ++tc);
            else
                printf("Case %lld: %lld %lld\n",++tc, a, b);
        }
    }
    return 0;
}




