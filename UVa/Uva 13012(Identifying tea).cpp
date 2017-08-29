#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, x;
    while(scanf("%d", &n)== 1)
    {
        map <int, int> m;
        for(i= 1; i<=5; i++)
        {
            scanf("%d", &x);
            m[x]++;
        }
        printf("%d\n", m[n]);
    }
    return 0;
}
