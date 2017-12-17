#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, tc= 0, n, q, i;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d%d", &n, &q);
        vector<long long> v;
        for(i= 1; i<=n; i++)
        {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }
        printf("Case %d:\n", ++tc);
        for(i= 1; i<=q; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            vector <long long>:: iterator low, up;
            low= lower_bound(v.begin(), v.end(), x);
            up= upper_bound(v.begin(), v.end(), y);

            printf("%d\n", up-low);
        }
    }

    return 0;
}
