#include<bits/stdc++.h>
using namespace std;

int level[33];

map<int, int> m;
int bfs(int s, int ttl, vector<int> adj[33])
{
	queue<int> q;
	int u, v, i, sz, count= 1;
	q.push(s);
	level[s]= 0;
	if(s== 0) return 0;
	while(!q.empty())
	{
		u= q.front();
		q.pop();

		if(level[u]==ttl) break;
		sz= adj[u].size();
		for(i= 0; i<sz; i++)
		{
			v= adj[u][i];
			if(level[v]== -1)
			{
				count++;
				q.push(v);
				level[v]= level[u]+1;
			}
		}
	}

	return count;
}



int main()
{
	int nc, tc= 0, u, v, i, s, ttl;

	while(scanf("%d", &nc)== 1 && nc!=0)
	{

		vector<int> adj[33];
		int c= 0;
		for(i= 1; i<=nc; i++)
		{
			scanf("%d%d", &u, &v);
			if(m[u]== 0) m[u]= ++c;
			if(m[v]== 0) m[v]= ++c;
			adj[m[u]].push_back(m[v]);
			adj[m[v]].push_back(m[u]);
		}


		while(scanf("%d%d", &s, &ttl)== 2)
		{
			if(s== 0 && ttl== 0) break;
			memset(level, -1 , sizeof(level));
			int temp= bfs(m[s], ttl, adj);
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++tc, c-temp, s, ttl);
		}

		m.clear();
	}

	return 0;
}
