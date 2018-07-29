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
    string s;
    cin>>s;
    ll i, j, len= s.size();
    ll zr= 0, on= 0, tw= 0;
    bool f= 0;
    string ans;
    for(i= 0; i<len; i++)
    {

        if(f== 0 && s[i]== '2')
        {
            f= 1;
            tw++;
        }
        else if(f== 1 && s[i]== '0')
        {
            for(j= 1; j<=zr; j++) ans+= '0';
            for(j= 1; j<=on; j++) ans+= '1';
            for(j= 1; j<=tw; j++) ans+= '2';
            ans+= '0';
            zr= 0;
            on= 0;
            tw= 0;
            f= 0;
        }
        else if(f== 0 && s[i]== '0') zr++;
        else if(s[i]== '1') on++;
        else if(s[i]== '2') tw++;
    }

    for(i= 1; i<=zr; i++) ans+= '0';
    for(i= 1; i<=on; i++) ans+= '1';
    for(i= 1; i<=tw; i++) ans+= '2';

    len= ans.size();
    f= 0;
    zr= 0;
    on= 0;
    ll p= -1;
    for(i= 0; i<len; i++)
    {
        if(f==  0 && ans[i]== '2')
        {
            f= 1;
            p= i;
        }
        else if(f== 0 && ans[i]== '0') zr++;
        else if(ans[i]== '1') on++;
    }
    if(p== -1)
    {
        cout<<ans<<"\n";
        return 0;
    }
    s= "";

    for(i= 1; i<=zr; i++) s+= '0';
    for(i= 1; i<=on; i++) s+= '1';

    for(i= p; i<len; i++)
    {
        if(ans[i]!= '1') s+=  ans[i];
    }

    cout<<s<<"\n";

    return 0;
}

