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
//#define lld I64d//for CF submissions
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


using namespace std;

vector<vector<ll> > g;
vector<ll> level;
//map<ll, string> mp1;
ll bfs(ll src, ll dst)
{
    ll i, u, v;
    queue<ll> q;
    q.push(src);
    level[src]= 0;

    while(!q.empty())
    {
        u= q.front();
        //cout<<"Opening: "<<mp1[u]<<" at level "<<level[u]<<" : ";
        q.pop();
        for(i= 0; i<g[u].size(); i++)
        {
            v= g[u][i];
            if(level[v]== -1)
            {
                //cout<<mp1[v]<<" ";
                level[v]= level[u]+1;
                q.push(v);
            }
        }
        //cout<<endl;
    }

    return level[dst];
}

int main()
{
    //fasterInOut;
    fin(in);
    fout(out);
    ll t, i, j, tc= 0;
    scanf("%lld", &t);
    getchar();
    while(t--)
    {
        tc++;
        if(tc!= 1) printf("\n");
        string s;
        vector<string> v;
        i= 1;
        map<string, ll> mp;
        //mp1.clear();
        while(cin>>s && s[0]!= '*')
        {
            v.pb(s);
            mp[s]= i;
            //mp1[i]= s;
            i++;
        }
        getchar();

        g= vector<vector<ll> > ((ll)v.size()+5);
        level= vector<ll> ((ll)v.size()+5, -1);
        for(i= 0; i<v.size(); i++)
        {
            //cout<<"u: "<<v[i]<<endl;

            for(j= i+1; j<v.size(); j++)
            {
                ll d= 0;
                if(v[i].size()!= v[j].size()) continue;
                ll k;
                string a= v[i];
                string b= v[j];
                //cout<<a<<" "<<b<<" ";
                for(k= 0; k<a.size(); k++)
                {
                    if(a[k]!= b[k]) d++;
                }
                //cout<<d<<endl;
                if(d== 1)
                {
                    g[i+1].pb(j+1);
                    g[j+1].pb(i+1);
                }
            }
        }
//        cout<<"data: ";
//        for(i= 0; i<v.size(); i++)
//        {
//            cout<<v[i]<<" ";
//        }
//        cout<<endl;

//        for(i= 1; i<= (ll)v.size(); i++)
//        {
//            cout<<mp1[i]<<" : ";
//            for(j= 0; j<g[i].size(); j++)
//            {
//                cout<<mp1[g[i][j]]<<" ";
//            }
//            cout<<endl;
//        }
        while(getline(cin, s))
        {
            if(s.size()== 0)
            {
                break;
            }
            string a, b;
            stringstream ss(s);
            ss>>a;
            ss>>b;
            ll src= mp[a];
            ll dst= mp[b];
            //cout<<"src: "<<mp1[src]<<" dst: "<<mp1[dst]<<endl;
            level= vector<ll> ((ll)v.size()+5, -1);
            cout<<a<<" "<<b<<" "<<bfs(src, dst)<<"\n";
        }
    }



    return 0;
}


