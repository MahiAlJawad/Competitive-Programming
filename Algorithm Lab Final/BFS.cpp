#include<bits/stdc++.h>
using namespace std;

int par[51];
vector <int> adj[51];
vector <int> level(51, -1);
queue <int> q;

void bfs(int s)
{
    int u, v, i;
    q.push(s);
    par[s]= 0;
    level[s]= 0;

    while(!q.empty())
    {
        u= q.front();
        q.pop();
        for(i= 0; i<adj[u].size(); i++)
        {
            v= adj[u][i];
            if(level[v]== -1)
            {
                q.push(v);
                par[v]= u;
                level[v]= level[u]+1;
            }
        }
    }
}

int main()
{
    int u, v, e, source, node, i;
    printf("Enter the number of edges : ");
    scanf("%d", &e);
    printf("\nNow enter the edges: \n");
    for(i= 1; i<=e; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printf("Enter the source node and node to search: ");
    scanf("%d%d", &source, &node);
    bfs(source);
    printf("\nThe shortest distance from %d to %d is: %d", source , node, level[node]);
    vector <int> path;
    path.push_back(node);
    while(par[node])
    {
        path.push_back(par[node]);
        node= par[node];
    }

    printf("\nAnd the shortest path: ");
    for(i= path.size()-1; i>= 0; i--)
        printf("->%d", path[i]);

    return 0;
}
