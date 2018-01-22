/******************************************************************************************************************************
*** "In the name of Allah(swt), the most gracious, most merciful. Allah(swt) blesses with knowledge to whom he wants."      ***
***     Author     : Mahi Al Jawad                                                                                          ***
***     University : Dept. of CSE, IIUC                                                                                     ***
***     github     : https://github.com/MahiAlJawad                                                                         ***
***     Email      : br.mahialjawad@gmail.com                                                                               ***
***     facebook   : https://www.facebook.com/jawad.wretched                                                                ***
*******************************************************************************************************************************/

#include<bits/stdc++.h>
#define fin(in) freopen("in.txt", "r", stdin)
#define fout(out) freopen("out.txt", "w", stdout)
#define pb push_back
#define ll long long
#define pi acos(-1.0)
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c));//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
#define forit(it,s) for(__typeof((s).end()) it=(s).begin(); it!= (s).end(); it++)
#define gcd(a,b) __gcd(a,b)
#define string_reverse(s) reverse(s.begin(), s.end())//Vector also can be reversed with this function
#define mx 100005
using namespace std;

ll a[mx], tree[3*mx], prop[3*mx];

void init(ll node, ll b, ll e)
{
    if(b== e)
    {
        tree[node]= a[b];
        return;
    }
    ll left= 2*node;
    ll right= left+1;
    ll mid= (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node]= tree[left]+ tree[right];
}
void update(ll node, ll b, ll e, ll i, ll j, ll x)
{
    if(b>j || e<i) return;
    if(b>= i && e<= j)
    {
        prop[node]+= x;
        tree[node]+= ((e-b+1)*x);
        return;
    }
    ll left= 2*node;
    ll right= left+1;
    ll mid= (b+e)/2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);
    tree[node]= tree[left]+ tree[right]+ ((e-b+1)*prop[node]);
}
ll query(ll node, ll b, ll e, ll i, ll j, ll carry)
{
    if(b> j || e<i) return 0;
    if(b>= i && e<= j)
    {
        return tree[node] + (e-b+1)*carry;
    }
    ll left= 2*node;
    ll right= left+1;
    ll mid= (b+e)/2;
    ll p1= query(left, b, mid, i, j, carry+prop[node]);
    ll p2= query(right, mid+1, e, i, j, carry+prop[node]);
    return p1+p2;
}


int main()
{
    ll t, q, m, i, j, x, tc= 0, n;
    //fin(in);
    //fout(out);
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld", &n, &q);
        memset(a, 0, sizeof(a));
        memset(tree, 0, sizeof(tree));
        memset(prop, 0, sizeof(prop));
        init(1, 1, n+1);
        printf("Case %lld:\n", ++tc);
        while(q--)
        {
            scanf("%lld", &m);
            if(m== 0)
            {
                scanf("%lld%lld%lld", &i, &j, &x);
                update(1, 1, n+1, i+1, j+1, x);
            }
            else
            {
                scanf("%lld%lld", &i, &j);
                printf("%lld\n", query(1, 1, n+1, i+1, j+1, 0));
            }
        }
    }
    return 0;
}


