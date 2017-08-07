#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n<=10)
            printf("0 %d\n", n);
        else
            printf("10 %d\n", n-10);
    }
    return 0;
}
