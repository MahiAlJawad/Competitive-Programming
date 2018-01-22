#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, tc= 0;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	double ox, oy, ax, ay, bx, by, r, a, s;
	scanf("%d", &t);
	while(t--)
	{
		printf("Case %d: ",++tc);
		scanf("%lf%lf%lf%lf%lf%lf", &ox, &oy, &ax, &ay, &bx, &by);
		r= sqrt(((ox-ax)*(ox-ax))+((oy-ay)*(oy-ay)));
		
		a= sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));
		cout<<r<<endl;
		cout<<a<<endl;
		s= r*(acos(((2*r*r)- a*a)/(2*r*r)));
		printf("%lf\n", s);		
	}
	return 0;
}