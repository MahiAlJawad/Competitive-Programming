/***"In the name of Allah(swt), the most gracious, most merciful. Allah(swt) blesses with knowledge whom he wants."***/
/*Header file starts here*/
//#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iterator>
#include<cctype>
#include<climits>
#include<string>
#include<sstream>
#include<cstring>
#include<ctime>
/*Header file ends here*/

/*Macro starts here*/
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define fin(in) freopen("in.txt", "r", stdin)
#define fout(out) freopen("out.txt", "w", stdout)
#define pb push_back
#define ll long long
#define lld I64d//for CF submissions
#define rh cout<<"Reached Here\n"
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define forit(it,s) for(__typeof((s).end()) it=(s).begin(); it!= (s).end(); it++)
#define string_reverse(s) reverse(s.begin(), s.end())//Vector also can be reversed with this function
#define memz(x) memset(x, 0, sizeof(x));
#define memneg(x) memset(x, -1, sizeof(x));

//Geometry & Maths
#define gcd(a,b) __gcd(a,b)
#define lcm(a, b) (a*b)/gcd(a, b)
#define pi acos(-1.0)
#define negmod(ans, x, m) ll y= (-1*x)%m; if(y== 0) ans= 0; else ans= m-y;//for negative mod only i.e. when x<0. Undefined when m<0
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c))//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
#define pointPos(x1, y1, x2, y2, x3, y3) ((x2-x1)*(y3-y1))-((x3-x1)*(y2-y1));/*returns NEGATIVE if the Point P3 is on the RIGHT side of the line P1P2,
otherwise returns POSITIVE in case of LEFT and ZERO when the point is on the line*/
#define t_areaWithPoints(x1, y1, x2, y2, x3, y3) abs(0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));//returns the area of a triangle formed by P1, p2, p3

//Base Conversions
#define toBin(bin, n) bin= bitset<8>(n).to_string()//returns a corresponding 8 bit Binary string 'bin' of integer 'n'
#define toOct(oct, n, ch) /*char ch[100]*/sprintf(ch, "%o", n); oct= ch;//returns a string 'oct'(maximum 100 length): Octal represent of number 'n'
#define toHex(hex, n, ch) /*char ch[100]*/sprintf(ch, "%x", n); hex= ch;//returns a string 'hex'(maximum 100 length): Hexadecimal represent of number 'n'
#define intToString(s, n, itos) /*stringstream itos;*/ itos<<n; s= itos.str();//converts a number 'n' to a string 's'
#define stringToint(n, s) stringstream stoi(s); stoi>>n;//converts a string 's' to a number 'n'---ONLY ONCE USABLE---

//Others
#define substring(s1, s2) strstr(s1.c_str(), s2.c_str())//returns true if s1 contains s2 in O(n^2) complexity
#define strCharRemove(s, c) s.erase(remove(s.begin(), s.end(), c), s.end());//Removes all character 'c' from the string 's'
#define strLastCharRemove(s) s.erase(s.end()-1)//Removes last(position is given by s.end()-1) character form string 's'
#define vectorEraseSingle(v, pos) v.erase(v.begin()+pos)//Erases an element from "pos' position in zero based index from the vector 'v'
#define vectorEraseRange(v, spos, fpos) v.erase(v.begin()+spos, v.begin()+fpos)//Erases range inclusive spos' to EXCLUSIVE(without) 'fpos' from vector 'v'
#define lowerBound(v, elem) (lower_bound(v.begin(), v.end(), elem))-v.begin();/*returns the lower bound of 'elem' in integer(ZERO BASED INDEX), where lower bound means
the LEFTMOST index where there is any integer which is GREATER OR EQUAL to 'elem'.*/
#define upperBound(v, elem) (upper_bound(v.begin(), v.end(), elem))-v.begin();/*returns the upper bound of 'elem' in integer(ZERO BASED INDEX), where upper bound means
the LEFTMOST index where there is any integer which is GREATER than 'elem'.*/
#define setLowerBound(st, elem) st.lower_bound(elem);/*returns the lower bound ITERATOR of 'elem' in the stl set 'st', where lower bound means
the LEFTMOST index where there is any integer which is GREATER OR EQUAL to 'elem'.*/
#define setUpperBound(st, elem) st.upper_bound(elem);/*returns the upper bound ITERATOR of 'elem' in the stl set 'st', where upper bound means
the LEFTMOST index where there is any integer which is GREATER than 'elem'.*/
#define clearPQ(pq, type) pq= priority_queue<type>()/*It clears a priority queue by redeclaration*/
#define minPQ(PQ_name, type) priority_queue<type, vector<type>, greater<type> > PQ_name;/*min priority queue with built in type i.e int or long long etc. */
#define sortArr(arr, sz) sort(arr+1, arr+(sz+1));/*Sorts an array from index 1 to index 'sz'*/
/*Macro ends here*/

/*Frequently used Function starts here*/
//Bit set
/*ll Set(ll mask, ll pos){return mask = (mask OR ((ll)1<<pos));}*//*Sets pos'th bit HIGH of the mask and returns*//**Replace OR by Bitwise OR sign when using**/
bool check(ll mask, ll pos){return (bool)(mask & ((ll)1<<pos));}/*Checks if the pos'th bit is HIGH or not of the mask*/
/*Frequently used Function ends here*/

using namespace std;

ll g[205][205], gsz[205], n, e;
ll color[205];

ll bfs(ll s)
{
    queue<ll> q;
    q.push(s);
    color[s]= 1;
    ll i;
    ll cnt1= 1, cnt2= 0;
    bool flag= 1;
    while(!q.empty())
    {
        ll u= q.front();
        q.pop();
        //cout<<"u: "<<u<<"\n";
        for(i= 0; i<gsz[u]; i++)
        {
            ll v= g[u][i];
            //cout<<"v: "<<v<<" ";
            if(color[v]== -1)
            {
                q.push(v);
                if(color[u]== 1) color[v]= 2, cnt2++;
                else if(color[u]== 2) color[v]= 1, cnt1++;
            }
            else if(color[v]== color[u])
            {
                flag= 0;
            }

        }
        //cout<<endl;
    }
    if(!flag) return -1;
    return min(cnt1, cnt2);
}
int main()
{
    //fasterInOut;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll t;
    scanf("%lld", &t);
    while(t--)
    {
        memz(g);
        memz(gsz);
        memneg(color);

        scanf("%lld%lld", &n, &e);
        ll i;
        for(i= 0; i<e; i++)
        {
            ll u, v;
            scanf("%lld%lld", &u, &v);
            g[u][gsz[u]++]= v;
            g[v][gsz[v]++]= u;
        }
//        cout<<"print graph: \n";
//        for(i= 0; i<n; i++)
//        {
//            cout<<"i "<<i<<": ";
//            for(ll j= 0; j<gsz[i]; j++) cout<<g[i][j]<<" ";
//            cout<<endl;
//        }
        ll cnt= 0;
        for(i= 0; i<n; i++)
        {
            ll ret= 0;
            if(color[i]== -1)
            {
                //cout<<"i: "<<i<<endl;
                ret= bfs(i);
//                cout<<"show color: ";
//                for(ll j= 0; j<n; j++) cout<<color[j]<<" ";
//                cout<<endl;
                if(ret== 0) ret= 1;
            }
            if(ret== -1)
            {
                cnt= -1;
                break;
            }
            else cnt+= ret;
            //cout<<"i: "<<i<<" ret: "<<ret<<"\n";
        }
        printf("%lld\n", cnt);
    }

    return 0;
}


