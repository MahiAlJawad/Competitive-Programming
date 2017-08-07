#include<bits/stdc++.h>
#define PI 2*acos(0.0)
using namespace std;
int main()
{
    int t, cs= 0;
    double r;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf", &r);
        printf("Case %d: %.2lf\n", ++cs, (2*r*2*r)- PI*r*r);
    }
    return 0;
}
