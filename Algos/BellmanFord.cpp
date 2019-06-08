#include<bits/stdc++.h>
#define ll long long
#define memz(x) memset(x, 0, sizeof(x))
#define pb push_back
#define ginf INT_MAX//Graph infinity, so that (ginf+ginf) does not overflow in long long
using namespace std;


ll n, cost[51][51], dis[51];

struct node
{
    ll u, v;
};
vector<node> edge;

void BellmanFord(ll s)
{
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
            cout<<"Negative Cycle Found\n";
            break;
        }
    }
}
int main()
{
    ll i, e;
    cin>>n>>e;//Number of nodes and edges
    memz(cost);//assigning all of them to zero, no need btw.

    for(i= 1; i<=e; i++)
    {
        ll u, v, w;
        cin>>u>>v>>w;
        cost[u][v]= w;
        cost[v][u]= w;
        node nd;
        nd.u= u;
        nd.v= v;
        edge.pb(nd);
        nd.u= v;
        nd.v= u;
        edge.pb(nd);
    }

    BellmanFord(1);

    cout<<"Print distance array: ";
    for(i= 1; i<=n; i++) cout<<dis[i]<<" ";

    return 0;
}
/*
3 3
1 2 3
2 3 2
3 1 -10
//Negatvie Cycle Detected

4 5
1 2 6
2 3 1
1 3 4
1 4 1
4 3 2
*/
