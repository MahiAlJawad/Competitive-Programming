#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <string, int> m;
    int n, i, j, k, len, max;
    string s, largest;
    char p[15];
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &n) && cin>>s)
    {
        max= -1;
        len= s.size();
        for(i= 0; i<= (len-n)+1; i++)
        {
            for(j= i, k= 0; k<n; j++, k++)
            {
                p[k]= s[j];
            }
            p[n]= NULL;
            m[p]++;

        }
        map <string, int> :: iterator it;
        for(it= m.begin(); it!= m.end(); it++)
        {
            if(it->second > max)
            {
                max= it->second;
                largest= it->first;
            }
        }
        cout<<largest<<'\n';
        m.clear();
    }



    return 0;
}
