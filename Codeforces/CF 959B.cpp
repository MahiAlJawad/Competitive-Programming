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
#define inf LONG_LONG_MAX
#define neginf LONG_LONG_MIN
#define rh cout<<"Reached Here\n";

using namespace std;
string s[100005];

int main()
{
    lng n, k, m, i, x, j;

    scanf("%lld%lld%lld", &n, &k, &m);

    for(i= 1; i<=n; i++)
        cin>>s[i];

    map<string, lng> mp;
    map<string, lng> grp;
    for(i= 1; i<=n; i++)
    {
        scanf("%lld", &x);
        mp[s[i]]= x;
        grp[s[i]]= x;
    }
    lng a;
    for(i= 1; i<=k; i++)
    {
        scanf("%lld", &x);
        lng mn= inf;
        vector<string> v;
        for(j= 1; j<=x; j++)
        {
            scanf("%lld", &a);
            mn= min(mp[s[a]], mn);
            v.pb(s[a]);
        }

        lng sz= v.size();
        for(j= 0; j<sz; j++)
        {
            grp[v[j]]= mn;
        }

    }

    string msg;
    lng cnt= 0;
    for(i= 1; i<=m; i++)
    {
        cin>>msg;
        cnt+= grp[msg];
    }
    printf("%lld\n", cnt);

    return 0;
}


