#include<iostream>
#include<string>
#include<cstring>
#include<cctype>

using namespace std;
int main()
{
    int i, j;
    string keyboard= "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./", s;
    while(getline(cin, s))
    {
       for(i= 0; s[i]!= NULL; i++)
       {

           for(j= 0; keyboard[j]!= NULL; j++)
           {
               if(s[i]== keyboard[j])
                s[i]= keyboard[j-1];
           }
       }
       cout<< s<< endl;

    }
    return 0;
}

