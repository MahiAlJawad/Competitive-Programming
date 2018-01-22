#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, tc= 0, i, n, p, q;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        vector<int> v;
        int x;
        scanf("%d%d%d", &n, &p, &q);
        for(i= 1; i<= n; i++)
        {
            scanf("%d", &x);
            v.push_back(x);
        }
        int sz= v.size();
        int s= 0, k= 0;
        for(i= 0; i< sz; i++)
        {
            if(s+v[i]<=q && k+1<=p)
            {
                s+= v[i];
                k++;
            }
            else break;
        }
        printf("Case %d: %d\n", ++tc, k);
    }
    return 0;
}
