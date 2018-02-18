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
using namespace std;


struct node
{
    lng x, y;
};

vector<node> v;
int main()
{
    lng n, i, x, y, j;
    scanf("%lld", &n);
    for(i= 1; i<=n; i++)
    {
        scanf("%lld%lld", &x, &y);
        node f;
        f.x= x;
        f.y= y;
        v.pb(f);
    }
    lng cnt= 0;
    for(i= 0; i<n; i++)
    {
        node f= v[i];
        x= f.x;
        y= f.y;
        bool a= 0, b= 0, c= 0, d= 0;
        for(j= 0; j<n; j++)
        {
            if(i!= j)
            {

                lng k, l;
                node g= v[j];
                k= g.x;
                l= g.y;
                if(x== k && y>l) a= 1;
                else if(x== k && y<l) b= 1;
                else if(y== l && x>k) c= 1;
                else if(y== l && x<k) d= 1;
            }
        }
        if(a== 1 && b== 1 && c== 1 && d== 1) cnt++;
    }

    printf("%lld\n", cnt);
    return 0;
}


