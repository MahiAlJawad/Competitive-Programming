#include<bits/stdc++.h>
#define ll long long
#define memz(x) memset(x, 0, sizeof(x));
using namespace std;

struct edge
{
    ll u, v, w;
    bool operator < (const edge &a) const
    {
        return w< a.w;
    }
};

vector <edge> e;
ll par[1005];

int findrep(int r)
{
    if(par[r]== r)
        return r;
    else
        par[r]= findrep(par[r]);
    return par[r];
}

ll MST(ll n)
{
    memz(par);
    ll i, u, v, cnt= 0, cost= 0;
    sort(e.begin(), e.end());
    for(i= 1; i<= n; i++)
        par[i]= i;// Making set of each node, as learnt in disjoint set DS

    for(i= 0; i< e.size(); i++)
    {
        u= findrep(e[i].u);// Finding representative of u
        v= findrep(e[i].v);// Finding representative of v
        if(u!= v)// if they are not friend yet
        {
            par[u]= v;// Making them friend i.e. making union
            cnt++; // counting the number of edges in MST
            cost+= e[i].w;
        }

        if(cnt== n-1)// i.e. all the nodes of MST are already found with the minimum cost
            break;
    }

    return cost;
}

int main()
{
    ll i, u, v, weight, n, edg;

    printf("Enter the number of vertex: ");
    scanf("%d", &n);
    printf("\nEnter the number of edge: ");
    scanf("%d", &edg);

    for(i= 1; i<= edg; i++)
    {
        scanf("%d%d%d", &u, &v, &weight);
        edge x;
        x.u= u;
        x.v= v;
        x.w= weight;
        e.push_back(x);
    }

    printf("\nThe minimum cost to visit all the nodes: %d\n", MST(n));

    return 0;
}
