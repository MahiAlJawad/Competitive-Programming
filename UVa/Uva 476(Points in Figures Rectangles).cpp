#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[5];
    int i= 0, p= 0, j, flag;
    double x1[12], y1[12], x2[12], y2[12], x, y;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%s", s))
    {
        if(s[0]== '*') break;
        i++;
        scanf("%lf %lf %lf %lf ", &x1[i], &y1[i], &x2[i], &y2[i]);
    }

    while(scanf("%lf%lf", &x, &y)== 2)
    {
        if(x== 9999.9 && y== 9999.9) break;
        p++;
        flag= 0;
        for(j= 1; j<=i; j++)
        {
            if((x>x1[j] && x<x2[j]) && (y>y2[j] && y<y1[j]))
            {
                printf("Point %d is contained in figure %d\n", p, j);
                flag= 1;
            }
        }
        if(flag== 0) printf("Point %d is not contained in any figure\n", p);

    }

    return 0;
}
