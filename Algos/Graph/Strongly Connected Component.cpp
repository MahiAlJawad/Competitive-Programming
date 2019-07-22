#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define memz(x) memset(x, 0, sizeof(x))
using namespace std;

vector<vector<ll> > g, rg;
vector<vector<ll> > components;
ll vis1[105], vis2[105], mark;
stack<ll> st;
void clearall()
{
    memz(vis1);//alternatively use vectors if the constrains varies
    memz(vis2);
    components= vector<vector<ll> > (105);
    mark= 0;
}
void dfs(ll u)
{
    ll i;
    vis1[u]= 1;
    for(i= 0; i<g[u].size(); i++)
    {
        ll v= g[u][i];
        if(!vis1[v]) dfs(v);
    }
    st.push(u);
}

void dfs2(ll u)
{
    ll i;
    components[mark].pb(u);
    vis2[u]= 1;
    for(i= 0; i<rg[u].size(); i++)
    {
        ll v= rg[u][i];
        if(!vis2[v]) dfs2(v);
    }
}
void findSCC()
{
    clearall();
    ll i, j;
    for(i= 1; i<=7; i++)//for all nodes, for test purpose assuming 7 nodes
    {
        if(!vis1[i]) dfs(i);
    }
    rg= vector<vector<ll> > (105);//reverse graph
    //now reversing
    for(i= 1; i<=7; i++)//for all nodes, for test purpose assuming 7 nodes
    {
        ll u, v;
        for(j= 0; j<g[i].size(); j++)
        {
            u= g[i][j];
            v= i;
            rg[u].pb(v);
        }
    }
    while(!st.empty())
    {
        ll u= st.top();
        st.pop();
        if(!vis2[u])
        {
            mark++;
            dfs2(u);
        }
    }
}
int main()
{
    ll e, i, u, v, j;
    cin>>e;
    g= vector<vector<ll> > (105);


    for(i= 1; i<=e; i++)
    {
        cin>>u>>v;
        g[u].pb(v);//assuming UNIDIRECTONAL edges
    }
    findSCC();
    for(i= 1; i<=mark; i++)
    {
        cout<<"Component "<<i<<" : ";
        for(j= 0; j<components[i].size(); j++) cout<<components[i][j]<<" ";
        cout<<"\n";
    }
}

/*
Test Case:
8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5


*/
