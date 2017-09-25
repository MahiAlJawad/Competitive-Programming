#include<bits/stdc++.h>
using namespace std;
int n= 5;
int minimum(int a[], int k)
{
    int i, min, loc;
    min= a[k];
    loc= k;
    for(i= k+1; i<n; i++)
    {
        if(min> a[i])
        {
            min= a[i];
            loc= i;
        }
    }
    return loc;
}
int main()
{
    int a[5]= {48, 63, 12, 38, 987}, i;
    for(i= 0; i<n-1; i++)
    {
        int loc= minimum(a, i);
        swap(a[i], a[loc]);
    }
    printf("After sorting: ");
    for(i= 0; i<n; i++)
        printf("%d\t", a[i]);
    return 0;
}
