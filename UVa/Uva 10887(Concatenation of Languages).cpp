#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc, i, a, b, j, k;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &tc);

    for(k= 1; k<=tc; k++)
    {
        scanf("%d%d", &a, &b);
        int c= a+b;
        string m[1505], n[1505], x;
        set <string> s;
        char ch= getchar();
        for(i= 1; i<= a; i++)
            getline(cin, m[i]);
        for(i= 1; i<=b; i++)
            getline(cin, n[i]);

        for(i= 1; i<= a; i++)
        {
            for(j= 1; j<=b; j++)
            {
                x= m[i]+n[j];
                s.insert(x);
            }
        }
        printf("Case %d: %d\n", k, s.size());
    }
    return 0;
}
