#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<long long, vector<int>, greater<int> > pq;
    int counter= 1;
    long long c, nc;
    c= 1;
    pq.push(2);
    pq.push(3);
    pq.push(5);
    //freopen("out.txt", "w", stdout);
    while(counter<1500)
    {
        nc= pq.top();
        pq.pop();
        counter++;
        while(c>= nc)
        {
            nc= pq.top();
            pq.pop();
        }
        c= nc;
        pq.push(2*c);
        pq.push(3*c);
        pq.push(5*c);
    }
    printf("The 1500'th ugly number is %d.\n", c);

    return 0;
}
