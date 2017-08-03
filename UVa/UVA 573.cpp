#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int day;
    double h, u, d, f, dc;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(scanf("%lf%lf%lf%lf", &h, &u, &d, &f)== 4 && h!=0)
    {
        dc= 0;
        dc+= u;
        dc-= d;
        f= (f/100)*u;
        day= 1;
        while(1)
        {
            u-= f;
            dc+= u;
            day++;
            if(dc>=h)
                break;
            dc-= d;
            if(dc<0)
                break;
        }
        if(dc>=h)
            printf("success on day %d\n", day);
        else
            printf("failure on day %d\n", day);
    }
    return 0;
}
