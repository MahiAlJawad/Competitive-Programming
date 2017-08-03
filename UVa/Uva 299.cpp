#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int t, n, a[55], i, j, s;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        s= 0;
        for(i= 1; i<=n; i++)
            scanf("%d", &a[i]);

        for(i= 1; i<= n-1; i++)
        {
            for(j= 1; j<= n-i; j++)
            {
                if(a[j]>a[j+1])
                {
                    swap(a[j], a[j+1]);
                    s++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", s);
    }
    return 0;
}
