#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, ans;
    while(scanf("%lld", &n)== 1 && n>= 0)
    {
        if(n== 0) printf("1\n");
        else
        {
            ans= 2+((n-1)*(2+n))/2;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
