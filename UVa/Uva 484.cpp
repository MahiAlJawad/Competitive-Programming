#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int > m;
    vector<int> v;
    int n;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while(scanf("%d", &n)== 1)
    {
        if(find(v.begin(), v.end(), n)== v.end()) v.push_back(n);
        m[n]++;
    }

    int i, sz= v.size();

    for(i= 0; i<sz; i++)
    {
        printf("%d %d\n", v[i], m[v[i]]);
    }

    return 0;
}
