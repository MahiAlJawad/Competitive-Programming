#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, x;
    x= "heidi";
    int len= 5, i, j;
    cin>> s;
    for(i= 0, j= 0; s[i]!= NULL; i++)
    {
        if(s[i]== x[j])
            j++;
    }
    if(j== len)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
