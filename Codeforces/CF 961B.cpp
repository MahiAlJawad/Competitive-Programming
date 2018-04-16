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
#define lng long long
#define lld I64d//for CF submissions
#define pi acos(-1.0)
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c));//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
#define forit(it,s) for(__typeof((s).end()) it=(s).begin(); it!= (s).end(); it++)
#define gcd(a,b) __gcd(a,b)
#define string_reverse(s) reverse(s.begin(), s.end())//Vector also can be reversed with this function
#define inf LONG_LONG_MAX
#define neginf LONG_LONG_MIN
#define rh cout<<"Reached Here\n";
#define sz 100005
using namespace std;


lng arr[sz], con[sz];
lng tree[4*sz];

void init(lng node, lng b, lng e)
{
    if(b== e)
    {
        if(con[b]== 0)
            tree[node]= arr[b];
        else tree[node]= 0;
        return;
    }
    lng left= 2*node;
    lng right= 2*node+1;
    lng mid= (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node]= tree[left]+tree[right];
}

lng query(lng node, lng b, lng e, lng i, lng j)// returns the summation of the array from i to j
{
    if(i> e|| j<b)
        return 0;// not relevant segment
    if(b>= i && e<=j)
        return tree[node];//relevant segment
    lng left= 2*node;
    lng right= 2*node+1;
    lng mid= (b+e)/2;
    lng p1= query(left, b, mid, i, j);
    lng p2= query(right, mid+1, e, i, j);
    return p1+p2;
}


int main()
{
    fin(in);
    fout(out);
    lng n, k, i, j;
    scanf("%lld%lld", &n, &k);

    for(i= 1; i<=n; i++)
    {
        scanf("%lld", &arr[i]);

    }

    for(i= 1; i<=n; i++)
    {
        scanf("%lld", &con[i]);
    }

    init(1, 1, n);
    lng lim= n+k-1;
    lng mx= neginf, st= 0, fn= 0, ans= 0;

    for(i= 1; i<=lim; i++)
    {
        lng x= query(1, 1, n, i, i+k-1);
        if(x>mx)
        {
            mx= x;
            st= i;
            fn= i+k-1;
        }
    }
    ans= mx;
    for(i= 1; i<=n; i++)
    {
        if(con[i]== 1) ans+= arr[i];
    }

    printf("%lld\n", ans);

    return 0;
}


