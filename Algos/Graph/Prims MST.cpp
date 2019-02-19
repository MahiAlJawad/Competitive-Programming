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

ll vis[100];

struct node
{
    ll u, v, w;
    bool operator <(const node &nd) const
    {
        return w>nd.w;
    }
};
void prims(vector<ll> adj[100], vector<ll> adjcst[100], vector<ll> mst[100], vector<ll> mstcst[100])
{
    memz(vis);
    priority_queue<node> pq;
    ll i;
    vis[1]= 1;//Node number 1 is included in mst
    for(i= 0; i<adj[1].size(); i++)
    {
        node nd;
        nd.u= 1;
        nd.v= adj[1][i];
        nd.w= adjcst[1][i];
        pq.push(nd);
    }

    while(!pq.empty())
    {
        node nd= pq.top();
        pq.pop();
        if(vis[nd.v]== 0)
        {
            ll u= nd.u;
            ll v= nd.v;
            mst[u].pb(v);
            mstcst[u].pb(nd.w);
            mst[v].pb(u);
            mstcst[v].pb(nd.w);
            vis[v]= 1;
            for(i= 0; i<adj[v].size(); i++)
            {
                node n;
                n.u= v;
                n.v= adj[v][i];
                n.w= adjcst[v][i];
                pq.push(n);
            }
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll e;
    cin>>e;//number of edges
    vector<ll> adj[100], adjcst[100], mst[100], mstcst[100];

    while(e--)
    {
        ll u, v, w;
        cin>>u>>v>>w;
        adj[u].pb(v);
        adjcst[u].pb(w);
        adj[v].pb(u);
        adjcst[v].pb(w);
    }

    prims(adj, adjcst, mst, mstcst);

    cout<<"\n\nMST :\n";
    ll i, j;
    for(i= 1; i<100; i++)
    {
        ll sz= mst[i].size();
        if(sz>0)
        {
            cout<<"\ni= "<<i<<" :  ";
            for(j= 0; j<sz; j++)
            {
                cout<<mst[i][j]<<" ";
            }
            cout<<"\ncost, i= "<<i<<" :  ";
            for(j= 0; j<sz; j++)
            {
                cout<<mstcst[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

/*
11
1 5 2
1 2 4
2 4 8
5 4 5
2 3 18
3 4 11
4 7 11
7 6 1
6 8 2
4 8 9
1 4 10
*/
