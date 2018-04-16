/******************************************************************************************************************************
*** "In the name of Allah(swt), the most gracious, most merciful. Allah(swt) blesses with knowledge to whom he wants."      ***
***     Author     : Mahi Al Jawad                                                                                          ***
***     University : Dept. of CSE, IIUC                                                                                     ***
***     github     : https://github.com/MahiAlJawad                                                                         ***
***     Email      : br.mahialjawad@gmail.com                                                                               ***
***     facebook   : https://www.facebook.com/jawad.wretched                                                                ***
*******************************************************************************************************************************/

#include<bits/stdc++.h>
#define fin(in) freopen("in.txt", "r", stdin)
#define fout(out) freopen("out.txt", "w", stdout)
#define pb push_back
#define lng long long
#define lld I64d//for CF submissions
#define pi acos(-1.0)
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c));//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
#define forit(it,s) for(__typeof((s).end()) it=(s).begin(); it!= (s).end(); it++)
#define gcd(a,b) __gcd(a,b)
#define string_reverse(s) reverse(s.begin(), s.end())//Vector also can be reversed with this function
#define mkp make_pair
#define rh cout<<"reached here"<<endl
using namespace std;

struct cost
{
    map<lng, lng> mp;
};

cost cst[100005];

struct node
{
    lng u, dis= LONG_LONG_MAX;
    bool operator <(const node &x) const
    {
        return dis>x.dis;
    }
};


lng n;
priority_queue<node> pq;
vector<lng> adj[100005];
node addj[100005];
lng par[100005];

void dijkstra()
{
    lng i;
    addj[1].dis= 0;
    par[addj[1].u]= 0;
    pq.push(addj[1]);
    node u;


    while(!pq.empty())
    {
        u= pq.top();
        pq.pop();

        if(u.u== n) break;

        for(i= 0; i<adj[u.u].size(); i++)
        {
            lng v= adj[u.u][i];

            if((u.dis+cst[u.u].mp[v])<addj[v].dis)
            {
                addj[v].dis= u.dis+cst[u.u].mp[v];
                pq.push(addj[v]);
                par[v]= u.u;
            }
        }

    }
}

int main()
{
    lng m, i, a, b, w;

    scanf("%lld%lld", &n, &m);

    for(i= 1; i<=m ; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &w);
        adj[a].pb(b);
        adj[b].pb(a);

        cst[a].mp[b]= w;
        cst[b].mp[a]= w;

        addj[a].u= a;
        addj[b].u= b;
    }


    dijkstra();

    vector<lng> path;
    lng secureN= n;
    while(n)
    {
        path.pb(n);
        n= par[n];
    }
    lng psize= path.size();

    if(addj[secureN].dis!= LONG_LONG_MAX)
    {
        for(i= psize-1; i>= 0; i--)
        {
            if(i!= psize-1)
            {
                printf(" ");
            }
            cout<<path[i];
        }
        printf("\n");
    }
    else printf("-1\n");

    return 0;
}


