#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long p, c, i, tc=  0;

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	while(scanf("%lld%lld", &p, &c)== 2 && p!= 0 && c!= 0)
	{
		deque<long long> q;
		for(i= 1; i<= p && i<= 1000; i++)
		{
			q.push_back(i);
		}
		char s[5];
		printf("Case %lld:\n", ++tc);
		for(i= 1; i<=c; i++)
		{
			scanf("%s", s);
			if(s[0]== 'N')
			{
				long long x= q.front();
				printf("%lld\n", x);
				q.pop_front();
				q.push_back(x);
			}
			else
			{
				long long x;
				scanf("%lld", &x);
				deque<long long> :: iterator it;
				for(it= q.begin(); it!= q.end(); it++)
				{
					if(*it== x)
					{
						q.erase(it);
						break;
					}
				}
				q.push_front(x);
			}
		}
	}

	return 0;
}
