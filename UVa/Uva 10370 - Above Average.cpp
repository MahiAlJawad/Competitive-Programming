#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, i, n;
    double a[1005], avg;
    int count;

    scanf("%d", &t);
    while(t--)
    {
        double sum= 0;
        count= 0;
        scanf("%d", &n);

        for(i= 1; i<=n; i++)
        {
            scanf("%lf", &a[i]);
            sum+= a[i];
        }
        avg= sum/n;
        for(i= 1; i<=n; i++)
        {
            if(a[i]>avg) count++;
        }
        printf("%.3lf%%\n", ((double)count*100)/(double)n);

    }
    return 0;
}
