#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, vsize, j,  maxgcd, gcd;
    string line;
    vector <int> v;
    scanf("%d ", &n);
    while(n--)
    {
        getline(cin, line);
        istringstream is(line);
        while(is>> m)
        {
            v.push_back(m);
        }
        vsize= v.size();
        maxgcd= -1;
        for(i= 0; i<vsize-1; i++)
        {
            for(j= i+1; j<vsize; j++)
            {
                gcd= __gcd(v[i], v[j]);
                if(gcd>maxgcd)
                    maxgcd= gcd;
            }
        }
        printf("%d\n", maxgcd);
        v.clear();

    }
    return 0;
}
