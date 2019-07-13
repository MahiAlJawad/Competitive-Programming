#include<bits/stdc++.h>
#define memz(x) memset(x, 0, sizeof(x))
#define pb push_back
using namespace std;
bool visited[105];
int parent[105], low[105], d[105], t= 0;
vector<vector<int>> g;


struct edge
{
    int u, v;
    edge(int a, int b)
    {
        u= a;
        v= b;
    }
    bool operator <(const edge e) const
    {
        if(u== e.u) return v<e.v;
        else return u<e.u;
    }
};

map<edge, bool> isArticulationB;/***Use 2D array if the number of node is not huge***/

void findArticulationBridges(int u)
{
    t++;
    low[u]= t;
    d[u]= t;
    visited[u]= 1;
    int i, v;

    for(i= 0; i<g[u].size(); i++)
    {
        v= g[u][i];
        if(v== parent[u]) continue;
        if(visited[v]) low[u]= min(low[u], d[v]);//back-edge
        else
        {
            parent[v]= u;
            findArticulationBridges(v);
            low[u]= min(low[u], low[v]);
            if(d[u]<low[v])
            {
                isArticulationB[edge(u, v)]= 1;
            }
        }
    }
}

void clearall()
{
    t= 0;
    memz(visited);
    memz(parent);
    memz(low);
    memz(d);
    isArticulationB.clear();
}


int main()
{
    int e, i;
    clearall();
    cin>>e;
    g= vector<vector<int>> (105);//maximum 100 nodes assumed;
    vector<edge> edg;

    for(i= 1; i<=e; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        edg.pb(edge(u, v));
    }
    int root= 1;
    findArticulationBridges(root);
    for(i= 0; i<e; i++)
    {
        cout<<"edge u: "<<edg[i].u<<" v: "<<edg[i].v<<" : "<<isArticulationB[edge(edg[i].u, edg[i].v)]<<endl;
    }

    return 0;
}
/*
Test Case:
7
1 2
1 3
3 4
4 5
4 6
3 7
6 7

5
1 2
2 3
2 4
3 5
5 2
*/

