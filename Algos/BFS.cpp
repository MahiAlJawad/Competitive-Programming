#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int parent[51];
vector<int> adj[51];
vector<int> level(51, -1);

void BFS(int s)
{

    int i, u, v;
    q.push(s);
    level[s]= 0;
    while(!q.empty())
    {
        u= q.front();
        q.pop();
        for(i= 0; i< adj[u].size(); i++)
        {
            v= adj[u][i];
            if(level[v]== -1)
            {
                q.push(v);
                level[v]= level[u]+1;
                parent[v]= u;
            }
        }
    }

}

int main()
{
    int vertex, edge, i, a, b, source, node;
    vector<int> path;
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
    printf("Enter the source node and the node to search: ");
    scanf("%d%d", &source, &node);
    BFS(source);
    printf("The shortest distance between node %d to node %d is: %d\n", source, node, level[node]);
    printf("The path: ");
    path.push_back(node);
    while(parent[node])
    {
        path.push_back(parent[node]);
        node= parent[node];
    }
    for(i= path.size()-1; i>=0; i--)
    {
        printf("%d", path[i]);
        if(i!= 0)printf("->");
    }
    printf("\n");

    return 0;
}
