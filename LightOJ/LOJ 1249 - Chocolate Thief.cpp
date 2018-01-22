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
#define long long ll
#define pi acos(-1.0)
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c));//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
#define forit(it,s) for(__typeof((s).end()) it=(s).begin(); it!= (s).end(); it++)
#define gcd(a,b) __gcd(a,b)
using namespace std;
int main()
{
    int t, tc= 0, n, a, b, c, i;
    //fin(in);
    //fout(out);
    scanf("%d", &t);
    while(t--)
    {
        string s, mins, maxs;
        scanf("%d", &n);
        int mx= INT_MIN;
        int mn= INT_MAX;
        printf("Case %d: ", ++tc);
        for(i= 1; i<= n; i++)
        {
           cin>> s;
           scanf("%d%d%d", &a, &b, &c);
           int volume= a*b*c;
           if(volume> mx)
           {
               mx= volume;
               maxs= s;
           }
           if(volume< mn)
           {
               mn= volume;
               mins= s;
           }
        }
        if(mx== mn)
            printf("no thief\n");
        else
            cout<<maxs<<" took chocolate from "<<mins<<"\n";
    }
    return 0;
}


