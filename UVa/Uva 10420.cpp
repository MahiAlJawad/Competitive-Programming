#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
int main()
{
    string s[2005], r;
    int n, c, i, j;
    cin>> n;
    for(i= 1; i<=n; i++)
    {
        cin>> s[i];
        getline(cin, r);
    }
    for(i= 1; i<=n; i++)
    {
        c= 0;
        for(j= 1; j<=n; j++)
        {
            if(s[i].compare(s[j])!= 0)
                c++;
        }
        cout<<s[i]<<" "<<c<<endl;
    }
    return 0;
}
