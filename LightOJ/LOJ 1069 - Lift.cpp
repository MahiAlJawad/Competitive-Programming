#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, tc= 0, a, l;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &a, &l);
        int ans= 0;
        if(l<a)
          ans= (a*4)+19+ (a-l)*4;
        else
            ans= (l*4)+19;
        printf("Case %d: ", ++tc);
        printf("%d\n", ans);
    }
    return 0;
}
