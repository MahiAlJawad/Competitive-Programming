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
#define inf LONG_LONG_MAX
#define neginf LONG_LONG_MIN
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
#define setLowerBound(st, elem) st.lower_bound(elem));/*returns the lower bound ITERATOR of 'elem' in the stl set 'st', where lower bound means
the LEFTMOST index where there is any integer which is GREATER OR EQUAL to 'elem'.*/
#define setUpperBound(st, elem) st.upper_bound(elem));/*returns the upper bound ITERATOR of 'elem' in the stl set 'st', where upper bound means
the LEFTMOST index where there is any integer which is GREATER than 'elem'.*/
#define clearPQ(pq, type) pq= priority_queue<type>()/*It clears a priority queue by redeclaration*/
#define minPQ(PQ_name, type) priority_queue<type, vector<type>, greater<type> > PQ_name;/*min priority queue with built in type i.e int or long long etc. */
#define sortArr(arr, sz) sort(arr+1, arr+(sz+1));/*Sorts an array from index 1 to index 'sz'*/
/*Macro ends here*/
//add vector descending sorting

using namespace std;

bool visited[10005];
int parent[10005], low[10005], d[10005], t= 0;
int isArticulationB[10005][10005], taken[10005][10005];
vector<vector<int>> g;


struct edge
{
    int u, v;
    edge(int a, int b)
    {
        u= a;
        v= b;
    }
    bool operator <(const edge e) const
    {
        if(u== e.u) return v<e.v;
        else return u<e.u;
    }
};

//map<edge, bool> isArticulationB;/***Use 2D array if the number of node is not huge***/


void findArticulationBridges(int u)
{
    t++;
    low[u]= t;
    d[u]= t;
    visited[u]= 1;
    int i, v;

    for(i= 0; i<g[u].size(); i++)
    {
        v= g[u][i];
        if(v== parent[u]) continue;
        if(visited[v]) low[u]= min(low[u], d[v]);//back-edge
        else
        {
            parent[v]= u;
            findArticulationBridges(v);
            low[u]= min(low[u], low[v]);
            if(d[u]<low[v])
            {
                isArticulationB[u][v]= 1;
                isArticulationB[v][u]= 1;
            }
        }
    }
}

void clearall()
{
    t= 0;
    memz(visited);
    memz(parent);
    memz(low);
    memz(d);
    memz(isArticulationB);
    memz(taken);
}

int main()
{
    /***Check the constrains again, use appropriate data type***/
    //fin(in);
    //fout(out);
    //fasterInOut;
    int n, tc= 1;
    while(scanf("%d", &n)== 1)
    {
        clearall();
        int i, j;
        vector<edge> edg;
        g= vector<vector<int>> (n+5);
        for(i= 1; i<=n; i++)
        {
            int u;
            scanf("%d", &u);
            char c;
            cin>>c;
            int k;
            scanf("%d", &k);
            cin>>c;
            for(j= 1; j<=k; j++)
            {
                int v;
                scanf("%d", &v);
                int u1= u;
                int v1= v;
                if(v1<u1) swap(u1, v1);
                if(!taken[u1][v1])
                {
                    taken[u1][v1]= 1;
                    g[u1].pb(v1);
                    g[v1].pb(u1);
                    edg.pb(edge(u1, v1));
                }
            }
        }
        for(i= 0; i<n; i++)
        {
            if(!visited[i])
            {
                findArticulationBridges(i);
            }
        }
        sort(edg.begin(), edg.end());
        int cnt= 0;
        for(i= 0; i<edg.size(); i++)
        {
            int u= edg[i].u;
            int v= edg[i].v;
            if(isArticulationB[u][v]) cnt++;
        }
        //if(tc!= 1) printf("\n");
        //tc++;
        printf("%d critical links\n", cnt);

        for(i= 0; i<edg.size(); i++)
        {
            int u= edg[i].u;
            int v= edg[i].v;
            if(isArticulationB[u][v]) printf("%d - %d\n", u, v);
        }
        printf("\n");
    }
    return 0;
}

/*
Test Case:


8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0

2

0 (1) 1
1 (1) 0

*/
