#include<bits/stdc++.h>
using namespace std;


struct node
{
	int id= 0;
	int tm= 0;
};

bool operator <(const node &a, const node &b)
{
	if(a.tm == b.tm) return a.id>b.id;
	else return a.tm>b.tm;
}

int main()
{
    int n, i, t, q, j;
    string s;
    vector<int> x, y;
    priority_queue<node> pq;
    while(cin>>s)
    {
    	if(s== "#") break;
    	scanf("%d%d", &q, &t);
    	x.push_back(q);
    	y.push_back(t);
    }
    scanf("%d", &n);

    int sz= x.size();
    int z= n;
    for(i= 0; i<sz; i++)
    {
    	for(j= 1; j<=z; j++)
    	{
    		node a;
    		a.id= x[i];
    		a.tm= y[i]*j;
    		pq.push(a);
    	}
    }

    for(i=1; i<=n; i++)
    {
    	node a= pq.top();
    	pq.pop();
    	printf("%d\n", a.id);
    }

    return 0;
}
