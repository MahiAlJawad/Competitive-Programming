#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t, cs= 0;
   long long x, m, n, s;
   //freopen("in.txt", "r", stdin);
   //freopen("out.txt", "w", stdout);
   scanf("%d", &t);

   while(t--)
   {
       scanf("%lld", &s);
       x= ceil(sqrt(s));
       if(x%2== 0)
       {
           if(s<= ((x-1)*(x-1))+ x)
           {
               m= s- ((x-1)*(x-1));
               n= x;
           }
           else
           {
               m= x;
               n= ((x*x)-s)+1;
           }
       }
       else
       {
           if(s<= ((x-1)*(x-1))+ x)
           {
               n= s- ((x-1)*(x-1));
               m= x;
           }
           else
           {
               n= x;
               m= ((x*x)-s)+1;
           }
       }
       printf("Case %d: %lld %lld\n", ++cs, m, n);
   }
   return 0;
}
