#include<bits/stdc++.h>
using namespace std;
int NOD(int n)
{
    int i, nod= 1, a;
    for(i= 2; i*i<=n; i++)
    {
        a= 0;
        if(n%i== 0)
        {
            while(n%i== 0)
            {
                n/= i;
                a++;
            }
            nod*= (a+1);
        }
    }
    if(n>1)
    {
        nod*= 2;
    }
    return nod;
}

int main()
{
    int i, j, n, u, l, nod, maxnod, p;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d", &l, &u);
        maxnod= -1;
        for(i= l; i<= u; i++)
        {
            nod= NOD(i);
            if(nod>maxnod)
            {
                maxnod= nod;
                p= i;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",l, u, p, maxnod);
    }
    return 0;
}

