#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int t, i, a, b, c, d, ws, we, ms, me;

    cin>> t;

    for(i= 1; i<=t; i++)
    {
       scanf("%d:%d %d:%d", &a, &b, &c, &d);
       ws= a*60+b;
       we= c*60+d;
       scanf("%d:%d %d:%d", &a, &b, &c, &d);
       ms= a*60+b;
       me= c*60+d;
       if(ms>we || me<ws)
        printf("Case %d: Hits Meeting\n", i);
       else
        printf("Case %d: Mrs Meeting\n", i);
    }




    return 0;
}
