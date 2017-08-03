#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    double  a, b, z, m, p, x, y;
    int t;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf%lf%lf", &a, &b, &z);
        m= (a+b)/3;
        x= a-m;
        y= b-m;
        p= (z/(x+y))*x;
        printf("%.0lf\n", p);
    }
    return 0;
}
