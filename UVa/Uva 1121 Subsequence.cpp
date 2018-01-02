#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, s, i;
	while(scanf("%d%d", &n, &s)== 2)
	{
		vector<int> v;
		v.push_back(0);
		for(i= 1; i<=n; i++)
		{
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}

		int b= 1, sum= 0;
		vector<int> sl;
		for(i= 1; i<= n; i++)
		{
			sum+= v[i];
			if(sum>= s)
			{
				sl.push_back((i-b)+1);
				while(1)
				{
					sum-= v[b];
					if(sum<s) break;
					else b++;
				}
				sl.push_back((i-b)+1);
				b++;
			}
		}
		int mn= 1e8;
		int vsize= sl.size();
		for(i= 0; i<vsize; i++)
		{
			if(sl[i]< mn) mn= sl[i];
		}
		if(vsize== 0) printf("0\n");
		else printf("%d\n", mn);
	}
	return 0;
}
