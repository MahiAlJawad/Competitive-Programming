#include<bits/stdc++.h>
using namespace std;

bool bicolorable(vector<int> adj[202], int s)
{
    int u, v, i, usize, pcolor;
    vector <int> color(202, 0);
    queue <int> q;
    color[s]= 1;
    q.push(s);
    while(!q.empty())
    {
        u= q.front();
        q.pop();
        pcolor= color[u];
        usize= adj[u].size();
        for(i= 0; i< usize; i++)
        {
            v= adj[u][i];
            if(color[v]== 0)
            {
                if(pcolor== 1)
                    color[v]= 2;
                else
                    color[v]= 1;
                q.push(v);
            }
            else
            {
                if(color[v]== pcolor)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int n, l, i, a, b, src;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(scanf("%d", &n) && n!=0)
    {
        vector <int> adj[202];
        scanf("%d", &l);
        for(i= 1; i<=l; i++)
        {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        src= a;
        if(bicolorable(adj, src))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
