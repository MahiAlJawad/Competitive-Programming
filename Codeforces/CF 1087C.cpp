/***"In the name of Allah(swt), the most gracious, most merciful. Allah(swt) blesses with knowledge whom he wants."***/
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
#define vectorEraseRange(v, spos, fpos) v.erase(v.begin()+spos, v.begin()+fpos)//Erases range inclusive spos' to EXCLUSIVE(without) 'fpos' from vector 'v'
#define lowerBound(v, elem) (lower_bound(v.begin(), v.end(), elem))-v.begin();/*returns the lower bound of 'elem' in integer(ZERO BASED INDEX), where lower bound means
the LEFTMOST index where there is any integer which is GREATER OR EQUAL to 'elem'.*/
#define upperBound(v, elem) (upper_bound(v.begin(), v.end(), elem))-v.begin();/*returns the upper bound of 'elem' in integer(ZERO BASED INDEX), where upper bound means
the LEFTMOST index where there is any integer which is GREATER than 'elem'.*/
#define setLowerBound(st, elem) st.lower_bound(elem));/*returns the lower bound ITERATOR of 'elem' in the stl set 'st', where lower bound means
the LEFTMOST index where there is any integer which is GREATER OR EQUAL to 'elem'.*/
#define setUpperBound(st, elem) st.upper_bound(elem));/*returns the upper bound ITERATOR of 'elem' in the stl set 'st', where upper bound means
the LEFTMOST index where there is any integer which is GREATER than 'elem'.*/

/*Macro ends here*/
//add vector descending sorting , min pq

using namespace std;

struct node
{
    ll x, y;

    bool operator <(const node &nd) const
    {
        if(x== nd.x) return y<nd.y;
        return x<nd.x;
    }
};

int main()
{
    ll i;
    vector<node> v;

    for(i= 1; i<=3 ; i++)
    {
        ll x, y;
        cin>>x>>y;
        node nd;
        nd.x= x;
        nd.y = y;
        v.pb(nd);
    }
    sort(v.begin(), v.end());

    node a, b, c;
    for(i= 0; i<v.size(); i++)
    {
        node nd= v[i];
        if(i== 0)
        {
            a.x= nd.x;
            a.y= nd.y;
        }
        else if(i== 1)
        {
            b.x= nd.x;
            b.y= nd.y;
        }
        else
        {
            c.x= nd.x;
            c.y= nd.y;
        }
    }

    ll d1, d2;

    if(a.y== b.y)
    {
        d1= (b.x-a.x)+1;

        for(i= a.x+1; i<b.x; i++)
        {
            node nd;
            nd.x= i;
            nd.y= a.y;
            v.pb(nd);
        }

    }
    else
    {
        d1= 2+ (b.x-a.x) + (abs(b.y-a.y)-1);
        for(i= a.x+1; i<=b.x; i++)
        {
            node nd;
            nd.x= i;
            nd.y= a.y;
            v.pb(nd);
        }
        ll mn= min(a.y, b.y);
        ll mx= max(a.y, b.y);
        for(i= mn+1; i<mx; i++)
        {
            node nd;
            nd.x= b.x;
            nd.y= i;
            v.pb(nd);
        }
    }

    if(c.y>=min(a.y, b.y) && c.y<= max(a.y, b.y))
    {

        d2= c.x-b.x;

        for(i= b.x+1; i<c.x; i++)
        {
            node nd;
            nd.x= i;
            nd.y= c.y;
            v.pb(nd);
        }
    }
    else if(c.y<min(a.y, b.y))
    {
        ll mn= min(a.y, b.y);
        d2= (c.x-b.x)+ (mn- c.y);
        for(i= b.x+1; i<= c.x; i++)
        {
            node nd;
            nd.x= i;
            nd.y= mn;
            v.pb(nd);
        }
        for(i= c.y+1; i<mn; i++)
        {
            node nd;
            nd.x= c.x;
            nd.y= i;
            v.pb(nd);
        }
    }
    else
    {
        ll mx= max(a.y, b.y);
        d2= (c.x-b.x)+ (c.y- mx);
        for(i= b.x+1; i<= c.x; i++)
        {
            node nd;
            nd.x= i;
            nd.y= mx;
            v.pb(nd);
        }
        for(i= mx+1; i<c.y; i++)
        {
            node nd;
            nd.x= c.x;
            nd.y= i;
            v.pb(nd);
        }
    }

    cout<<(d1+d2)<<"\n";
    ll sz= v.size();
    set<node> st;
    for(i= 0; i<sz; i++)
    {
        node nd= v[i];
        st.insert(nd);
    }

    forit(it, st){
        node nd= *it;
        cout<<nd.x<<" "<<nd.y<<endl;
    }


    return 0;
}





