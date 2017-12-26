#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len;
    map<string, string> m;
    string p[3], s, x;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(getline(cin, x))
    {
        if(x.size()== 0) break;
        istringstream is(x);
        int i= 0;
        while(is>> p[i++]) {}
        m[p[1]]= p[0];
    }

    while(getline(cin, s))
    {
        if(m[s]== "") printf("eh\n");
        else cout<< m[s]<<"\n";
    }

    return 0;
}
