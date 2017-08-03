#include<stdio.h>

int f(int n)
{
    if(n== 1) return 1;
    else return ((n*n)+f(n-1));
}

int main()
{
    int n, m;

    while(scanf("%d", &n)== 1)
    {
        if(n== 0) break;
        m= f(n);
        printf("%d\n", m);
    }
    return 0;
}
