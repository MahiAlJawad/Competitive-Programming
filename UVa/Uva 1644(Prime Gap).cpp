#include<bits/stdc++.h>
using namespace std;
vector <int> p;
int n= 1299750;
int m[1299750];
int pg[1299750];


void sieve()
{
    int i, j, limit= sqrt(n+1), psize, g, a, b;
    m[1]= 1;
    p.push_back(2);
    for(i= 2; i<=n; i+= 2)
        m[i]= 1;

    for(i= 3; i<=n; i+=2)
    {
        if(!m[i])
        {
            p.push_back(i);
            if(i<= limit)
            {
                for(j= i*i; j<=n; j+= 2*i)
                {
                    m[j]= 1;
                }
            }
        }
    }
    psize= p.size();
    for(i= 0; i<psize-1; i++)
    {
        a= p[i];
        b= p[i+1];
        pg[a]= 0;
        pg[b]= 0;
        g= b-a;
        for(j= a+1; j< b; j++)
            pg[j]= g;
    }

}

int main()
{
    sieve();
    int num;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &num) && num!= 0)
    {
        printf("%d\n", pg[num]);
    }
    return 0;
}
