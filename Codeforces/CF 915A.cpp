#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, x, i, ans= 0;
    vector<int> v;
    scanf("%d%d", &n, &k);
    for(i= 1; i<=n; i++)
    {
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int vsize= v.size();
    for(i= vsize-1; i>=0; i--)
    {
        if(k%v[i]== 0)
        {
            ans= k/v[i];
            break;
        }
    }
    printf("%d\n", ans);

    return 0;
}
