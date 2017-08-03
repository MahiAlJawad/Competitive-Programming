#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &a)== 1){
        if(a%6== 0)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
