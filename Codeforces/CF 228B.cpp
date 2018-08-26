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

ll a[53][53], b[53][53];

int main()
{
    ll na, ma, nb, mb;

    ll  i, j;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%lld%lld", &na, &ma);
    string s;
    for(i= 1; i<=na; i++)
    {
        cin>>s;
        for(j= 0; j<ma; j++)
        {
            a[i][j+1]= (s[j]-48);
        }
    }

    scanf("%lld%lld", &nb, &mb);

    for(i= 1; i<=nb; i++)
    {
        cin>>s;
        for(j= 0; j<mb; j++)
        {
            b[i][j+1]= (s[j]-48);
        }
    }





    ll xmin, xmax, ymin, ymax;

    xmin= (-1)*(na-1);
    xmax= nb-1;
    ymin= (-1)*(ma-1);
    ymax= mb-1;

    ll x, y;
    ll mx= neginf;
    ll ansx= -1, ansy= -1;
    for(x= xmin; x<=xmax; x++)
    {
        for(y= ymin; y<=ymax; y++)
        {
            //cout<<"x: "<<x<< " y: "<<y;
            ll cnt= 0;
            for(i= 1; i<=na; i++)
            {
                for(j= 1; j<=ma; j++)
                {
                    if((i+x)<=nb && (j+y)<=mb)
                    {
                        //cout<< " noti: "<<i<< " "<<j<< " "<<i+x<< " "<<j+y<<endl;
                        //cout<< " aij, bixjy: "<<a[i][j]<< " "<<b[i+x][j+y]<<endl;
                        if(a[i][j]== 1 && b[i+x][j+y]== 1)
                        {
                            //rh;
                            cnt++;
                            //cout<<"i, j, x, y"<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
                        }
                    }
                }
            }

            //cout<<" cnt "<<cnt<<endl;

            if(cnt>mx)
            {
                mx= cnt;
                ansx= x;
                ansy= y;
            }
        }
    }

    printf("%lld %lld\n", ansx, ansy);






    return 0;
}


