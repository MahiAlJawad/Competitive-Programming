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
#define lld I64d//for CF submissions
#define pi acos(-1.0)
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c));//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
#define forit(it,s) for(__typeof((s).end()) it=(s).begin(); it!= (s).end(); it++)
#define gcd(a,b) __gcd(a,b)
#define string_reverse(s) reverse(s.begin(), s.end())//Vector also can be reversed with this function
using namespace std;

lng a[10005], b[10005];

int main()
{
    lng n, m, i, j;
    scanf("%lld", &n);
    for(i= 1; i<=n; i++)
        scanf("%lld", &a[i]);

    scanf("%lld", &m);

    for(i= 1; i<=m; i++)
        scanf("%lld", &b[i]);


    map<lng, lng> mp;
    lng mx= -1;
    for(i= 1; i<=n; i++)
    {
        for(j= 1; j<=m; j++)
        {
            if(b[j]%a[i]== 0)
            {
                lng x= b[j]/a[i];
                mp[x]++;
                if(x>mx) mx= x;
            }
        }
    }
    //cout<<mx<<endl;
    printf("%lld\n", mp[mx]);



    return 0;
}


