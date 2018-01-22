#include<bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
int main()
{
	int t, tc= 0;
	double r1, r2, R, h, p;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf", &R, &r2, &h, &p);
		r1= r2+ ((R-r2)*p)/h;
		double volume= (pi*p*((r1*r1)+(r2*r2)+ (r1*r2)))/3.0;
		printf("Case %d: %lf\n",++tc, volume);
	}
	return 0;
}
