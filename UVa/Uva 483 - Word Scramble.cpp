#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    char c;

    while(scanf("%c", &c)== 1)
    {
        if(c== ' ' || c== '\n')
        {
            reverse(s.begin(), s.end());
            cout<<s<<c;
            s= "";
        }
        else s+= c;
    }
    return 0;
}
