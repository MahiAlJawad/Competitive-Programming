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
#define setLowerBound(st, elem) st.lower_bound(elem));/*returns the lower bound ITERATOR of 'elem' in the stl set 'st', where lower bound means
the LEFTMOST index where there is any integer which is GREATER OR EQUAL to 'elem'.*/
#define setUpperBound(st, elem) st.upper_bound(elem));/*returns the upper bound ITERATOR of 'elem' in the stl set 'st', where upper bound means
the LEFTMOST index where there is any integer which is GREATER than 'elem'.*/
#define clearPQ(pq, type) pq= priority_queue<type>()/*It clears a priority queue by redeclaration*/
#define minPQ(PQ_name, type) priority_queue<type, vector<type>, greater<type> > PQ_name;/*min priority queue with built in type i.e int or long long etc. */
#define sortArr(arr, sz) sort(arr+1, arr+(sz+1));/*Sorts an array from index 1 to index 'sz'*/
#define ginf INT_MAX
/*Macro ends here*/
//add vector descending sorting

using namespace std;

ll n, m;
ll cost[1005][1005], dis[1005], vis[1005];
vector<ll> adj[1005];
vector<ll> ans;
struct node
{
    ll u, v;
    node(ll x, ll y)
    {
        u= x;
        v= y;
    }
};
vector<node> edge;

void dfs(ll s)
{
    ans.pb(s);
    vis[s]= 1;
    ll i;
    for(i= 0; i<adj[s].size(); i++)
    {
        ll v= adj[s][i];
        if(!vis[v])
        {
            dfs(v);
        }
    }
}


bool BellmanFord(ll s)
{
    bool negativeCycle= 0;
    ll i, j;
    for(i= 0; i<=n; i++) dis[i]= ginf;//assigning all the nodes distance from source equals to infinity
    dis[s]= 0;
    for(i= 1; i<=n-1; i++)
    {
        for(j= 0; j<edge.size(); j++)
        {
            ll u= edge[j].u;
            ll v= edge[j].v;
            if((dis[u]+cost[u][v])<dis[v]) dis[v]= dis[u]+ cost[u][v];
        }
    }
    for(i= 0; i<edge.size(); i++)
    {
        ll u= edge[i].u;
        ll v= edge[i].v;
        if((dis[u]+cost[u][v])<dis[v])
        {
            negativeCycle= 1;
            if(!vis[u]) dfs(u);
        }
    }
    return negativeCycle;
}

int main()
{
    //fin(in);
    //fout(out);
    ll tc;
    cin>>tc;
    for(ll i= 1; i<=tc; i++)
    {

        cin>>n>>m;
        edge.clear();
        memz(cost);
        memz(vis);
        for(ll j= 0; j<=1000; j++) adj[j].clear();
        ans.clear();
        ll s;
        while(m--)
        {
            ll u, v, w;
            cin>>u>>v>>w;
            edge.pb(node(v, u));
            cost[v][u]= w;
            adj[v].pb(u);
            s= u;
        }
        cout<<"Case "<<i<<": ";
        if(BellmanFord(s))
        {
            sort(ans.begin(), ans.end());
            for(ll j= 0; j<ans.size();  j++)
            {
                if(j!= 0) cout<<" ";
                cout<<ans[j];
            }
            cout<<"\n";
        }
        else cout<<"impossible\n";
    }

    return 0;
}

/*
1
4 4
1 2 1
2 1 -3
1 3 1
3 4 2


*/

