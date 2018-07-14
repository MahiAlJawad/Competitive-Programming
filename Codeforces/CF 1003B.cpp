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
#define lcm(a, b) (a*b)/gcd(a, b);
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

int main()
{
    ll a, b, x, i;

    scanf("%lld%lld%lld", &a, &b, &x);
    char p;

    if(a>b) p= '0';
    else p= '1';

    ll ones= b;
    ll zeros= a;

    string s;

    for(i= 1; i<= x; i++)
    {
       s+= p;
       if(p== '1') ones--, p= '0';
       else zeros--, p= '1';

    }

    if(s[0]== s[x-1])
    {
        if(s[0]== '0')
        {
            for(i= 1; i<=ones; i++) s+= '1';
        }
        else
        {
            for(i= 1; i<=zeros; i++) s+= '0';
        }

        if(s[0]== '0')
        {
            for(i= 1; i<=zeros; i++) s= '0'+s;
        }
        else for(i= 1; i<=ones; i++) s= '1'+s;
    }
    else
    {
        if(s[x-1]== '0')
        {
            for(i= 1; i<=zeros; i++) s+= '0';
            for(i= 1; i<=ones; i++) s+= '1';
        }
        else
        {
            for(i= 1; i<=ones; i++) s+= '1';
            for(i= 1; i<=zeros; i++) s+= '0';
        }
    }

    cout<<s<<"\n";

    return 0;
}

