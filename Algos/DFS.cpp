#include<bits/stdc++.h>
using namespace std;
vector <int> adj[51];
vector <int> color(51, 1);//Let the color 1 be white, 2 be gray and 3 be black
int d[51], f[51];
int t;

void DFS(int s)
{
    int u= s, i, v;
    d[u]= ++t;
    color[u]= 2;
    for(i= 0; i<adj[u].size(); i++)
    {
        v= adj[u][i];
        if(color[v]== 1)
            DFS(v);
    }
    f[u]= ++t;
    color[u]= 3;
    return;
}


int main()
{
    int vertex, edge, i, a, b, source;
    printf("Enter the number of vertex: ");
    scanf("%d", &vertex);
    printf("\nEnter the number of edges: ");
    scanf("%d", &edge);
    printf("\n");
    for(i= 1; i<=edge; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    source= a;
    DFS(a);

    return 0;
}
