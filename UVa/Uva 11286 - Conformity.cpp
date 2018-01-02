#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, x;

    while(scanf("%d", &n)== 1)
    {
        if(n== 0) break;
        map<int, set<int> > m;
        map<set<int>, int> mp;
        for(i= 1; i<=n; i++)
        {
            set<int> s;
            for(j= 1; j<=5; j++)
            {
                scanf("%d", &x);
                s.insert(x);
            }
            m[i]= s;
            mp[s]++;
        }
        map<set<int>, int> :: iterator it;
        int mx= -1;
        for(it= mp.begin(); it!= mp.end(); it++)
        {
            if(it->second > mx) mx= it->second;
        }

        int cnt= 0;
        map<int, set<int> > :: iterator it1;
        for(it1= m.begin(); it1!= m.end(); it1++)
        {
            if(mp[it1->second]== mx) cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
