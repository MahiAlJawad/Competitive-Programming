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

vector<lng> v[100005];

bool check(vector<lng> vt)
{
    lng i;
    bool flag= 1;
    lng diff= vt[vt.size()-1]- vt[vt.size()-2];
    for(i= vt.size()-2; i>=1; i--)
    {
        if((vt[i]- vt[i-1])!= diff)
        {
            flag= 0;
            break;
        }
    }
    return flag;
}

int main()
{
    lng n;
    set<lng> st;
    lng i;
    scanf("%lld", &n);

    for(i= 1; i<=n; i++)
    {
        lng x;
        scanf("%lld", &x);
        st.insert(x);
        v[x].pb(i);
    }
    map<lng, lng> mp;
    forit(it, st)
    {
        lng val= *it;
        if(v[val].size()== 1) mp[val]= 0;
        else
        {
            if(check(v[val]))
            {
                mp[val]= v[val][1]- v[val][0];
            }
        }
    }

    cout<<mp.size()<<"\n";
    forit(it, mp)
    {
        cout<<it->first<<" "<<it->second<<"\n";
    }

    return 0;
}


