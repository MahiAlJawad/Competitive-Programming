#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, phi;
    while(scanf("%d", &n) && n!=0)
    {
        phi= n;
        for(i= 2; i*i<=n; i++)
        {
            if(n%i== 0)
            {
                while(n%i== 0)
                {
                    n/= i;
                }
                phi= (phi/i)*(i-1);
            }
        }
        if(n>1)
        {
            phi= (phi/n)*(n-1);
        }
        printf("%d\n", phi);
    }
    return 0;
}
