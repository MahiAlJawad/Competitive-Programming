#include<bits/stdc++.h>
using namespace std;
int bigmod(int a, int b,int m)
{
    int x;
    if(b== 0) return 1;
    if(b%2== 0)
    {
        x= bigmod(a, b/2, m);
        return ((x%m)*(x%m))%m;
    }
    else
        return ((a%m)*bigmod(a, b-1, m)%m);
}

int main()
{
    int n= bigmod(2, 100, 7);
    cout<< n<<endl;
    return 0;
}
