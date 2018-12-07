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

using namespace std;

struct node
{
    ll b, w;
};


int main()
{
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n, m;
        cin>>n>>m;
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        ll total= (n*m);
        ll w;
        if(m%2== 0)
        {
            w= n*(m/2);
        }
        else
        {
            ll x= ceil((double)m/2.0);
            if(n%2== 0)
            {
                w= (n/2)*(x+(x-1));
            }
            else
            {
                ll temp= n-1;
                w= ((temp/2)*(x+(x-1)))+x;
            }
        }
        ll b= (total- w);
        node full;
        full.b= b;
        full.w= w;

        //
        ll mm= x4-x3+1;
        ll nn= y4-y3+1;
        total= mm*nn;
        if(mm%2== 0)
        {
            w= nn*(mm/2);
        }
        else
        {
            ll x= ceil((double)mm/2.0);
            if(nn%2== 0)
            {
                w= (nn/2)*(x+(x-1));
            }
            else
            {
                ll temp= nn-1;
                w= ((temp/2)*(x+(x-1)))+x;
            }
        }
        b= total- w;

        node B;

        if((x3+y3)%2== 1)//i.e. black
        {
            swap(b, w);
            B.b= b;
            B.w= w;
        }
        else
        {
            B.b= b;
            B.w= w;
        }

        //cout<<w<<" "<<b<<endl;
        //
        mm= x2-x1+1;
        nn= y2-y1+1;
        total= mm*nn;
        if(mm%2== 0)
        {
            w= nn*(mm/2);
        }
        else
        {
            ll x= ceil((double)mm/2.0);
            if(nn%2== 0)
            {
                w= (nn/2)*(x+(x-1));
            }
            else
            {
                ll temp= nn-1;
                w= ((temp/2)*(x+(x-1)))+x;
            }
        }
        b= total- w;

        node A;

        if((x1+y1)%2== 1)//i.e. black
        {
            swap(b, w);
            A.b= b;
            A.w= w;
        }
        else
        {
            A.b= b;
            A.w= w;
        }
        //cout<<w<<" "<<b<<endl;

        if((x1>=x3 && x1<=x4) && (y1>=y3 && ))
        {
            rh;
            ll p= max(x1, x3);
            ll q= max(y1, y3);
            ll r= min(x2, x4);
            ll s= min(y2, y4);
            //cout<<"pqrs: ";
            // cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;

            full.w-= B.w;
            full.b+= B.w;

            //
            mm= r-p+1;
            nn= s-q+1;
            total= mm*nn;
            if(mm%2== 0)
            {
                w= nn*(mm/2);
            }
            else
            {
                ll x= ceil((double)mm/2.0);
                if(nn%2== 0)
                {
                    w= (nn/2)*(x+(x-1));
                }
                else
                {
                    ll temp= nn-1;
                    w= ((temp/2)*(x+(x-1)))+x;
                }
            }
            b= total- w;

            node C;

            if((p+q)%2== 1)//i.e. black
            {
                swap(b, w);
                C.b= b;
                C.w= w;
            }
            else
            {
                C.b= b;
                C.w= w;
            }
            //
            //cout<<w<<" "<<b<<endl;
            A.w-= C.w;
            A.b-= C.b;
            full.b-= A.b;
            full.w+= A.b;
        }
        else
        {
            full.w-= B.w;
            full.b+= B.w;
            full.b-= A.b;
            full.w+= A.b;
        }




        cout<<full.w<<" "<<full.b<<"\n";




    }

    return 0;
}


/*
1
1000000000 1000000000
100000000 100000000 200000500 200000934
1 1000000000 1000000000 1000000000

*/



