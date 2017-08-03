#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
int main()
{
    int t, p, b, i;
    string s;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        p= 0;
        b= 0;
        cin>> s;
        for(i= 0; s[i]!= NULL; i++)
        {
            if(s[i]== '(')
                p++;
            else if(s[i]== ')')
                p--;
            else if(s[i]== '[')
                b++;
            else if(s[i]== ']')
                b--;
        }
        if(p== 0 && b== 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
