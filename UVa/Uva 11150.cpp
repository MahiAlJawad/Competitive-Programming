#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n, a, count;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &n)== 1)
    {
        if(n== 1)
            count= 1;
        else
        {
            count= 0;
            while(1)
            {
                if(n==2)
                {
                    n++;
                    a= n;
                    n/=3;
                }
                else if(n%3!= 0 && n>3)
                {
                    a= (n/3)*3;
                    n= (n/3)+(n%3);
                }
                else if(n%3== 0)
                {
                    a= n;
                    n/=3;
                }
                else if(n== 0)
                    break;
                count+= a;

            }
        }
        printf("%d\n", count);
    }
    return 0;
}
