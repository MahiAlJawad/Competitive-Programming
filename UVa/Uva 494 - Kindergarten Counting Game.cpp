#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c, pc= '\n';
    int count= 0;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while(scanf("%c", &c)== 1)
    {
        if(isalpha(pc) && !isalpha(c)) count++;
        pc= c;
        if(pc== '\n')
        {
            printf("%d\n", count);
            count= 0;
        }
    }
    return 0;
}
