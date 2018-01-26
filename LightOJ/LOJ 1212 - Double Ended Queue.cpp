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
using namespace std;

int main()
{
    int t, x, tc= 0, i, n, m, sz;
    string s;
    //fin(in);
    //fout(out);
    scanf("%d", &t);
    while(t--)
    {
        deque<int> dq;
        scanf("%d%d", &n, &m);
        printf("Case %d:\n", ++tc);
        while(m--)
        {
            sz= dq.size();
            cin>> s;
            if(s== "pushLeft")
            {
                scanf("%d", &x);
                if(sz== n)
                    printf("The queue is full\n");
                else
                {
                    dq.push_front(x);
                    printf("Pushed in left: %d\n", x);
                }
            }
            else if(s== "pushRight")
            {
                scanf("%d", &x);
                if(sz== n)
                    printf("The queue is full\n");
                else
                {
                    dq.push_back(x);
                    printf("Pushed in right: %d\n", x);
                }
            }
            else if(s== "popLeft")
            {
                if(sz== 0)
                    printf("The queue is empty\n");
                else
                {
                    x= dq.front();
                    dq.pop_front();
                    printf("Popped from left: %d\n", x);
                }
            }
            else
            {
                if(sz== 0)
                    printf("The queue is empty\n");
                else
                {
                    x= dq.back();
                    dq.pop_back();
                    printf("Popped from right: %d\n", x);
                }
            }
        }
    }
    return 0;
}


