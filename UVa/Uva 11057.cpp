#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int a[10005];
int main(){
    int i, j, n, m, min, x, y, d;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(scanf("%d", &n)== 1){

        for(i= 1; i<= n; i++){
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        min= 1000005;
        for(i= 1; i<=n; i++){

            for(j=i+1; j<=n; j++){
                d= abs(a[i]-a[j]);
                if((a[i]+a[j])== m && d<min){
                    min= d;
                    x= a[i];
                    y= a[j];
                }

            }

        }
        if(x>y)
            swap(x, y);
        printf("Peter should buy books whose prices are %d and %d.\n\n", x, y);
    }
}
