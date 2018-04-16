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

using namespace std;

int main()
{
    ll n, i;
    scanf("%lld", &n);
    vector<ll> arr;
    vector<ll>  v, nm, org;
    for(i= 1; i<=n; i++)
    {
        ll x;
        scanf("%lld", &x);
        arr.pb(x);
    }

    v= arr;
    sort(v.begin(), v.end());

    ll st= 0, fn= 0;
    bool flag= 1;

    for(i= 0; i<n; i++)
    {
        if(fn!= 0 && v[i]!= arr[i])
        {
            flag= 0;
            break;
        }
        if(fn== 0 && v[i]!= arr[i])
        {
            if(st== 0) st= i+1;
            nm.pb(arr[i]);
            org.pb(v[i]);
            if(i== n-1) fn= n;
        }

        if(st!= 0 && fn== 0 && v[i]== arr[i])
        {
            if(i+1<n && v[i+1]== arr[i+1])
            {
                fn= i;
            }
            else if(i== n-1) fn= i;
        }

    }

    string_reverse(nm);
    if(nm!= org) flag= 0;

    /*forit(it, nm) cout<<*it<<" ";
    cout<<endl;

    forit(it, org) cout<<*it<<" ";
    cout<<endl;
    */
    if(flag && st== 0 && fn== 0){
        st= 1; fn= 1;
    }
    if(flag)
    {
        printf("yes\n");
        printf("%lld %lld\n", st, fn);
    }
    else printf("no\n");

    return 0;
}


