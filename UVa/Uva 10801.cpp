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
//#define lld I64d//for CF submissions
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
ll n, k, t[6], mp[505], cost[505][505], dis[505];

struct node
{
    ll x, d;
    bool operator <(const node &nd) const
    {
        return d>nd.d;
    }
};

ll dijkstra(vector<ll> adj[505], ll src)
{
    priority_queue<node> pq;
    node s;
    s.x= src;
    s.d= 0;
    dis[src]= 0;
    pq.push(s);
    ll mn= inf;
    while(!pq.empty())
    {
        node u= pq.top();
        if(mp[u.x]== k)
        {
            //cout<<"in dijkstra: "<<u.d<<endl;
            //cout<<u.x<<" "<<mp[u.x]<<endl;
            if(u.d<mn) mn= u.d;
        }
        pq.pop();
        ll sz= adj[u.x].size();
        ll i;
        for(i= 0; i<sz; i++)
        {
            ll v= adj[u.x][i];
            if(dis[v]== -1 || ((dis[u.x]+cost[u.x][v])<dis[v]))
            {
                dis[v]= dis[u.x]+cost[u.x][v];
                node vv;
                vv.x= v;
                vv.d= dis[v];
                pq.push(vv);
            }
        }
    }

    return mn;
}



int main()
{
    //fin(in);
    //fout(out);

    while(scanf("%lld%lld", &n, &k)== 2)
    {
        memz(mp);
        memz(t);
        ll i;
        for(i= 1; i<=n;  i++)
            scanf("%lld ", &t[i]);
        memneg(mp);
        memneg(cost);
        memneg(dis);
        ll p= 1;
        vector<ll> mplist[103];
        vector<ll> adj[505];
        for(i= 1; i<=n; i++)
        {
            string s;
            getline(cin, s);
            //cout<<"s: "<<s<<endl;
            stringstream is(s);
            vector<ll> v;
            ll x;
            while(is>>x)
            {
                v.pb(x);
            }

            ll sz= v.size();
            ll j;
            ll y;
            //cout<<"p: "<<p<<endl;
            for(j= 0; j<sz-1; j++)
            {
                x= v[j];
                y= v[j+1];
                mp[p]= x;
                mp[p+1]= y;
                if(j== 0) mplist[x].pb(p);
                mplist[y].pb(p+1);

                adj[p].pb(p+1);
                adj[p+1].pb(p);
                cost[p][p+1]= t[i]*(y-x);
                cost[p+1][p]= t[i]*(y-x);

                p++;
            }
            //cout<<"input taken\n";
            p++;
        }//



        for(ll j= 0; j<=99; j++)
        {
            ll x, y, sz;
            sz= mplist[j].size();
            if(j== 0)
            {
                for(ll kk= 0; kk<sz; kk++)
                {
                    x= mplist[j][kk];

                    for(ll jj= kk+1; jj<sz; jj++)
                    {
                        y= mplist[j][jj];
                        adj[x].pb(y);
                        adj[y].pb(x);
                        cost[x][y]= 0;
                        cost[y][x]= 0;
                    }

                }

            }
            else
            {
                for(ll kk= 0; kk<sz; kk++)
                {
                    x= mplist[j][kk];

                    for(ll jj= kk+1; jj<sz; jj++)
                    {
                        y= mplist[j][jj];
                        adj[x].pb(y);
                        adj[y].pb(x);
                        cost[x][y]= 60;
                        cost[y][x]= 60;
                    }

                }
            }
        }


//        for(i= 1; i<=20; i++)
//        {
//            ll sz= adj[i].size();
//            for(ll j= 0; j<sz; j++)
//            {
//                ll d= adj[i][j];
//                cout<<i<<"-"<<d<<" cost: "<<cost[i][d]<<endl;
//            }
//            cout<<endl<<endl;
//        }

        if(mplist[0].size()== 0 || mplist[k].size()== 0) printf("IMPOSSIBLE\n");
        else
        {
            ll src= mplist[0][0];
            ll ans= dijkstra(adj, src);
            if(ans== inf) printf("IMPOSSIBLE\n");
            else printf("%lld\n", ans);
        }

    }

    return 0;
}






