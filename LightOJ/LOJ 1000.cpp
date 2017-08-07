#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int a, b;
    int t, cs= 0;
    scanf("%d", &t);
    while(t--)
    {
        cs++;
        scanf("%u%u", &a, &b);
        printf("Case %d: %u\n", cs, a+b);

    }
    return 0;
}
