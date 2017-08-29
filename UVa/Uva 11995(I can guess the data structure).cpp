#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, i;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &n)== 1)
    {
        int x= 1, y= 1, z= 1;
        stack <int> s;
        queue <int> q;
        priority_queue<int> pq;

        while(n--)
        {
            scanf("%d%d", &a, &b);
            if(a== 1)
            {
                s.push(b);
                q.push(b);
                pq.push(b);
            }
            else
            {
                if(s.size()== 0 || b!= s.top()) x= 0;
                if(q.size()== 0 || b!= q.front()) y= 0;
                if(pq.size()== 0 || b!= pq.top()) z= 0;

                if(x== 1) s.pop();
                if(y== 1) q.pop();
                if(z== 1) pq.pop();
            }
        }
         if(x== 0 && y== 0 && z== 0) printf("impossible\n");
         else if(x== 1 && y== 0 && z== 0) printf("stack\n");
         else if(x== 0 && y== 1 && z== 0) printf("queue\n");
         else if(x== 0 && y== 0 && z== 1) printf("priority queue\n");
         else printf("not sure\n");
    }
    return 0;
}

