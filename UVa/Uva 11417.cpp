#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int gcd(int a, int b)
{
    int r;
    r= b%a;
    if(r== 0)
        return a;
    else
        return gcd(r, a);
}

int main()
{
    int n, i, j,  x, y, g;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &n)== 1 && n!=0)
    {
        g= 0;
        for(i= 1; i<n; i++)
        {
            for(j= i+1; j<=n; j++)
            {
               x= i;
               y= j;
               if(x>y)
                    swap(x, y);
               g+= gcd(x, y);
            }
        }
        printf("%d\n", g);
    }
}
