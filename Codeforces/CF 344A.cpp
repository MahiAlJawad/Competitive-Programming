#include<bits/stdc++.h>
#define lng long long
#define lld I64d
using namespace std;
int main()
{
    lng t, cur, x, cnt= 0;
    scanf("%lld", &t);
    scanf("%lld", &cur);
    t--;
    cnt++;
    while(t--)
    {
        scanf("%lld", &x);
        if(cur!= x)
        {
            cnt++;
            cur= x;
        }
    }
    printf("%lld\n", cnt);
    return 0;
}
