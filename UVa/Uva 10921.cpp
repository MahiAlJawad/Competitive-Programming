#include<iostream>
#include<string>
using namespace std;

int main()
{
    int i;
    string s;

    while(cin>> s)
    {
        for(i=0 ; s[i]!=NULL; i++)
        {
           if(s[i]>='A' && s[i]<='C')
                cout<< 2;
           else if(s[i]>='D' && s[i]<='F')
            cout<< 3;
           else if(s[i]>='G' && s[i]<='I')
            cout<< 4;
           else if(s[i]>='J' && s[i]<='L')
            cout<< 5;
           else if(s[i]>='M' && s[i]<='O')
            cout<< 6;
           else if(s[i]>='P' && s[i]<='S')
            cout<< 7;
           else if(s[i]>='T' && s[i]<='V')
            cout<< 8;
           else if(s[i]>='W' && s[i]<='Z')
            cout<< 9;
           else if(s[i]== '1')
            cout<< 1;
           else if(s[i]== '0')
            cout<< 0;
           else
            cout<< "-";
        }
        cout<< endl;
    }
    return 0;
}
