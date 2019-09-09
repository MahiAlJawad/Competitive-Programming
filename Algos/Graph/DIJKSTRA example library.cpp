//Uva 10986
#include<bits/stdc++.h>
#define ll int
#define inf INT_MAX /*** this should not be LLONG_MAX because addition operation to
this may result in Overflow ***/
#define pb push_back
using namespace std;

/***
here 'll' defined as 'int', and this solution got an AC, but if we use long long then
for this problem maximum n= 20000, that's why when we define 'cost' 2D vector cost[20000][20000]
it cannot allocate memory for long long 2D array of size 20000, and gets a TLE.
But in case of int it can int cost[20000][20000] allocate for size 20000. that's why
gets an AC.

USE INTEGER IF THE SIZE OF NODES ARE MUCH LARGER TO ALLOCATE COST[][] VECTOR IN LONG LONG
***/

vector<vector<ll> > g;
vector<ll> dis;
vector<vector<ll> > cost;/***better to use 2D array if RUNTIME is a concern***/
struct node
{
    ll x, d;
    //x is the node, and d is the distance of node x from the source when this
    //is pushed into priority queue
    node(ll v, ll dst)
    {
        x= v;
        d= dst;
    }

    bool operator <(const node &nd) const
    {
        return d>nd.d;
    }
};


void dijkstra(ll src, ll dst)
{
    ll i;
    priority_queue<node> pq;

    dis[src]= 0;
    pq.push(node(src, 0));

    while(!pq.empty())
    {
        node u= pq.top();
        if(u.x== dst) break;
        pq.pop();
        for(i= 0; i<g[u.x].size(); i++)
        {
            ll v= g[u.x][i];
            if((dis[u.x]+cost[u.x][v])<dis[v])
            {
                dis[v]= dis[u.x]+cost[u.x][v];
                pq.push(node(v, dis[v]));
            }
        }
    }

}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll t, tc= 0;
    scanf("%d", &t);//number of test cases
    while(t--)
    {
        ll n, m, i, s, e;
        scanf("%d%d%d%d", &n, &m, &s, &e);//number of nodes, edges, starting node, ending node
        g= vector<vector<ll> > (n+5);
        dis= vector<ll> (n+5, inf);
        cost= vector<vector<ll> > (n+5, vector<ll> (n+5, inf));


        for(i= 1; i<=m; i++)//m edges input
        {
            ll u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            g[u].pb(v);
            g[v].pb(u);
            cost[u][v]= min(cost[u][v], w);
            cost[v][u]= cost[u][v];
        }

        dijkstra(s, e);
        if(dis[e]== inf) printf("Case #%d: unreachable\n", ++tc);
        else printf("Case #%d: %d\n", ++tc, dis[e]);
    }

    return 0;
}



