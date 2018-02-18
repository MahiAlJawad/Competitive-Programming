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

struct sell
{
    lng x= 0;
    lng y= 0;
    lng z= 0;
};

bool operator <(const sell &a, const sell &b)
{
    return a.z<b.z;
}

int main()
{
    lng n, f, i;
    scanf("%lld%lld", &n, &f);
    priority_queue<sell> pq;
    for(i= 1; i<=n; i++)
    {
        sell s;
        lng x, y;
        scanf("%lld%lld", &x, &y);
        s.x= x;
        s.y= y;
        s.z= min(x*2, y)- min(x, y);
        pq.push(s);
    }

    lng ans= 0;
    for(i= 1; i<=f; i++)
    {
        sell s;
        s= pq.top();
        pq.pop();
        ans+= min(s.x*2, s.y);
    }
    while(!pq.empty())
    {
        sell s;
        s= pq.top();
        pq.pop();
        ans+= min(s.x, s.y);
    }

    printf("%lld\n", ans);
    return 0;
}


