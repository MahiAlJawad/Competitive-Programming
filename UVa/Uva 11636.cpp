#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int c= 0, n, pc, line;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(scanf("%d", &n)== 1 && n>=0)
    {
        pc= 0;
        line= 1;
        while(1)
        {
            if(n<=line)
                break;
            pc++;
            line*= 2;
        }
        printf("Case %d: %d\n", ++c, pc);
    }
    return 0;
}
