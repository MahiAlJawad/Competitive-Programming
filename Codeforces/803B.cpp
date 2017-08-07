#include<bits/stdc++.h>
using namespace std;
int a[200005];
vector <int> z;
int main()
{
    int n, i, min, j, r;
    scanf("%d", &n);
    for(i= 1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i]== 0)
            z.push_back(i);
    }
    for(i= 1; i<=n; i++)
    {
        min= 2000005;
        for(j= 0; j<z.size(); j++)
        {
            r= abs(i-z[j]);
            if(r<min)
                min= r;
        }
        if(i!= n)
            printf("%d ", min);
        else
            printf("%d\n", min);
    }
    return 0;
}
