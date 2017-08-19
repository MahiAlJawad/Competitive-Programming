#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, x, vsize;
    vector <int> v;
    while(scanf("%d", &n)  && n!= 0)
    {
        for(i= 1; i<=n; i++)
        {
            scanf("%d", &x);
            if(x)
                v.push_back(x);
        }
        vsize= v.size();
        if(vsize== 0)
            printf("0\n");
        else
        {
            for(i= 0; i<vsize; i++)
            {
                printf("%d", v[i]);
                if(i!= vsize-1)
                    printf(" ");
            }
            printf("\n");
        }
        v.clear();
    }
    return 0;
}
