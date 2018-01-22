#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, tc= 0, n, i, k;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		int total= 0;
		string s;
		scanf("%d", &n);
		printf("Case %d:\n", ++tc);
		for(i= 1 ; i<=n; i++)
		{
			cin>> s;
			if(s== "donate")
			{
				scanf("%d", &k);
				total+= k;
			}
			else
				printf("%d\n", total);
		}
	}
	return 0;
}