#include<iostream>
#include<cstdio>
#include<cmath>
#define PI acos(-1)
using namespace std;
int main(){
    int t;
    double l, w, r, red, green;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin>> t;
    while(t--){
        scanf("%lf", &l);
        w= (6.0/10.0)*l;
        r= (1.0/5.0)*l;
        red= PI*r*r;
        green= (l*w)- red;
        printf("%.2lf %.2lf\n", red, green);
    }
    return 0;
}
