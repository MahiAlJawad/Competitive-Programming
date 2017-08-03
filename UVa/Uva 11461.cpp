#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool square(int n)
{
    int m;
    m= sqrt(n);
    if((m*m)==n)
        return true;
    else
        return false;
}

int main()
{
    int a, b, i, c;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d%d", &a, &b)== 2)
    {
        if(a== 0 && b== 0)
            break;
        c= 0;
        for(i= a; i<=b; i++)
        {
            if(square(i))
                c++;
        }
        printf("%d\n", c);
    }
    return 0;
}
