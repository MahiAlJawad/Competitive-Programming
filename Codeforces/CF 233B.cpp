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
#define strCharRemove(s, c) s.erase(remove(s.begin(), s.end(), c), s.end());//Removes all character 'c' from the string 's'
#define strLastCharRemove(s) s.erase(s.end()-1)//Removes last(position is given by s.end()-1) character form string 's'
using namespace std;

ll sx(ll x)
{
    string s;
    stringstream itos;
    intToString(s, x, itos);
    ll sz= s.size();

    ll i, sum= 0;
    for(i= 0; i<sz; i++)
    {
        ll y= s[i]-48;
        sum+= y;
    }

    return sum;
}

int main()
{
    ll n, i;
    scanf("%lld", &n);
    ll mn= inf;
    for(i= 1; i<=90; i++)
    {
        ll ans1= inf, ans2= inf;
        ll b= i;
        ll d=(b*b)+(4*n);
        double temp= sqrt(d);
        ll sqd= temp;
        double temp1= sqd;
        if((temp1-temp)!= 0)
        {
            continue;
        }
        ll x1= sqd-b;
        ll x2= ((-1)*sqd)-b;

        if(x1>0)
        {
            ans1= x1/2;
            if(sx(ans1)!= i) ans1= inf;
        }
        if(x2>0)
        {
            ans2= x2/2;
            if(sx(ans2)!= i) ans2= inf;
        }
        //cout<<"ans1 , ans2: "<<ans1<< " "<<ans2<<endl;
        mn= min(mn, min(ans1, ans2));

    }

    if(mn!= inf) printf("%lld\n", mn);
    else printf("-1\n");

    return 0;
}


