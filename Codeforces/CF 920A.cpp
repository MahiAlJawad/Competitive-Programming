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
#define lld I64d//for the sites like CF
using namespace std;

bool a[205];
lng k[205];
int main()
{
    lng t, n, K, i;
    scanf("%lld", &t);
    while(t--)
    {
        memset(a, 0, sizeof(a));
        scanf("%lld%lld", &n, &K);

        a[0]= 1;
        a[n+1]= 1;
        for(i= 1; i<=K; i++)
        {
            scanf("%lld", &k[i]);
            a[k[i]]= 1;
        }

        lng t= 1;
        lng cnt;
        bool flag= 0;
        while(1)
        {
            cnt= 0;
            for(i= 1; i<=K; i++)
            {
                lng pos= k[i];
                if((pos+t)<=n && (pos-t)>= 1)
                {
                    if(a[pos+t]== 1 && a[pos-t]== 1) cnt++;
                    else
                    {
                         a[pos+t]= 1;
                        a[pos-t]= 1;
                    }
                }
                else if((pos+t)<=n)
                {
                    if(a[pos+t]== 1) cnt++;
                    else
                    {
                        a[pos+t]= 1;
                    }
                }
                else if((pos-t)>= 1)
                {
                    if(a[pos-t]== 1) cnt++;
                    else
                    {
                        a[pos-t]= 1;
                    }
                }
                else
                {
                    flag= 1;
                    break;
                }
            }

            if(cnt== K || flag== 1) break;
            t++;
        }
        printf("%lld\n", t);
    }
    return 0;
}


