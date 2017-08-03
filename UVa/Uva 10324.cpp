#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int i, j, a, b, mx, mn, n, l, cs= 0;
    string s;
    char c;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin>> s)
    {
        l= s.length();
        if(l== 0)
            break;
        scanf("%d", &n);
        printf("Case %d:\n", ++cs);
        for(i= 1; i<=n; i++)
        {
            scanf("%d%d", &a, &b);
            mx= max(a, b);
            mn= min(a, b);
            c= s[mn];
            for(j= mn+1; j<=mx; j++)
            {
                if(c!= s[j])
                    break;
                c= s[j];
            }
            if(j== (mx+1))
                printf("Yes\n");
            else
                printf("No\n");
        }
        getchar();
    }
    return 0;
}
