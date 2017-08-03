#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int t, i, j,  n, a[10005], max;
    cin>> t;
    for(i= 1; i<=t; i++)
    {
        cin>> n;
        for(j= 1; j<=n; j++)
        {
            cin>> a[j];
        }
        max= a[1];
        for(j= 2; j<=n; j++)
        {
            if(max< a[j])
                max= a[j];
        }
        printf("Case %d: %d\n", i, max);


    }
    return 0;
}
