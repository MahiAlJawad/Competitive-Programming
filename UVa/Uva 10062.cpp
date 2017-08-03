#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, cs= 0, a, vlen, slen;
    string s;
    map <int, int> m;
    map<int, int> :: iterator it;
    vector <int> v[1001];

    while(getline(cin, s))
    {
        cs++;
        if(cs!= 1)
            printf("\n");
        slen= s.size();
        for(i= 0; i<slen; i++)
        {
            a= s[i];
            m[a]++;
        }
        for(it= m.begin(); it!= m.end(); it++)
        {
            v[it->second].push_back(it->first);
        }
        for(i= 1; i<1001; i++)
        {
            if(!v[i].empty())
            {
                sort(v[i].begin(), v[i].end());
                vlen= v[i].size()-1;
                for(j= vlen; j>=0; j--)
                {
                    printf("%d %d\n", v[i][j], i);
                }
                v[i].clear();
            }
        }
        m.clear();


    }
    return 0;
}
