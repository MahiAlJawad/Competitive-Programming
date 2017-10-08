#include<bits/stdc++.h>
using namespace std;
int main()
{
    int bin[4][4], i, j, x[4], flag, sum;
    long long mx;
    string s;
    //freopen("in.txt","r", stdin);
    //freopen("out.txt", "w", stdout);
    map<char, int> m;
    m['B']= 1;
    m['C']= 2;
    m['G']= 3;

    while(scanf("%d%d%d%d%d%d%d%d%d",&bin[1][1],&bin[1][3],&bin[1][2], &bin[2][1],&bin[2][3],&bin[2][2], &bin[3][1],&bin[3][3],&bin[3][2])== 9)
    {
        mx= 100000000000000;
        vector<char> c;
        c.push_back('B');
        c.push_back('C');
        c.push_back('G');
        do
        {
            sum= 0;
            x[1]= m[c[0]];
            x[2]= m[c[1]];
            x[3]= m[c[2]];

            for(i= 1; i<= 3; i++)
            {
                for(j= 1; j<=3; j++)
                {
                    if(x[i]!= j)
                        sum+= bin[i][j];
                }
            }

            if(sum<mx)
            {
                mx= sum;
                s= "";
                s+= c[0];
                s+= c[1];
                s+= c[2];
            }
        }while(next_permutation(c.begin(), c.end()));
        cout<<s;
        printf(" %d\n", mx);
    }

    return 0;
}
