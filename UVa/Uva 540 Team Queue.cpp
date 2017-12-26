#include<bits/stdc++.h>
using namespace std;
map<int, int> tnum;
map<int, int> tpr;
map <int, int> tmem;
struct team
{
    int x;
    int p;
    int q;
};
bool operator <(const team &a, const team &b)
{
    if(a.p== b.p) return a.q>b.q;
    return a.p>b.p;
}


int main()
{
    int t, n, i, j, elem, tc= 0;
    string s;

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    while(scanf("%d", &t) && t!= 0)
    {
        printf("Scenario #%d\n", ++tc);
        priority_queue <team> pq;
        tnum.clear();
        tpr.clear();
        tmem.clear();
        vector<int> v[1005];

        for(i= 1; i<= t; i++)
        {
            scanf("%d", &n);
            for(j= 0; j<n; j++)
            {
                int w;
                scanf("%d", &w);
                v[i].push_back(w);
                tnum[w]= i;
                tpr[i]= 0;
            }

        }
        int op= 0, en= 0;
        while(cin>>s && s!= "STOP")
        {
            if(s== "ENQUEUE")
            {
                scanf("%d", &elem);
                team a;
                a.x= elem;
                if(tnum[elem]== 0)
                {
                    tpr[tnum[elem]]= 1001;
                }
                else
                {
                    if(tpr[tnum[elem]]== 0)
                        tpr[tnum[elem]]= ++op;
                    tmem[tnum[elem]]++;
                }
                a.p= tpr[tnum[elem]];
                a.q= ++en;
                pq.push(a);
            }
            else
            {
                team b;
                b= pq.top();
                pq.pop();
                int el= b.x;
                tmem[tnum[el]]--;
                if(tmem[tnum[el]]<= 0) tpr[tnum[el]]= 0;
                printf("%d\n", el);
            }
        }
        printf("\n");
    }

    return 0;
}
