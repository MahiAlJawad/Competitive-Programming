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

vector<double> v;
int main()
{
    lng x, y;

    scanf("%lld%lld", &x, &y);

    lng ori= 1, cp= 0;
    int p= 0;
    while(1)
    {
        if(ori< y)
        {
            ori+= 1;
            cp+= 1;
        }
        else if(cp<=x && ori== y)
        {
            if(cp== x) p= 1;
            else if(cp!= 0 && ((cp%2== 0 && x%2== 0) || (cp%2== 1 && x%2== 1))) p= 1;
            else p= 2;
            break;
        }
        else
        {
            p= 2;
            break;
        }
    }

    if(p== 1) printf("Yes\n");
    else printf("No\n");

    return 0;
}




