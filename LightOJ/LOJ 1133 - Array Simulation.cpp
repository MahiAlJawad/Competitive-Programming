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
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/ //including this two lines will cause to get a Runtime error!
    ll t, tc= 0, i, n, m, x, y;
    char c;
    //fin(in);
    //fout(out);
    cin>> t;
    while(t--)
    {
        vector<int> v;
        cin>>n>>m;
        for(i= 1; i<=n; i++)
        {
            cin>> x;
            v.pb(x);
        }
        int vsize= v.size();
        while(m--)
        {
            cin>> c;
            if(c== 'S')
            {
                cin>> x;
                for(i= 0; i<vsize; i++)
                {
                    v[i]+= x;
                }
            }
            else if(c== 'M')
            {
                cin>> x;
                for(i= 0; i<vsize; i++)
                {
                    v[i]*= x;
                }
            }
            else if(c== 'D')
            {
                cin>> x;
                for(i= 0; i<vsize; i++)
                {
                    v[i]/= x;
                }
            }
            else if(c== 'R')
            {
                reverse(v.begin(), v.end());
            }
            else
            {
                cin>>x>>y;
                swap(v[x], v[y]);
            }
        }
        cout<<"Case "<<++tc<<":\n";
        for(i= 0; i<vsize; i++)
        {
            if(i!= 0) cout<<" ";
            cout<<v[i];
        }
        cout<<"\n";
    }
    return 0;
}

