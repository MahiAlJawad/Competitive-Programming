#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, vol, maxvol= 0, l;
    string s, p;
    scanf("%d ", &n);
    getline(cin, s);
    istringstream is(s);
    while(is>> p)
    {
        vol= 0;
        l= p.size();
        for(i= 0; i<l; i++)
            if(isupper(p[i]))
                vol++;
        if(vol>maxvol)
            maxvol= vol;
    }
    printf("%d\n", maxvol);
    return 0;
}
