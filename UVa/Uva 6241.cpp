#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long long n, s;
    while(scanf("%lld", &n))
    {
        if(n== 0)
            break;
        s= sqrt(n);
        if(s*s== n)
            printf("yes\n");
        else
            printf("no\n");

    }
    return 0;
}
