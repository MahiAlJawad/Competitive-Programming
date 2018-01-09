#include<bits/stdc++.h>
using namespace std;

struct node
{
    int n= 0;
    int nod= 0;
};

bool operator <(const node &a, const node &b)
{
    if(a.nod== b.nod) return a.n>b.n;
    return a.nod<b.nod;
}

int main()
{
    int t, tc= 0, i, j;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    vector<node> v;
    vector<int> d[1001];
    for(i= 1; i<= 1000; i++)
    {
        for(j= i; j<=1000; j+= i)
        {
            d[j].push_back(i);
        }
    }
    for(i= 1; i<=1000; i++)
    {
       node nd;
       nd.n= i;
       nd.nod= d[i].size();
       v.push_back(nd);
    }
    sort(v.begin(), v.end());
    while(t--)
    {
        int x;
        scanf("%d", &x);
        vector<node> :: iterator it;
        it= v.begin()+(x-1);

        node pr;
        pr= *it;
        printf("Case %d: %d\n", ++tc, pr.n);
    }

    return 0;
}
