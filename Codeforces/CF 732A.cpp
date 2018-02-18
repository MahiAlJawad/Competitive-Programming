#include<bits/stdc++.h>
#define lng long long
#define lld I64d
using namespace std;
int main()
{
    lng k, r;
    scanf("%lld%lld", &k, &r);
    lng sum= 0, cnt= 0;
    while(1)
    {
        sum+= k;
        cnt++;
        lng md= sum%10;
        if(md == r || md== 0) break;
    }

    printf("%lld\n", cnt);
    return 0;
}
