#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ll w, h, x, y;
  cin>>w>>h>>x>>y;

  ll d= (2*x)==w && (2*y)== h;
  printf("%.6lf %lld\n", ((double)w*(double)h)/2.0, d);

 return 0;
}
