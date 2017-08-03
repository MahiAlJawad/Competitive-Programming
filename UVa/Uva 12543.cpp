#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

int main()
{
    int i, length, mlen= -1;
    char s[105], r[105];
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%s", &s))
    {
        if(s[0]== 'E' && s[1]== '-'  && s[2]== 'N' && s[3]== '-' && s[4]== 'D')
            break;
        length= 0;
        for(i= 0; s[i]!= NULL; i++)
        {
            if(isalpha(s[i]) || s[i]== '-')
                length++;

        }
        if(length>mlen)
        {
            mlen= length;
            strcpy(r, s);
        }
    }
    for(i= 0; r[i]!= NULL; i++)
    {
        if(isalpha(r[i])||r[i]== '-')
        {
            if(isupper(r[i]))
                printf("%c", tolower(r[i]));
            else
                printf("%c", r[i]);
        }
    }
    printf("\n");
    return 0;

}
