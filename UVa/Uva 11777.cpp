#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int i, t, j;
    double a[5], c[4], ct, total, s, m;


    cin>> t;
    for(i= 1; i<=t; i++)
    {
        s= 0;
        for(j= 1; j<= 4; j++)
        {
            cin>> a[j];
            s+= a[j];
        }
        ct= 0;
        for(j= 1; j<= 3; j++)
        {
            cin>> c[j];
            ct+= c[j];
        }
        m= min(c[1], min(c[2], c[3]));
        ct= (ct-m)/2;
        total= s+ct;
        if(total>=90)
            printf("Case %d: A\n", i);
        else if(total>= 80 && total<90)
            printf("Case %d: B\n", i);
        else if(total>= 70 && total<80)
            printf("Case %d: C\n", i);
        else if(total>= 60 && total<70)
            printf("Case %d: D\n", i);
        else
            printf("Case %d: F\n", i);

    }
    return 0;
}
