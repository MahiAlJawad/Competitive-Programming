#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a, b, c, d, x, y, z, degree;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d%d%d%d", &a, &b, &c, &d)== 4)
    {
        if(a== 0 && b== 0 && c== 0 && d== 0)
            break;
        if(a<b)
            x= ((40+a)-b)*9;
        else
            x= (a-b)*9;
        if(c<b)
            y= ((40+c)-b)*9;
        else
            y= (c-b)*9;
        if(c<d)
            z= ((40+c)-d)*9;
        else
            z= (c-d)*9;

        degree= 1080+x+y+z;
        printf("%d\n", degree);
    }
    return 0;
}
