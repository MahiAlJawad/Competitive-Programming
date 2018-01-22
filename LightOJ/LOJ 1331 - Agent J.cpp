#include<bits/stdc++.h>
#define fin(in) freopen("in.txt", "r", stdin)
#define fout(out) freopen("out.txt", "w", stdout)
#define long long ll
#define pi acos(-1.0)
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c));//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
using namespace std;
int main()
{
    int t, tc= 0;
    double r1, r2, r3, x, y, z, area, a1, a2, a3, a, b, c;
    //fin(in);
    //fout(out);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf%lf%lf", &r1, &r2, &r3);
        a= r1+ r2;
        b= r2+r3;
        c= r1+r3;
        x= t_angle(a, c, b);
        y= t_angle(b, a, c);
        z= t_angle(c, b, a);
        area= t_area(a, b, c,(a+b+c)/2.0);
        a1= (x*r1*r1)/2.0;
        a2= (y*r2*r2)/2.0;
        a3= (z*r3*r3)/2.0;
        area-= (a1+a2+a3);
        printf("Case %d: %lf\n", ++tc, area);
    }
    return 0;
}

