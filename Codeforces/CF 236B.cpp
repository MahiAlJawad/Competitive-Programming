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
//main program starts here

ll dp[1000005];

ll nod(ll n)
{
    if(dp[n]!= -1) return dp[n];
    ll i, j, num, p;
    map<ll, ll> factor;
    num= n;// saving n, so that it doesn't manipulate
    for(i= 2; i*i<=n; i++)
    {
        if(n%i== 0)// n is firstly divisible by a number which is a prime, hence here i is prime if the condition is true
        {
            while(n%i== 0)
            {
                factor[i]++;
                n/= i;
            }
        }
    }
    if(n>1)
    {
        factor[n]++;
    }
    //Generating SOD & NOD from the Prime Factors

    int nod= 1;
    forit(it, factor)
    {
        nod*= (it->second+1);
    }


    dp[num]= nod;
    return nod;
}


int main()
{
    ll a, b, c, i, j, k, x, sum= 0;
    scanf("%lld%lld%lld", &a, &b, &c);
    memset(dp, -1, sizeof(dp));

    for(i= 1; i<=a; i++)
    {
        for(j= 1; j<=b; j++)
        {
            for(k= 1; k<=c; k++)
            {
                x= i*j*k;
                //cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<"\n";
                sum+= nod(x);
                if(sum>=1073741800)
                {
                    sum%= 1073741824;
                }
            }
        }
    }

    printf("%lld\n", sum);

    return 0;
}


