#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int t, n, a, x;
    cin>> t;
    while(t--)
    {
        cin>> n;
        a= (((((n*567)/9)+7492)*235)/47)-498;
        x= (a/10)%10;
        x= abs(x);
        printf("%d\n", x);
    }
    return 0;
}
