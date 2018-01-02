#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    memset(a, 0, sizeof(a));
    long long n, i, mn= 100000000000, dis;
    cin>> n;
    for(i= 1; i<=n; i++)
    {
        cin>> a[i];
        if(a[i]<mn) mn= a[i];
    }

    vector<int> pos;
    for(i= 1; i<=n; i++)
    {
        if(mn== a[i]) pos.push_back(i);
    }
    long long vsize= pos.size();
    for(i= 1; i<vsize; i++)
    {
        if(pos[i]-pos[i-1] < dis) dis= pos[i]-pos[i-1];
    }
    cout<<dis<<"\n";

    return 0;
}
