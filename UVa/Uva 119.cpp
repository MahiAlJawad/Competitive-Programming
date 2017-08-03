#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> m;
    string s[12], x;
    int i, j, n, a, p;
    cin>> n;
    while(1)
    {
        for(i= 1; i<=n; i++)
        {
            cin>> s[i];
            m[s[i]]= 0;
        }
        for(i= 1; i<=n; i++)
        {
            cin>>x>>a>>p;
            if(p!= 0)
            {

                if(a%p==  0)
                {
                    m[x]-= a;
                }
                else
                {
                    m[x]-= a-(a%p);
                }
                for(j= 1; j<=p ; j++)
                {
                    cin>> x;
                    m[x]+= (a-(a%p))/p;
                }
            }
        }
        for(i= 1; i<=n; i++)
        {
            cout<<s[i]<<" "<<m[s[i]]<<'\n';
        }
        if(cin>> n)
            printf("\n");
        else
            break;
    }
    return 0;
}
