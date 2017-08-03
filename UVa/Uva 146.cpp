#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <char> s;
    int i;
    char c;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(1)
    {
        while(scanf("%c", &c)== 1 && c!= '#' && c!= '\n')
        {
            s.push_back(c);
        }
        if(c== '#')
            break;
        if(next_permutation(s.begin(), s.end()))
            for(i= 0; i<s.size(); i++)
                printf("%c", s[i]);
        else
            printf("No Successor");
        printf("\n");
        s.clear();
    }
    return 0;
}
