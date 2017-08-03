#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long n, r, ternary;
    while(scanf("%lld", &n)== 1)
    {
        if(n<0)
            break;
        ternary = 0;
        while(1)
        {
            ternary= ternary +(n%3);
            n/= 3;
        }

        printf("%lld\n", ternary);
    }
    return 0;
}
