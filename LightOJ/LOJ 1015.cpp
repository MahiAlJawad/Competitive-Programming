#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs= 0, n, a, sum, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        sum= 0;
        for(i= 1; i<=n; i++)
        {
            scanf("%d", &a);
            if(a>0)
                sum+= a;
        }
        printf("Case %d: %d\n", ++cs, sum);
    }
    return 0;

}
