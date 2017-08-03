#include<iostream>
#include<cstdio>
#include<cmath>
#define pi 2*acos(0)

using namespace std;
int main()
{
    double a, b, c, s, r, R, x, y, yellow, violet, red;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%lf%lf%lf", &a, &b, &c)== 3)
    {
        s= (a+b+c)/2;
        x= sqrt(s*(s-a)*(s-b)*(s-c));
        r= x/s;
        red= pi*r*r;
        violet= x-red;
        R= ((a*b*c)/sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c)));
        y= pi*R*R;
        yellow= y-x;
        printf("%.4lf %.4lf %.4lf\n", yellow, violet, red);
    }
    return 0;
}
