#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <char , int > m;
    map <char, int> :: iterator it;
    int n, k, i, p, a;
    char c, d;
    double sum;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d ", &k);
        for(i= 1; i<=k; i++)
        {
            scanf("%c", &c);
            scanf("%d ", &a);
            m[c]= a;
        }
        sum= 0;
        scanf("%d ", &p);
        for(i= 1; i<=p; i++)
        {
            while(scanf("%c", &d) && d!= '\n')
            {
                it= m.find(d);
                if(it!= m.end())
                   sum+= it->second;
            }
        }
        printf("%.2lf$\n", sum/100);
        m.clear();
    }
    return 0;
}
