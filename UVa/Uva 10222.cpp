#include<iostream>
#include<string>
#include<cstring>
#include<cctype>

using namespace std;
int main()
{
    int i, j;
    string keyboard= "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./`1234567890-=", s;
    while(getline(cin, s))
    {
       for(i= 0; s[i]!= NULL; i++)
       {
           s[i]= tolower(s[i]);
           for(j= 0; keyboard[j]!= NULL; j++)
           {
               if(s[i]== keyboard[j])
                s[i]= keyboard[j-2];
           }
       }
       cout<< s<< endl;

    }
    return 0;
}
