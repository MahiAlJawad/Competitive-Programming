#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[1005], i,j, cnt;
    while(scanf("%d", &n)== 1)
    {
        for(i= 1; i<= n; i++)
            scanf("%d", &a[i]);

        cnt= 0;

        for(i= 1; i<=n-1; i++)
        {
            for(j= 1; j<=n-1; j++)
            {
                if(a[j]> a[j+1])
                {
                    swap(a[j], a[j+1]);
                    cnt++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", cnt);
    }
    return 0;
}
