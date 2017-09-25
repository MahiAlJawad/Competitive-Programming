#include<bits/stdc++.h>
using namespace std;
vector <int> color(51, 1);
vector <int> adj[51];
int d[51], f[51];
int t= 0;
void dfs(int s)
{
    int u, v, i;
    u= s;
    printf("%d ", u);
    d[u]= ++t;
    color[s]= 2;

    for(i= 0; i< adj[u].size(); i++)
    {
        v= adj[u][i];
        if(color[v]== 1)
        {
            dfs(v);
        }
    }
    f[u]= ++t;
    color[u]= 3;

    return;
}

int main()
{
    int e, u, v, source, i;
    printf("\nEnter the number of edges: ");
    scanf("%d", &e);
    printf("Enter edges: ");
    for(i= 1; i<=e; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printf("Enter source: ");
    scanf("%d", &source);
    printf("The DFS traversal: ");
    dfs(source);
}
