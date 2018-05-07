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
#define n 10000000
using namespace std;


//Needed functions
ll modulo(ll x, ll m)//for positive and negative modulo
{
    //define later when m>0 or m<0?
    if(x>=0) return x%m;
    ll y= (-1*x)%m;
    if(y== 0) return 0;
    return (m- y);
}


vector<ll> prime;
ll mark[n];




int main()
{
    ll x;
    scanf("%lld", &x);
    memset(mark, 0, sizeof(mark));
    ll num, i, j;
    ll limit= sqrt(n+1);
    mark[1]= 1;
    prime.push_back(2);
    for(i= 4; i<=n; i+= 2)
        mark[i]= 1;

    for(i= 3; i<=n; i+= 2)
    {
        if(!mark[i])
        {
            prime.push_back(i);
            if(i<= limit)
            {
                for(j= i*i; j<= n; j+= 2*i)
                    mark[j]= 1;
            }
        }
    }


    for(i= 1; i<=x; i++)
    {
        if(i!= 1) printf(" ");
        printf("%lld", prime[i-1]);
    }

    printf("\n");



    return 0;
}




