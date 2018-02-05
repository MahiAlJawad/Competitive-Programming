#include<bits/stdc++.h>
using namespace std;

bool f[1005];

int main()
{
    int n, i;
    memset(f, 0, sizeof(f));
    f[1]= 1;
    f[2]= 1;
    int a= 1, b= 2, x= a+b;
    while(x<= 1003)
    {
        f[x]= 1;
        a= b;
        b= x;
        x= a+b;
    }
    scanf("%d", &n);
    for(i= 1; i<=n; i++)
    {
        if(f[i]== 1) printf("O");
        else printf("o");
    }
    printf("\n");

    return 0;
}
