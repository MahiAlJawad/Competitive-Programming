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


using namespace std;

ll sum= 0;
vector<vector<ll> > g;
vector<ll> dp, comp, compsum, comptype;

struct node
{
    ll u, v;

    node(ll a, ll b)
    {
        u= a;
        v= b;
    }
    bool operator < (const node &nd) const
    {
        if(u== nd.u) return v<nd.v;
        else return u<nd.u;
    }
};

map<node, ll> cost;

void solve(ll src, ll k, ll type)
{
    //cout<<"src: "<<src<<" k: "<<k<<" type: "<<type<<endl;
    sum= 0;
    dp[src]= 0;
    ll i;
    comptype[k]= type;
    queue<ll> q;
    q.push(src);
    comp[src]= k;
    if(g[src].size()== 2)
    {
        ll tmp= g[src][1];
        sum+= cost[node(src, tmp)];
    }
    ll tm;
    while(!q.empty())
    {
        ll u= q.front();
        //cout<<"u: "<<u<<" v: ";
        q.pop();
        ll lim;
        if(u== src) lim= 1;
        else lim= g[u].size();

        for(i= 0; i<lim; i++)
        {
            ll v= g[u][i];
            //cout<<v<<" ";
            if(dp[v]== -1)
            {
                dp[v]= dp[u]+cost[node(u, v)];
                q.push(v);
                comp[v]= k;
                tm= dp[v];
            }
        }
        //cout<<endl;
    }
    sum+= tm;
    compsum[k]= sum;
}


int main()
{
    fasterInOut;
    ll t, tc= 0;
    cin>>t;
    while(t--)
    {
        ll n, e, i;
        cin>>n>>e;
        g= vector<vector<ll> > (n+5);
        comp= vector<ll> (n+5, 0);
        compsum= vector<ll> (n+5, 0);
        comptype= vector<ll> (n+5, 0);
        cost.clear();
        dp= vector<ll> (n+5, -1);

        if(e== 0)
        {
            ll q;
            cin>>q;
            cout<<"Case "<<++tc<<":\n";
            while(q--)
            {
                ll u, v;
                cin>>u>>v;
                cout<<"-1\n";
            }
            continue;
        }
        for(i= 1; i<=e; i++)
        {
            ll u, v, w;
            cin>>u>>v>>w;
            g[u].pb(v);
            g[v].pb(u);
            cost[node(u, v)]= w;
            cost[node(v, u)]= w;
            sum+= w;
        }

//        cout<<"show adj: \n";
//        for(i= 1; i<=n; i++)
//        {
//            cout<<i<<" : ";
//            for(ll j= 0; j<g[i].size(); j++)
//            {
//                cout<<g[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        ll k= 1;
        for(i= 1; i<=n; i++)
        {
            if(dp[i]== -1 && g[i].size()== 1)
            {
                solve(i, k++, 1);
            }
        }
        for(i= 1; i<=n; i++)
        {
            if(dp[i]== -1 && g[i].size()>1)
            {
                solve(i, k++, 2);
            }
        }

        ll q;
        cin>>q;
        cout<<"Case "<<++tc<<":\n";
        while(q--)
        {
            ll u, v;
            cin>>u>>v;
            if(comp[u]!= comp[v])
            {
                cout<<"-1\n";
                continue;
            }
            if(u== v)
            {
                cout<<"0\n";
                continue;
            }
            if(comptype[comp[u]]== 1)
            {
                ll x= dp[u];
                ll y= dp[v];

                if(x== -1 || y== -1)
                {
                    cout<<"-1\n";
                    continue;
                }
                if(x<y) swap(x, y);
                cout<<(x-y)<<"\n";
            }
            else
            {
                ll x= dp[u];
                ll y= dp[v];
                if(x== -1 || y== -1)
                {
                    cout<<"-1\n";
                    continue;
                }
                if(x<y) swap(x, y);
                cout<< min((x-y),(compsum[comp[u]]-(x-y)))<<"\n";
            }
        }

    }



    return 0;
}

/*
4

4 3
1 3 4
2 3 3
1 4 1
4
2 1
2 3
1 3
2 4

12 10
1 2 10
2 3 15
3 4 5
4 5 2
1 5 3
7 8 2
8 9 3
10 11 5
11 12 6
10 12 2
18
2 3
3 4
1 4
4 5
1 5
1 3
1 2
6 1
5 5
7 9
7 8
7 10
7 3
10 12
10 11
12 1
7 7
6 6

2 0
3
1 1
2 1
1 2

2 1
1 2 5
2
1 2
2 1


*/
