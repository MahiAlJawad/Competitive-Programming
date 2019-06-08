#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

struct node
{
    ll x, y;
};
bool cmp(node a, node b)
{
    if(a.x== b.x)
    {
        return a.y>b.y;
    }
    else return a.x<b.x;
}
vector<node> v;
int main()
{

    node a, b, c;
    a.x= 1;
    a.y= 2;
    b.x= 2;
    b.y= 3;
    c.x= 2;
    c.y= 4;
    v.pb(b);
    v.pb(a);
    v.pb(c);
    sort(v.begin(), v.end(), cmp);
    ll i;
    for(i= 0; i<v.size(); i++)
    {
        cout<<v[i].x<<" "<<v[i].y<<endl;
    }
    return 0;
}
