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
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define fin(in) freopen("in.txt", "r", stdin)
#define fout(out) freopen("out.txt", "w", stdout)
#define pb push_back
#define ll long long
#define lld I64d//for CF submissions
#define rh cout<<"Reached Here\n"
#define inf LLONG_MAX
#define neginf LLONG_MIN
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
otherwise returns POSITIVE in case of LEFT and ZERO when the point is on the line*/
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
#define setLowerBound(st, elem) st.lower_bound(elem);/*returns the lower bound ITERATOR of 'elem' in the stl set 'st', where lower bound means
the LEFTMOST index where there is any integer which is GREATER OR EQUAL to 'elem'.*/
#define setUpperBound(st, elem) st.upper_bound(elem);/*returns the upper bound ITERATOR of 'elem' in the stl set 'st', where upper bound means
the LEFTMOST index where there is any integer which is GREATER than 'elem'.*/
#define clearPQ(pq, type) pq= priority_queue<type>()/*It clears a priority queue by redeclaration*/
#define minPQ(PQ_name, type) priority_queue<type, vector<type>, greater<type> > PQ_name;/*min priority queue with built in type i.e int or long long etc. */
#define sortArr(arr, sz) sort(arr+1, arr+(sz+1));/*Sorts an array from index 1 to index 'sz'*/
/*Macro ends here*/

/*Frequently used Function starts here*/
//Bit set
/*ll Set(ll mask, ll pos){return mask = (mask OR ((ll)1<<pos));}*//*Sets pos'th bit HIGH of the mask and returns*//**Replace OR by Bitwise OR sign when using**/
bool check(ll mask, ll pos){ return (bool)(mask & ((ll)1 << pos)); }/*Checks if the pos'th bit is HIGH or not of the mask*/
/*Frequently used Function ends here*/

using namespace std;


struct data
{
    ll a, b, c;
    data(ll x, ll y, ll z)
    {
        a = x, b = y, c = z;
    }
};

struct node
{
    ll a, b;
    node(ll x, ll y)
    {
        if(x>y) swap(x, y);
        a = x, b = y;
    }

    bool operator < (const node& nd) const
    {
        if (nd.a == a) return nd.b < b;
        return nd.a < a;
    }
};

vector<vector<ll> > g;
vector<ll> vis;
ll src;
void dfs(ll u)
{
    vis[u] = 1;
    ll i;
    if (g[u].size() == 1)
    {
        src = u;
        return;
    }
    for (i = 0; i < g[u].size(); i++)
    {
        ll v = g[u][i];
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

vector<ll> graph;

void getGraph(ll u)
{
    graph.pb(u);
    vis[u] = 1;

    ll i;

    for (i = 0; i < g[u].size(); i++)
    {
        ll v = g[u][i];
        if (!vis[v])
        {
            getGraph(v);
        }
    }
}
int main()
{
    //fasterInOut;
    ll n;
    cin >> n;
    ll i, j;
    vector<data> v;
    for (i = 1; i <= (n - 2); i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back(data(a, b, c));
    }

    map<node, vector<ll> > mp;

    for (i = 0; i < v.size(); i++)
    {
        ll a = v[i].a;
        ll b = v[i].b;
        ll c = v[i].c;
        mp[node(a, b)].pb(i);
        mp[node(b, c)].pb(i);
        mp[node(c, a)].pb(i);
    }

    g = vector<vector<ll> >(n + 5);
    vis = vector<ll>(n + 5, 0);
    ll p;
    forit(it, mp)
    {
        vector<ll> tmp = it->second;
//        node nd= it->first;
//        cout<<nd.a<<","<<nd.b<<" : ";
//        for(i= 0; i<tmp.size(); i++) cout<<tmp[i]<<" ";
//        cout<<"\n";
        if (tmp.size() == 2)
        {

            ll u = tmp[0];
            ll v = tmp[1];
            p = u;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
//    cout<<"print graph: \n";
//    for(i= 0; i<3; i++)
//    {
//        cout<<"u "<<i<<" : ";
//        for(j= 0; j<g[i].size(); j++)
//        {
//            cout<<g[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    src = -1;
    dfs(p);
    graph.clear();
    vis= vector<ll> (n+5, 0);

//    cout<<"print vis: \n";
//    for(i= 0; i<vis.size(); i++) cout<<vis[i]<<" ";
//    cout<<endl;
    getGraph(src);
//    cout<<"print graph: \n";
//    for(i= 0; i<graph.size(); i++)
//    {
//        cout<<graph[i]<<" ";
//
//    }
//    cout<<endl;
    vector<ll> ans(n+1);
    map<ll, ll> mpp;
    for(i= 0; i<3; i++)
    {
        ll a= v[graph[i]].a;
        ll b= v[graph[i]].b;
        ll c= v[graph[i]].c;
        mpp[a]++;
        mpp[b]++;
        mpp[c]++;
        if(mpp[a]== 3)
        {
            ans[3]= a;
        }
        else if(mpp[b]== 3)
        {
            ans[3]= b;
        }
        else if(mpp[c]== 3)
        {
            ans[3]= c;
        }
    }
    ll a= v[graph[0]].a;
    ll b= v[graph[0]].b;
    ll c= v[graph[0]].c;

    if(mpp[a]== 1)
    {
        ans[1]= a;
        if(mpp[b]== 2) ans[2]= b;
        else if(mpp[c]== 2) ans[2]= c;
    }
    else if(mpp[b]== 1)
    {
        ans[1]= b;
        if(mpp[a]== 2) ans[2]= a;
        else if(mpp[c]== 2) ans[2]= c;
    }
    else if(mpp[c]== 1)
    {
        ans[1]= c;
        if(mpp[b]== 2) ans[2]= b;
        else if(mpp[a]== 2) ans[2]= a;
    }
    ll lim= graph.size();
    ll last= ans[3];
    ll secondlast= ans[2];
    p= 3;
    for(i= 1; i<lim; i++)
    {

        a= v[graph[i]].a;
        b= v[graph[i]].b;
        c= v[graph[i]].c;
        //cout<<"i: "<<i<<" a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
        if(a!= last && a!= secondlast)
        {
            ans[++p]= a;
            secondlast= last;
            last= a;
        }
        else if(b!= last && b!= secondlast)
        {
            ans[++p]= b;
            secondlast= last;
            last= b;
        }
        else if(c!= last && c!= secondlast)
        {
            ans[++p]= c;
            secondlast= last;
            last= c;
        }
    }

    for(i= 1; i<=n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
