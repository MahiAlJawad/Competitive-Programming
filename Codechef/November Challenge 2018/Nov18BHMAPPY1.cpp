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
#define rh cout<<"Reached Here\n"
#define inf LONG_LONG_MAX
#define neginf LONG_LONG_MIN
#define forit(it,s) for(__typeof((s).end()) it=(s).begin(); it!= (s).end(); it++)
#define string_reverse(s) reverse(s.begin(), s.end())//Vector also can be reversed with this function
//Add memsets
//Geometry & Maths
#define gcd(a,b) __gcd(a,b)
#define lcm(a, b) (a*b)/gcd(a, b)
#define pi acos(-1.0)
#define negmod(ans, x, m) ll y= (-1*x)%m; if(y== 0) ans= 0; else ans= m-y;//for negative mod only i.e. when x<0. Undefined when m<0
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c))//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
#define pointPos(x1, y1, x2, y2, x3, y3) ((x2-x1)*(y3-y1))-((x3-x1)*(y2-y1));/*returns NEGATIVE if the Point P3 is on the RIGHT side of the line P1P2,
else returns POSITIVE in case of LEFT and ZERO when the point is on the line*/

//Base Conversions
#define toBin(bin, n) bin= bitset<8>(n).to_string()//returns a corresponding 8 bit Binary string 'bin' of integer 'n'
#define toOct(oct, n, ch) /*char ch[100]*/sprintf(ch, "%o", n); oct= ch;//returns a string 'oct'(maximum 100 length): Octal represent of number 'n'
#define toHex(hex, n, ch) /*char ch[100]*/sprintf(ch, "%x", n); hex= ch;//returns a string 'hex'(maximum 100 length): Hexadecimal represent of number 'n'
#define intToString(s, n, itos) /*stringstream itos;*/ itos<<n; s= itos.str();//converts a number 'n' to a string 's'
#define stringToint(n, s) stringstream stoi(s); stoi>>n;//converts a string 's' to a number 'n'---ONLY ONCE USABLE---

#define substring(s1, s2) strstr(s1.c_str(), s2.c_str())//returns true if s1 contains s2 in O(n^2) complexity
#define strCharRemove(s, c) s.erase(remove(s.begin(), s.end(), c), s.end());//Removes all character 'c' from the string 's'
#define strLastCharRemove(s) s.erase(s.end()-1)//Removes last(position is given by s.end()-1) character form string 's'
#define vectorEraseSingle(v, pos) v.erase(v.begin()+pos)//Erases an element from "pos' position in zero based index from the vector 'v'
#define vectorEraseRange(v, spos, fpos) v.erase(v.begin()+spos, v.begin()+fpos)//Erases range inclusive spos' to EXCLUSIVE 'fpos' from vector 'v'


//TODO: Make these MACRO and also AREA of tangle with three coords.*****Lowerbound, UpperBound, 'set' lower-upper bound
using namespace std;

ll dp[500005];

int main()
{
    ll n, q, k;
    ll i, j;
    scanf("%lld%lld%lld", &n, &q, &k);
    string s;
    for(i= 1; i<=n; i++)
    {
        char c;
        cin>>c;
        s+= c;
    }

    s= s+s+s+s+s;
    string_reverse(s);
    memset(dp, 0, sizeof(dp));
    string qry;
    cin>>qry;

    ll sz= s.size();
    ll cnt= 0;
    //cout<<"s: "<<s<<endl;
    for(i= 0; i<sz; i++)
    {
        if(s[i]== '0') cnt= 0;
        else
        {
            cnt++;
            dp[i]= cnt;
        }
    }
//    cout<<"print: ";
//    for(i= 0; i<sz; i++)
//    {
//        cout<<dp[i]<<" ";
//    }
//    cout<<endl;

    ll mx= neginf;
    ll b, e;
    for(i= 0; i<n; i++)
    {
        if(dp[i]>=mx) mx= dp[i], e= i;
    }
    b= (e-mx)+1;
    if(mx== 0)
    {
        b= -1;
        e= -1;
    }

    ll d;
    if(mx== 0) d=0;
    else d= (e-b)+1;
//    cout<<endl<<endl<<endl;
    //cout<<" b: e: "<<b<<" "<<e<<endl;
    ll l= 0, r= n-1;
    for(i= 0; i<q; i++)
    {
        if(qry[i]== '!')
        {
            l++;
            r++;
            if(l>b && l>e) b= -1, e= -1;
            else if(l>b && l<=e) b= l;

            if(b== -1 && e== -1) d= 0;
            else d= (e-b)+1;

            if(s[r]== '1')
            {
                //cout<<"d: "<<d<<endl;
                if((e+1)== r && d!= 0)
                {
                    e++;
                }
                else //if(dp[r]>=d && d!= 0)
                {
                    ll x= max(((r-dp[r])+1), l);
                    ll y= r;
                    ll z= (y-x)+1;
                    if(z>=d)
                    {
                        b= x;
                        e= y;
                    }
                }
                //cout<<" b: e: "<<b<<" "<<e<<endl;
            }
            //else cout<<" b: e: "<<b<<" "<<e<<endl;
            if(b== -1 && e== -1) d= 0;
            else d= (e-b)+1;

        }
        else
        {
            //cout<<b<<" "<<e<<" ";
            if(d>k) cout<<k<<"\n";
            else cout<<d<<"\n";
        }
    }


    return 0;
}
/*
4 9 10
0 0 1 1
?!?!?!?!?


3 7 10
0 1 1
?!?!?!?

1 7 10
1
?!?!?!?

4 13 10
1 0 1 1
?!?!?!?!?!?!?
*/
