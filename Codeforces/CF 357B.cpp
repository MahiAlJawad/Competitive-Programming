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
#define toBin(bin, n) bin= bitset<8>(n).to_string()//returns a corresponding 8 bit Binary string 'bin' of integer 'n'
#define toOct(oct, n, ch) /*char ch[100]*/sprintf(ch, "%o", n); oct= ch;//returns a string 'oct'(maximum 100 length): Octal represent of number 'n'
#define toHex(hex, n, ch) /*char ch[100]*/sprintf(ch, "%x", n); hex= ch;//returns a string 'hex'(maximum 100 length): Hexadecimal represent of number 'n'
#define negmod(ans, x, m) ll y= (-1*x)%m; if(y== 0) ans= 0; else ans= m-y;//for negative mod only i.e. when x<0. Undefined when m<0
#define intToString(s, n, itos) /*stringstream itos;*/ itos<<n; s= itos.str();//converts a number 'n' to a string 's'
#define stringToint(n, s) stringstream stoi(s); stoi>>n;//converts a string 's' to a number 'n'---ONLY ONCE USABLE---
#define substring(s1, s2) strstr(s1.c_str(), s2.c_str())//returns true if s1 contains s2 in O(n^2) complexity
using namespace std;




ll color[100005];

int main()
{
    ll n, m, i;
    scanf("%lld%lld", &n, &m);
    memset(color, 0, sizeof(color));
    //memset(vis, 0, sizeof(vis));


    while(m--)
    {
        ll p= 0, x[4], clr[4], cp;
        for(i= 1; i<=3; i++)
        {
            scanf("%lld", &x[i]);
            if(color[x[i]]!= 0)
            {
                p= i;
                cp= color[x[i]];
            }
        }
        if(p== 0)
        {
            color[x[1]]= 1;
            color[x[2]]= 2;
            color[x[3]]= 3;
        }
        else
        {
            ll cl1, cl2;
            if(cp== 1)
            {
                cl1= 2;
                cl2= 3;
            }
            else if(cp== 2)
            {
                cl1= 1;
                cl2= 3;
            }
            else if(cp== 3)
            {
                cl1= 1;
                cl2= 2;
            }
            if(p== 1)
            {
                color[x[2]]= cl1;
                color[x[3]]= cl2;
            }
            else if(p== 2)
            {
                color[x[1]]= cl1;
                color[x[3]]= cl2;
            }
            else if(p== 3)
            {
                color[x[1]]= cl1;
                color[x[2]]= cl2;
            }
        }
    }

    for(i= 1; i<=n; i++)
    {
        if(i!= 1) printf(" ");
        printf("%lld", color[i]);
    }

    return 0;
}


