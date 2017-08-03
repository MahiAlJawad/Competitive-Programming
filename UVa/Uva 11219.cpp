#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t, i, a, b, c, x, y, z, year, age;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin>> t;
    for(i= 1; i<=t; i++)
    {
        scanf("%d/%d/%d", &a, &b, &c);
        scanf("%d/%d/%d", &x, &y, &z);
        year= ((c-z)*365)+((b-y)*30)+(a-x);
        age= year/365;
        if((z>c) || (z== c && y>b) || (z== c && y== b && x>a))
            printf("Case #%d: Invalid birth date\n", i);
        else if(age>130)
            printf("Case #%d: Check birth date\n", i);
        else
            printf("Case #%d: %d\n", i, age);
    }
    return 0;
}
