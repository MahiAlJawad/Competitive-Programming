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

using namespace std;

int main()
{
    lng t, i, sx, sy, ex, ey, px, py, sec;
    char rx, ry;
    string s;
    scanf("%lld%lld%lld%lld%lld", &t, &sx, &sy, &ex, &ey);
    cin>> s;
    px= sx- ex;
    py= sy- ey;

    if(px>0) rx= 'W';
    else if(px<0) rx= 'E';
    if(py>0) ry= 'S';
    else if(py<0) ry= 'N';

    for(i= 0; i<t; i++)
    {
        if(s[i]== rx || s[i]== ry)
        {
            if(py!= 0 && s[i]== 'N')
            {
                py++;
            }
            else if(px!= 0 && s[i]== 'E')
            {
                px++;
            }
            else if(py!= 0 && s[i]== 'S')
            {
                py--;
            }
            else if(px!= 0 && s[i]== 'W')
            {
                px--;
            }
        }
        if(px== 0 && py== 0)
        {
            sec= i+1;
            break;
        }
    }

    if(px== 0 && py== 0) printf("%lld\n", sec);
    else  printf("-1\n");

    return 0;
}


