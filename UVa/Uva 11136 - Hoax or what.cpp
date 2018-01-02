#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, i, k, x;
    while(scanf("%d", &n))
    {
        multiset<int> v;
        if(n== 0) break;
        long long p= 0;
        while(n--)
        {
            scanf("%d", &k);
            for(i= 1; i<=k; i++)
            {
                scanf("%d", &x);
                v.insert(x);
            }
            multiset<int>:: iterator it1, it2;
            it1= v.begin();
            int mn= *it1;
            v.erase(it1);
            it2= --v.end();
            int mx= *it2;
            v.erase(it2);
            p+= (mx-mn);
        }
        printf("%lld\n", p);
    }
    return 0;
}
