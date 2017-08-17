#include<bits/stdc++.h>
using namespace std;
struct node
{
    double x, y;
};

struct edge
{
    int u, v;
    double w;

    bool operator < (const edge &b) const
    {
        return w<b.w;
    }
};

vector<int> par(102, 0);
vector<edge> e;

int findrep(int r)
{
    if(par[r]== r)
        return r;
    else
        par[r]= findrep(par[r]);
    return par[r];
}

double mst(int n)
{
    int u, v, i, count= 0;
    double cost= 0;
    sort(e.begin(), e.end());
    for(i= 1; i<=n; i++)
        par[i]= i;

    for(i= 0; i< e.size(); i++)
    {
        u= findrep(e[i].u);
        v= findrep(e[i].v);
        if(u!= v)
        {
            par[u]= v;
            count++;
            cost+= sqrt(e[i].w);
        }
        if(count== n-1)
            break;
    }

    return cost;
}
int main()
{
    int t, n, i, j, k;
    double x, y;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d", &t);
    for(i= 1; i<= t; i++)
    {
        node nd[102];
        scanf("%d", &n);
        for(j= 1; j<=n; j++)
        {
            scanf("%lf%lf", &x, &y);
            nd[j].x= x;
            nd[j].y= y;
        }

        for(j= 1; j<=n; j++)
        {
            for(k= j+1; k<=n; k++)
            {
                edge x;
                x.u= j;
                x.v= k;
                x.w= ((nd[j].x-nd[k].x)*(nd[j].x-nd[k].x)) +  ((nd[j].y-nd[k].y)*(nd[j].y-nd[k].y));
                e.push_back(x);
            }
        }

        printf("%.2lf\n", mst(n));
        if(i!= t)
            printf("\n");
        e.clear();
        par.clear();
    }
    return 0;
}
