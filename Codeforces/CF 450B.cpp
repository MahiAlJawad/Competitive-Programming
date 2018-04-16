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
#define mod 1000000007
using namespace std;

ll modulo(ll x, ll m)
{
    //define later when m>0 or m<0
    if(x>=0) return x%m;
    ll y= (-1*x)%m;
    if(y== 0) return 0;
    return (m- y);

}

int main()
{
    ll f1, f2, n;

    scanf("%lld%lld%lld", &f1, &f2, &n);
    ll ans;
    if(n== 1)
    {
        ans= modulo(f1, mod);
    }
    else if(n== 2)
    {
        ans= modulo(f2, mod);
    }
    else if(n>=3)
    {
        ll p= n/3;
        ll r= n%3;
        if(p%2== 1)
        {
            if(r== 0) ans= modulo(f2-f1, mod);
            else if(r== 1) ans= modulo(-f1, mod);
            else ans= modulo(-f2, mod);
        }
        else
        {
            if(r== 0) ans= modulo(f1-f2, mod);
            else if(r== 1) ans= modulo(f1, mod);
            else ans= modulo(f2, mod);
        }
    }


    printf("%lld\n", ans);


    return 0;
}


