#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, r, i,j, mid, distance;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &r);
        vector<int> v;
        for(i= 1; i<= r; i++)
        {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int vsize= v.size();
        mid= v[vsize/2];

        distance = 0;
        for(j= 0; j<vsize; j++)
            distance+= abs(mid- v[j]);
        printf("%d\n", distance);

    }

    return 0;
}
