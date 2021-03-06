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
ll ar[25];
int main()
{
    ll n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);

    ll i;
    for(i= 1; i<=n; i++)
    {
        scanf("%lld", &ar[i]);
    }

    ll mid= n/2;
    ll j= n;
    bool f= 0;
    for(i= 1; i<=mid; i++, j--)
    {

            if((ar[i]== 0 && ar[j]== 1) || (ar[i]== 1 && ar[j]== 0))
            {
                f= 1;
                break;
            }

    }

    if(f)
    {
        printf("-1\n");
        return 0;
    }
    ll mn;
    if(a<b)
    {
        mn= a;
    }
    else mn= b;

    ll cost= 0;
    j= n;
    for(i= 1; i<=mid; i++, j--)
    {


            if(ar[i]== 2 && ar[j]== 2)
            {
                cost+= (2*mn);
            }
            else if(ar[i]== 1 && ar[j]== 2)
            {
                cost+= b;
            }
            else if(ar[i]== 0 && ar[j]== 2)
            {
                cost+= a;
            }
            else if(ar[i]== 2 && ar[j]== 1)
            {
                cost+= b;
            }
            else if(ar[i]== 2 && ar[j]== 0)
            {
                cost+= a;
            }

    }
    if(n%2== 1 && ar[mid+1]== 2)
    {
        cost+= mn;
    }

    printf("%lld\n", cost);
    return 0;
}


