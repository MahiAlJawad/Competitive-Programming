#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i= 0;
    long long a;
    vector <long long> v;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &a)== 1)
    {
        i++;
        v.push_back(a);
        sort(v.begin(), v.end());
        if(i%2== 0)
            printf("%d\n", (v[(i/2)-1]+v[i/2])/2);
        else
            printf("%d\n", v[i/2]);
    }
    return 0;
}
