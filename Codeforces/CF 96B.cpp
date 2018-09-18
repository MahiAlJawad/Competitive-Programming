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

char c[20];

void solve(string s)
{
    ll len= s.size();
    if(len%2== 1) len++;
    else len+= 2;

    ll p= len/2;
    ll i;
    string ans;
    for(i= 0; i<p; i++) ans+= "4";
    for(i= p; i<len; i++) ans+= "7";

    cout<<ans<<"\n";
}

ll four[20], seven[20];
int main()
{
    string s;
    ll i;
    cin>>s;
    ll len= s.size();
    if(len%2== 1)
    {
        solve(s);
        return 0;
    }
    bool cs1= 0, cs2= 0;

    ll pos1, pos2;

    for(i= 0; i<len; i++)
    {
        if(s[i]<= '7' && s[i]!= '7' && s[i]!= '4')
        {
            cs1= 1;
            pos1= i;
            break;
        }
        if(s[i]> '7')
        {
            cs2= 1;
            pos2= i;
            break;
        }
    }

    if(cs1)
    {
        string ans;
        ll fr= 0, svn= 0;
        for(i= 0; i<pos1; i++)
        {
            ans+= s[i];
            if(s[i]== '4') fr++;
            else if(s[i]== '7') svn++;
        }

        if(s[pos1]< '4')
        {
            ans+= '4';
            fr++;
        }
        else if(s[pos1]<'7')
        {
            ans+= '7';
            svn++;
        }

        ll mid= len/2;

        if(svn>mid || fr>mid)
        {
            solve(s);
            return 0;
        }

        ll x= mid- fr;

        for(i= 1; i<=x; i++) ans+= '4';

        x= mid- svn;

        for(i= 1; i<=x; i++) ans+= '7';
        cout<<ans<<"\n";
    }
    else if(cs2)
    {
        string ans;
        ll x= -1;

        for(i= pos2; i>=0; i--)
        {
            if(s[i]== '4')
            {
                x= i;
                break;
            }
        }
        if(x== -1)
        {
            solve(s);
            return 0;
        }
        ll fr= 0, svn= 0;

        for(i= 0; i<x; i++)
        {
            ans+= s[i];
            if(s[i]== '4') fr++;
            else if(s[i]== '7') svn++;
        }
        ans+= '7';
        svn++;

        ll mid= len/2;

        if(svn>mid || fr>mid)
        {
            solve(s);
            return 0;
        }

        x= mid- fr;

        for(i= 1; i<=x; i++) ans+= '4';

        x= mid- svn;

        for(i= 1; i<=x; i++) ans+= '7';
        cout<<ans<<"\n";

    }
    else
    {
        ll fr= 0, svn= 0;
        for(i= 0; i<len; i++)
        {
            if(s[i]== '4') fr++;
            else if(s[i]== '7') svn++;
        }
        if(fr== svn)
        {
            cout<<s<<"\n";
            return 0;
        }
        else if(fr== 0)
        {
            solve(s);
            return 0;
        }
        memset(four, 0, sizeof(four));
        memset(seven, 0, sizeof(seven));

        for(i= 0; i<len; i++)
        {
            if(s[i]== '4')
            {
                if(i== 0) four[i]= 1;
                else four[i]= four[i-1]+1;
                seven[i]= seven[i-1];
            }
            else if(s[i]== '7')
            {
                if(i== 0) seven[i]= 1;
                else seven[i]= seven[i-1]+1;
                four[i]= four[i-1];
            }
        }
        ll p= -1;
        ll mid= len/2;
        for(i= len-1; i>=0; i--)
        {
            if(s[i]== '4')
            {
                ll fr= four[i]-1;
                ll svn= seven[i]+1;
                if(fr<=mid && svn<=mid)
                {
                    ll fnd= mid- fr;
                    ll snd= mid- svn;
                    ll x= (len- i)-1;
                    if(x== (fnd+snd))
                    {
                        ll j;
                        string ans;
                        for(j= 0; j<i; j++) ans+= s[j];
                        ans+= '7';
                        for(j= 1; j<=fnd; j++) ans+= '4';
                        for(j= 1; j<=snd; j++) ans+= '7';
                        cout<<ans<<"\n";
                        return 0;
                    }
                }
            }
        }
        solve(s);
        return 0;

    }



    return 0;
}


