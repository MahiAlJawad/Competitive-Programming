#include<bits/stdc++.h>
#define ll long long
#define memz(x) memset(x, 0, sizeof(x));
#define pb push_back
using namespace std;
bool inGraph[101];//the inGraph[u]= 1 indicates that u is connected with some edge in this graph.
ll color[101];//white= 0, gray= 1, black= 2;
vector<ll> adj[101];
vector<ll> topsort;


void DFS(ll s)
{
    ll u= s, i, v;
    color[u]= 1;
    for(i= 0; i<adj[u].size(); i++)
    {
        v= adj[u][i];
        if(color[v]== 0) DFS(v);
    }
    topsort.pb(u);
    color[u]= 2;
    return;
}

void topologicalSort()
{
    memz(color);
    ll i;
    for(i= 1; i<=100; i++)//here 100 considered as the maximum possible node
    {
        if(inGraph[i] && color[i]== 0)
        {
            DFS(i);
        }
        //else if(color[i]== 0 && !inGraph[i])
        //{
        //     topsort.pb(i);
        // this condition is used when for any node i, inGraph[i]= 0 but the node i exist in the graph alone by itself
        //}
    }
}

int main()
{
    ll v, e, i;
    cin>>v>>e;
    memz(inGraph);
    while(e--)
    {
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        inGraph[u]= 1;
        inGraph[v]= 1;
    }
    topologicalSort();
    reverse(topsort.begin(), topsort.end());
    for(i= 0; i<topsort.size(); i++)
    {
        if(i!= 0) cout<<"->";
        cout<<topsort[i];
    }
    cout<<"\n";
}
/*
4 4
1 4
2 1
2 3
3 4

3 3
1 2
1 3
2 3

*/
