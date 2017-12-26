#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, i, x, sum;
    string s, p, q;
    map<string, int> mp;

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d%d", &m, &n);
    for(i= 1; i<= m; i++)
    {
        cin>>s>>x;
        mp[s]= x;
    }

    for(i= 1; i<=n; i++)
    {
        sum= 0;
        while(getline(cin, p))
        {
            if(p== ".") break;
            istringstream is(p);
            while(is>>q)
            {
                sum+= mp[q];
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}
