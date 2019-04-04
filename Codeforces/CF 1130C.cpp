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
#define clearPQ(pq, type) pq= priority_queue<type>()/*It clears a priority queue by redeclaration*/
#define minPQ(PQ_name, type) priority_queue<type, vector<type>, greater<type> > PQ_name;/*min priority queue with built in type i.e int or long long etc. */
#define sortArr(arr, sz) sort(arr+1, arr+(sz+1));/*Sorts an array from index 1 to index 'sz'*/
/*Macro ends here*/
//add vector descending sorting

using namespace std;

ll grid[55][55], vis[55][55];

struct node
{
    ll x, y;
};
vector<node> v;
bool bfs(ll x1, ll y1, ll x2, ll y2)
{
    v.clear();
    vis[x1][y1]= 1;
    node src;
    src.x= x1;
    src.y= y1;
    queue<node> q;
    q.push(src);
    //cout<<"in bfs: "<<endl;
    while(!q.empty())
    {
        node tp= q.front();
        q.pop();
        ll x= tp.x;
        ll y= tp.y;
        v.pb(tp);
        //cout<<x<<" "<<y<<endl;
        if(x== x2 && y== y2) return 1;
        if(vis[x+1][y]== 0 && grid[x+1][y]!= -1 && grid[x+1][y]!= 1)
        {
            node nd;
            nd.x= x+1;
            nd.y= y;
            q.push(nd);
            vis[x+1][y]= 1;
        }
        if(vis[x-1][y]== 0 && grid[x-1][y]!= -1 && grid[x-1][y]!= 1)
        {
            node nd;
            nd.x= x-1;
            nd.y= y;
            q.push(nd);
            vis[x-1][y]= 1;
        }
        if(vis[x][y+1]== 0 && grid[x][y+1]!= -1 && grid[x][y+1]!= 1)
        {
            node nd;
            nd.x= x;
            nd.y= y+1;
            q.push(nd);
            vis[x][y+1]= 1;
        }
        if(vis[x][y-1]== 0 && grid[x][y-1]!= -1 && grid[x][y-1]!= 1)
        {
            node nd;
            nd.x= x;
            nd.y= y-1;
            q.push(nd);
            vis[x][y-1]= 1;
        }
    }
    return 0;
}

ll dist(node a, node b)
{
    return ((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y));
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n;
    cin>>n;

    ll x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;

    ll i, j;
    memneg(grid);
    memz(vis);
    for(i= 1; i<=n; i++)
    {
        string s;
        cin>>s;
        for(j= 0; j<s.size(); j++)
        {
            char c= s[j];
            grid[i][j+1]= c-48;
            //cout<<grid[i][j]<<" ";
        }
        //cout<<endl;
    }

    vector<node> a, b;
    bool f= bfs(x1, y1, x2, y2);
    a= v;
    //cout<<"f: "<<f<<endl;
    if(f)
    {
        cout<<"0\n";
        return 0;
    }
    f= bfs(x2, y2, x1, y1);
    b= v;
    ll mn= inf;
    for(i= 0; i<a.size(); i++)
    {
        for(j= 0; j<b.size(); j++)
        {
            node x= a[i];
            node y= b[j];
            ll d= dist(x, y);
            if(d<mn) mn= d;
            //cout<<"d: "<<d<<endl;
        }
    }
    cout<<mn<<endl;

    return 0;
}

/*
5
1 1
1 4
00001
11111
00111
00110
00110
*/




