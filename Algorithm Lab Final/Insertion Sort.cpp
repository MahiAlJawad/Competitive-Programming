#include<bits/stdc++.h>
using namespace std;

int n= 5;

int main()
{
    int a[5]= {48, 63, 12, 38, 987}, i, j, key;
    for(i= 1; i<n; i++)
    {
        key= a[i];
        for(j= i-1; j>= 0 && a[j]>key; j--)
        {
            a[j+1]= a[j];
        }
        a[j+1]= key;
    }
    printf("After sorting : ");
    for(i= 0; i<n; i++)
        printf("%d\t", a[i]);
    return 0;
}
