#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, p= "";
    int len, i= 0, k;
    cin>>s;
    len= s.size();
    while(i<len)
    {
        if(s[i]== '1')
        {
            k= i;
            p+= '1';
            break;
        }
        i++;
    }

    for(i= k+1; i<len; i++)
    {
        if(s[i]== '0') p+= '0';
    }

    if(p.size()>=7)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
