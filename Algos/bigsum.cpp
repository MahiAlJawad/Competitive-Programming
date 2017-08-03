#include<bits/stdc++.h>
using namespace std;
int bigmod(int a, int b,int m)
{
    int x;
    if(b== 0) return 1;
    if(b%2== 0)
    {
        x= bigmod(a, b/2, m);
        return ((x%m)*(x%m))%m;
    }
    else
        return ((a%m)*bigmod(a, b-1, m)%m);
}
int bigsum(int a, int b, int m)
{
    int x, y;
    if(b== 2) return 1+a;
    if(b%2== 0)
    {
        x= bigsum(a, b/2, m);
        y= ((x%m)+(bigmod(a, b/2, m)*(x%m))%m)%m;
        return y;
    }
    else
    {
        x= bigmod(a, b-1, m);
        y= ((x%m)+bigsum(a, b-1, m)%m)%m;
        return y;
    }
}
int main()
{
    cout<<bigsum(2, 6, 7);
}
