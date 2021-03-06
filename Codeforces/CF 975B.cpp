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


int main()
{
    ll a[15], i, j, add[15];
    for(i= 1; i<=14; i++) scanf("%lld", &a[i]);
    ll mx= neginf;
    for(i= 1; i<=14; i++)
    {
        memset(add, 0, sizeof(add));
        ll save= a[i];
        ll d= 14-i;
        if(a[i]<=d)
        {
            ll k= 1;
            for(j= i+1; k<=a[i]; j++)
            {
                add[j]+= 1;
                k++;
            }
        }
        else
        {
            ll x, y;
            ll z= a[i]- d;
            for(j= i+1; j<=14; j++) add[j]+=1;
            x= z/14;
            for(j= 1; j<=14; j++) add[j]+=x;
            y= z%14;
            for(j= 1; j<=y; j++) add[j]+=1;
        }
        a[i]= 0;
        /*cout<<"for i= "<<i<<endl;
        for(j= 1; j<=14; j++)
        {
            cout<<"a: "<<a[j]<<" add: "<<add[j]<<endl;
        }*/

        ll sum= 0;

        for(j= 1; j<=14; j++)
        {
            if((a[j]+add[j])%2== 0) sum+= a[j]+add[j];
        }
        //cout<<"sum: "<<sum<<endl;
        if(sum>mx) mx= sum;
        a[i]= save;
    }

    printf("%lld\n", mx);

    return 0;
}


