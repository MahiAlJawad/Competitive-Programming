/*Header file starts here*/
//#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iterator>
#include<cctype>
#include<climits>
#include<string>
#include<sstream>
#include<cstring>
#include<ctime>
/*Header file ends here*/

/*Macro starts here*/
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
#define memz(x) memset(x, 0, sizeof(x));
#define memneg(x) memset(x, -1, sizeof(x));

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
#define t_areaWithPoints(x1, y1, x2, y2, x3, y3) abs(0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));//returns the area of a triangle formed by P1, p2, p3

//Base Conversions
#define toBin(bin, n) bin= bitset<8>(n).to_string()//returns a corresponding 8 bit Binary string 'bin' of integer 'n'
#define toOct(oct, n, ch) /*char ch[100]*/sprintf(ch, "%o", n); oct= ch;//returns a string 'oct'(maximum 100 length): Octal represent of number 'n'
#define toHex(hex, n, ch) /*char ch[100]*/sprintf(ch, "%x", n); hex= ch;//returns a string 'hex'(maximum 100 length): Hexadecimal represent of number 'n'
#define intToString(s, n, itos) /*stringstream itos;*/ itos<<n; s= itos.str();//converts a number 'n' to a string 's'
#define stringToint(n, s) stringstream stoi(s); stoi>>n;//converts a string 's' to a number 'n'---ONLY ONCE USABLE---

//Others
#define substring(s1, s2) strstr(s1.c_str(), s2.c_str())//returns true if s1 contains s2 in O(n^2) complexity
#define strCharRemove(s, c) s.erase(remove(s.begin(), s.end(), c), s.end());//Removes all character 'c' from the string 's'
#define strLastCharRemove(s) s.erase(s.end()-1)//Removes last(position is given by s.end()-1) character form string 's'
#define vectorEraseSingle(v, pos) v.erase(v.begin()+pos)//Erases an element from "pos' position in zero based index from the vector 'v'
#define vectorEraseRange(v, spos, fpos) v.erase(v.begin()+spos, v.begin()+fpos)//Erases range inclusive spos' to EXCLUSIVE 'fpos' from vector 'v'
#define lowerBound(v, elem) (lower_bound(v.begin(), v.end(), elem))-v.begin();/*returns the lower bound of 'elem' in integer(ZERO BASED INDEX), where lower bound means
the LEFTMOST index where there is any integer which is GREATER OR EQUAL to 'elem'.*/
#define upperBound(v, elem) (upper_bound(v.begin(), v.end(), elem))-v.begin();/*returns the upper bound of 'elem' in integer(ZERO BASED INDEX), where upper bound means
the LEFTMOST index where there is any integer which is GREATER than 'elem'.*/
#define setLowerBound(st, elem) st.lower_bound(elem));/*returns the lower bound ITERATOR of 'elem' in the stl set 'st', where lower bound means
the LEFTMOST index where there is any integer which is GREATER OR EQUAL to 'elem'.*/
#define setUpperBound(st, elem) st.upper_bound(elem));/*returns the upper bound ITERATOR of 'elem' in the stl set 'st', where upper bound means
the LEFTMOST index where there is any integer which is GREATER than 'elem'.*/

/*Macro ends here*/
#define mod 1000000007
using namespace std;

ll bigmod(ll a, ll b,ll m)
{
    ll x;
    if(b== 0) return 1;
    if(b%2== 0)
    {
        x= bigmod(a, b/2, m);
        return ((x%m)*(x%m))%m;
    }
    else
        return ((a%m)*bigmod(a, b-1, m)%m);
}

ll dp[100005];
int main()
{
    ll n, q;
    cin>>n>>q;

    string s;
    cin>>s;
    ll sum= 0, i;

    for(i= 0; i<n; i++)
    {
        if(s[i]== '1')
        {
            sum++;
            dp[i+1]= sum;
        }
        else dp[i+1]= sum;
    }
    ll sm1= 0, sm2= 0;

//    cout<<"dp: ";
//    for(i= 1; i<=n; i++) cout<<dp[i]<<" ";
//    cout<<endl;
    while(q--)
    {
        ll l, r;
        cin>>l>>r;

        ll z= (r-l)+1;
        ll x= dp[r]- dp[l-1];
        ll y= z-x;

        sm1= bigmod(2, x, mod)-1;
        sm2= (((sm1%mod)*(1- bigmod(2, y, mod)))*(-1))%mod;
        //cout<<x<<" "<<y<<endl;
        ll sm= ((sm1%mod)+(sm2%mod))%mod;
        cout<<sm<<"\n";
    }

    return 0;
}

