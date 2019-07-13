#include<bits/stdc++.h>
#define memz(x) memset(x, 0, sizeof(x))
#define pb push_back
using namespace std;
bool isArticulationP[105], visited[105];
int parent[105], low[105], d[105], t= 0, root;
vector<vector<int>> g;

void findArticulationPoints(int u)
{
    t++;
    low[u]= t;
    d[u]= t;
    visited[u]= 1;
    int numOfChild= 0, i, v;

    for(i= 0; i<g[u].size(); i++)
    {
        v= g[u][i];
        if(v== parent[u]) continue;
        if(visited[v]) low[u]= min(low[u], d[v]);//back-edge
        else
        {
            parent[v]= u;
            findArticulationPoints(v);
            low[u]= min(low[u], low[v]);
            if(d[u]<=low[v] && u!=root)
            {
                isArticulationP[u]= 1;
            }
            numOfChild++;
        }
        if(u== root && numOfChild>=2) isArticulationP[u]= 1;
    }
}

void clearall()
{
    memz(isArticulationP);
    memz(visited);
    memz(parent);
    memz(low);
    memz(d);
    t= 0;
}
int main()
{
    int e;
    cin>>e;
    g= vector<vector<int>> (105);//maximum 100 nodes assumed;

    while(e--)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    root= 1;
    findArticulationPoints(root);
    for(int i= 1; i<=10; i++)
    {
        cout<<"node "<<i<<" :"<<isArticulationP[i]<<endl;
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
