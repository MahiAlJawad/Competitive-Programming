#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    string s;
    int i;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt","w", stdout);
    while(scanf("%c", &c)== 1)
    {
        if(isalpha(c))
        {
            s+= c;
        }
        else
        {
            if(s.size()== 0)
                printf("%c", c);
            else
            {
                if(s[0]== 'a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u'||s[0]== 'A'||s[0]=='E'||s[0]=='I'||s[0]=='O'||s[0]=='U')
                {
                    s+= "ay";
                    cout<<s+c;
                    s= "";
                }
                else
                {
                    s+= s[0];
                    s+= "ay";
                    for(i=1; s[i]!= NULL; i++)
                        printf("%c", s[i]);
                    printf("%c", c);
                    s= "";
                }
            }
        }
    }
    return 0;
}
