#include<bits/stdc++.h>
using namespace std;
int findrep(vector<int> par, int r)
{
    if(par[r]== r)
        return r;
    else
        par[r]= findrep(par, par[r]);
    return par[r];
}

int main()
{
    int tc, i, n, a, b, ra, rb, r, j;
    char c, d;
    string s;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &tc);

    for(i= 1; i<=tc; i++)
    {
        vector <int> par(30, 0);
        cin>> d;
        n= (d- 'A')+1;
        c= getchar();

        for(j= 1; j<=n; j++)
                par[j]= j;

        while(getline(cin, s))
        {
            if(s.size()== 0)
                break;

            a= (s[0]- 'A')+1;
            b= (s[1]- 'A')+1;
            ra= findrep(par, a);
            rb= findrep(par, b);
            if(ra!= rb)
                par[rb]= ra;
        }
        map <int, int> m;
        for(j= 1; j<=n; j++)
        {
            r= findrep(par, j);
            if(r!= 0)
                m[r]++;
        }
        printf("%d\n", m.size());
        if(i!= tc)
            printf("\n");
    }
    return 0;
}
