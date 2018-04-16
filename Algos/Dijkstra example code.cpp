#include<bits/stdc++.h>
#define sz 5005
using namespace std;

lng cost[sz][sz];
lng n;

struct node
{
    lng v;
    lng pdis= inf;
    lng dis= inf;
    bool operator<(const node &x) const
    {
        return dis>x.dis;
    }
};

void dijkstra(node vtx[sz], vector<lng> adj[sz])
{
    node u;
    lng i;
    priority_queue<node> pq;
    vtx[1].dis= 0;
    pq.push(vtx[1]);

    while(!pq.empty())
    {
        u= pq.top();
        pq.pop();
        //if(u.v== n) break;// যদি n পেয়ে যাওয়ার পর আর খোঁজার দরকার না হয় আরকি!, সেকেন্ড বেস্ট পাথ খুঁজলে এইটা রাখা যাবে না।
        lng lim= adj[u.v].size();
        for(i= 0; i<lim; i++)
        {
            lng adjofu= adj[u.v][i];
            if((u.dis+cost[u.v][adjofu])<vtx[adjofu].dis)
            {
                vtx[adjofu].dis= u.dis+cost[u.v][adjofu];
                pq.push(vtx[adjofu]);
            }
            else if((u.dis+cost[u.v][adjofu])<vtx[adjofu].pdis && (u.dis+cost[u.v][adjofu])>vtx[adjofu].dis)// এইটা  Second Shortest path খোঁজার জন্য কন্ডিশন।
            {
                vtx[adjofu].pdis= u.dis+cost[u.v][adjofu];
                pq.push(vtx[adjofu]);
            }
        }
    }
}


int main()
{
    lng t, tc= 0, r, i, a, b, w;
    scanf("%lld", &t);
    while(t--)//যতবার টেস্টকেস আছে ততবার গ্রাফ ইনপুট নিবে, অন্য একটা প্রব্লেম সলভ করতে যাই লিখা হইয়ে গেসে কোডটা :p
    {
        node vtx[sz];
        memset(cost, 0, sizeof(cost));
        vector<lng> adj[sz];

        scanf("%lld%lld", &n, &r);// নোড আর এজের সংখ্যা
        for(i= 1; i<=r; i++)// এজ ইনপুট নিচ্ছে ওয়েটের সাথে
        {
            scanf("%lld%lld%lld", &a, &b, &w);

            cost[a][b]= w;
            cost[b][a]= w;

            adj[a].pb(b);
            adj[b].pb(a);

            vtx[a].v= a;
            vtx[b].v= b;
        }

        dijkstra(vtx, adj);
        printf("Case %lld: %lld\n", ++tc, vtx[n].pdis);//এখানে সেকেন্ড শর্টেস্ট পাথের দূরত্ব প্রিন্ট করতেসে
    }



    return 0;
}


