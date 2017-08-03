#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main()
{
    char s[30];
    int c= 0;

    while(1)
    {
      c++;
      getline(cin, s);
      if(s[0]== '#') break;

      if(strcmp(s, "HELLO")== 0)
        cout<< "Case "<<c<<": "<<"ENGLISH"<<endl;
      else if(strcmp(s, "HOLA")== 0)
        cout<< "Case "<<c<<": "<<"SPANISH"<<endl;
      else if(strcmp(s, "HALLO")== 0)
        cout<< "Case "<<c<<": "<<"GERMAN"<<endl;

      else if(strcmp(s, "BONJOUR")== 0)
        cout<< "Case "<<c<<": "<<"FRENCH"<<endl;
      else if(strcmp(s, "CIAO")== 0)
        cout<< "Case "<<c<<": "<<"ITALIAN"<<endl;
      else if(strcmp(s, "ZDRAVSTVUJTE")== 0)
        cout<< "Case "<<c<<": "<<"RUSSIAN"<<endl;
      else cout<< "Case "<<c<<": "<<"UNKNOWN"<<endl;
    }
    return 0;
}
