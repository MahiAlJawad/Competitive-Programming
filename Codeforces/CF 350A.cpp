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
#define lld I64d//for CF submissions
#define pi acos(-1.0)
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c));//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
#define forit(it,s) for(__typeof((s).end()) it=(s).begin(); it!= (s).end(); it++)
#define gcd(a,b) __gcd(a,b)
#define string_reverse(s) reverse(s.begin(), s.end())//Vector also can be reversed with this function
#define inf LONG_LONG_MAX
#define neginf LONG_LONG_MIN
#define rh cout<<"Reached Here\n";
#define sz 150005
using namespace std;


//Needed functions
ll modulo(ll x, ll m)//for positive and negative modulo
{   //define later when m>0 or m<0?
    if(x>=0) return x%m;
    ll y= (-1*x)%m;
    if(y== 0) return 0;
    return (m- y);
}




vector<ll> a, b;

int main()
{
    ll n, m, i, x;
    scanf("%lld%lld", &n, &m);

    for(i= 1; i<=n; i++)
    {
        scanf("%lld", &x);
        a.pb(x);
    }

    for(i= 1; i<=m; i++)
    {
        scanf("%lld", &x);
        b.pb(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll p= a[0]*2, v= a[n-1];

    while(1)
    {
        if(p<=v)
        {
            break;
        }
        else v++;
    }

    if(v< b[0]) printf("%lld\n", v);
    else printf("-1\n");

    return 0;
}



