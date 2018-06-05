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
ll a[105][105], b[105][105];
int main()
{
    ll m, n, i, j, k;
    scanf("%lld%lld", &m, &n);
    for(i= 1; i<=m; i++)
    {
        for(j= 1; j<=n; j++) scanf("%lld", &b[i][j]);
    }

    memset(a, -1, sizeof(a));

    for(i= 1; i<=m; i++)
    {
        for(j= 1; j<=n; j++)
        {
            if(b[i][j]== 0)
            {
                for(k= 1; k<=n; k++) a[i][k]= 0;
                for(k= 1; k<=m; k++) a[k][j]= 0;
            }
        }
    }

    for(i= 1; i<=m; i++)
    {
        for(j= 1; j<=n; j++)
        {
            if(b[i][j]== 1)
            {
                bool flag= 0;
                for(k= 1; k<=n; k++)
                    if(a[i][k]== -1)
                    {
                        flag= 1;
                        break;
                    }

                if(!flag)
                {
                    for(k= 1; k<=m; k++)
                        if(a[k][j]== -1)
                        {
                            flag= 1;
                            break;
                        }
                }

                if(!flag){
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }

    printf("YES\n");

    for(i= 1; i<=m; i++)
    {
        for(j= 1; j<=n; j++)
        {
            if(j!= 1) printf(" ");
            if(a[i][j]== -1) printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}


