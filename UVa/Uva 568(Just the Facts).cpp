#include<bits/stdc++.h>
using namespace std;
long long fct[10005];

void fact(int n)
{
	int i;
	long long f= 1;
	fct[0]= 1;
	for(i=1; i<=n; i++)
	{
		f*=i;
		while(f%10== 0)
			f/= 10;
        f%= 1000000;
		fct[i]= f%10;
	}
}

int main()
{
	int n;
	fact(10000);
	//freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	while(scanf("%d", &n)== 1)
	{
		printf("%5d -> %lld\n", n, fct[n]);
	}
	return 0;
}
