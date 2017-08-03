#include<bits/stdc++.h>
using namespace std;
vector <int> prime;
vector <int> mark(20000005, 0);
vector <int> pr;
int n= 20000000;
int main()
{
    int num, i, j, x, y, psize, pos;
    int limit= sqrt(n+1);
    mark[1]= 1;

    for(i= 4; i<=n; i+= 2)
        mark[i]= 1;

    for(i= 3; i<=n; i+= 2)
    {
        if(!mark[i])
        {
            prime.push_back(i);
            if(i<= limit)
            {
                for(j= i*i; j<= n; j+= 2*i)
                    mark[j]= 1;
            }
        }
    }

    psize= prime.size();
    for(i= 0; i<psize-1; i++)
    {
        if((prime[i+1]- prime[i])== 2)
            pr.push_back(prime[i]);
    }

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while(scanf("%d", &num)== 1)
    {
        pos= num- 1;
        printf("(%d, %d)\n", pr[pos], pr[pos]+2);
    }


    return 0;
}

