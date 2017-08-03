#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int t, a, b, c;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        if((a+b)<=c || (b+c)<= a || (a+c)<= b)
            printf("Wrong!!\n");
        else
            printf("OK\n");
    }
    return 0;
}
