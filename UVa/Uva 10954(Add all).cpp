#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, num;
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    while(scanf("%d", &n) && n!= 0)
    {
        priority_queue<int, vector<int>, greater<int> > q;
        for(i= 1; i<= n; i++)
        {
            scanf("%d", &num);
            q.push(num);
        }
        int cost= 0;
        while(1)
        {
            int a, b;
            a= q.top();
            q.pop();
            b= q.top();
            q.pop();
            int s= a+b;
            cost+= s;
            if(q.empty())
                break;
            q.push(s);
        }
        printf("%d\n", cost);
    }
    return 0;
}
