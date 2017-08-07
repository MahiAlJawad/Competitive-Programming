#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n, i, min, max, count= 0;
    scanf("%d", &n);
    scanf("%d", &a[1]);
    max= a[1];
    min= a[1];
    for(i= 2; i<=n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i]>max)
            max= a[i];
        if(a[i]<min)
            min= a[i];
    }
    for(i= 1; i<=n; i++)
    {
        if(a[i]>min && a[i]<max)
            count++;
    }
    printf("%d\n", count);
    return 0;
}
