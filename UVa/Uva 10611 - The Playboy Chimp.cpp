#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, q, i, x;
    vector<int> v;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    for(i= 0; i<n; i++)
    {
        scanf("%d", &x);
        v.push_back(x);
    }
    scanf("%d", &q);
    for(i= 1; i<=q; i++)
    {
        scanf("%d", &x);
        int up, low;
        up= upper_bound(v.begin(), v.end(), x) - v.begin();
        low= lower_bound(v.begin(), v.end(), x) - v.begin();
        if(low== 0) printf("X ");
        else printf("%d ", v[low-1]);
        if(up== n) printf("X\n");
        else printf("%d\n", v[up]);
    }

    return 0;
}
