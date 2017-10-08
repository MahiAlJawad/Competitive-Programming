#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1= "Bismillah";
    string s2= "llah";
    if(strstr(s1.c_str(), s2.c_str()))
        printf("String 1 contains String 2\n");
    else
        printf("String 1 does not contain String 2\n");

    return 0;
}
