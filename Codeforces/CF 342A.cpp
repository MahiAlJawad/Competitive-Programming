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
using namespace std;


//Needed functions
ll modulo(ll x, ll m)//for positive and negative modulo
{   //define later when m>0 or m<0?
    if(x>=0) return x%m;
    ll y= (-1*x)%m;
    if(y== 0) return 0;
    return (m- y);
}


ll a[10];
vector<ll> v[34000];
int main()
{
    ll n, i, x, j;
    scanf("%lld", &n);
    memset(a, 0, sizeof(a));
    for(i= 1; i<=n; i++)
    {
        scanf("%lld", &x);
        a[x]++;
    }


    bool flag= 1;
    ll grp= n/3;
    //cout<<grp<<endl;
    for(i= 1; i<=grp; i++)
    {
        ll k= 0, p;
        for(j= 1; j<=7; )
        {
            if(a[j]!= 0)
            {
                if(k== 0)
                {
                    k++;
                    a[j]--;
                    v[i].pb(j);
                    p= j;
                }
                else if(j%p== 0)
                {
                    k++;
                    a[j]--;
                    v[i].pb(j);
                    p= j;
                }

            }
            if(k==3) break;
            j++;
        }
        if(k<3)
        {
            flag= 0;
            break;
        }
    }

    if(flag)
    {
        for(i= 1; i<=grp; i++)
        {
            for(j= 0; j<3; j++)
            {
                if(j!= 0) printf(" ");
                cout<<v[i][j];
            }
            cout<<"\n";
        }
    }
    else printf("-1\n");


    return 0;
}


