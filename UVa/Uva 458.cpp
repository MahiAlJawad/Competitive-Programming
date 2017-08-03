#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    int i;
    while(getline(cin, s))
    {

        for(i= 0; s[i]!=NULL; i++)
        {
           s[i]= s[i]-7;

        }
        cout<<s<<endl;;

    }
    return 0;
}
