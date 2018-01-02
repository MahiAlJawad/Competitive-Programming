#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long tc, i, x, n;
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		map<long  long, long long> m;
		vector<long long> v;
		v.push_back(0);
		for(i= 1; i<=n; i++)
		{
			scanf("%lld", &x);
			v.push_back(x);
		}

		int beg= 1, d= 0;
		int vsize= v.size();
		vector<int> longest;
		for(i= 1; i<vsize; i++)
		{
			if(m[v[i]]>= beg)
			{
				beg= m[v[i]]+1;
				longest.push_back(d);
			}
			m[v[i]]= i;
			d= (i-beg)+1;
		}
		longest.push_back(d);

		int lsize= longest.size();
		int l= 0;
		if(longest.size()!= 0) l= longest[0];
		for(i= 1 ; i<lsize; i++)
		{
			if(longest[i]> l) l= longest[i];
		}
		printf("%d\n", l);
	}

	return 0;
}
