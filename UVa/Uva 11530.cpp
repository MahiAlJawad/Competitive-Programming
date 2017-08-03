#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
    int t, i, j, c;
    char x;
    string s;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    c= getchar();
    for(i= 1; i<=t; i++){
        getline(cin, s);
        c= 0;
        for(j= 0; s[j]!= NULL; j++){
            if(s[j]=='b'||s[j]=='e'||s[j]=='h'||s[j]=='k'||s[j]=='n'||s[j]=='q'||s[j]=='u'||s[j]=='x')
                c+=2;
            else if(s[j]=='c'||s[j]=='f'||s[j]=='i'||s[j]=='l'||s[j]=='o'||s[j]=='r'||s[j]=='v'||s[j]=='y')
                c+= 3;
            else if(s[j]=='s'||s[j]=='z')
                c+=4;
            else
                c++;
        }
        printf("Case #%d: %d\n", i, c);
    }
    return 0;
}
