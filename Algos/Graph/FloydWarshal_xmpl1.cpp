//Uva 10171
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
else returns POSITIVE in case of LEFT and ZERO when the point is on the line*/
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

/*Macro ends here*/
//add vector descending sorting , min pq

using namespace std;
ll n;
ll yng[30][30], agd[30][30], res[30];
ll add(ll x, ll y)
{
    if(x== -1 || y== -1) return -1;
    else return (x+y);
}
void floydwarshal(ll matrix[30][30], ll n)
{
    ll i, j, k;
    for(k= 1; k<=n; k++)
    {
        for(i= 1; i<=n; i++)
        {
            for(j= 1; j<=n; j++)
            {
                if(matrix[i][j]== -1)
                {
                    matrix[i][j]= add(matrix[i][k], matrix[k][j]);
                }
                else
                {
                    ll x= add(matrix[i][k], matrix[k][j]);
                    if(x!= -1 && x<matrix[i][j]) matrix[i][j]= x;
                }
            }
        }
    }
}

int main()
{
    ll i, j;
    //fin(in);
    //fout(out);
    while(scanf("%lld", &n)== 1 && n!= 0)
    {
        string s;
        getchar();
        map<char, ll> mp1;
        map<ll, char> mp2;
        ll k= 1;
        memneg(yng);
        memneg(agd);

        for(i= 1; i<=26; i++)
        {
            yng[i][i]= 0;
            agd[i][i]= 0;
        }
        while(n--)
        {
            getline(cin, s);
            ll cst;
            string t= s;
            vectorEraseRange(t, 0, 8);

            stringstream stoi(t);
            stoi>>cst;
            //cout<<s[0]<<"-"<<s[2]<<"-"<<s[4]<<"-"<<s[6]<<"-"<<cst<<endl;
            if(s[0]== 'Y')
            {
                char c1= s[4];
                char c2= s[6];
                if(mp1[c1]== 0)
                {
                    mp1[c1]= k;
                    mp2[k]= c1;
                    k++;
                }
                if(mp1[c2]== 0)
                {
                    mp1[c2]= k;
                    mp2[k]= c2;
                    k++;
                }
                if(s[2]== 'U')
                {
                    ll x= mp1[c1];
                    ll y= mp1[c2];
                    if(yng[x][y]== -1)
                    {
                        yng[x][y]= cst;
                    }
                    else
                    {
                        if(yng[x][y]>cst) yng[x][y]= cst;
                    }
                }
                else
                {
                    ll x= mp1[c1];
                    ll y= mp1[c2];
                    if(yng[x][y]== -1)
                    {
                        yng[x][y]= cst;
                    }
                    else
                    {
                        if(yng[x][y]>cst) yng[x][y]= cst;
                    }

                    if(yng[y][x]== -1)
                    {
                        yng[y][x]= cst;
                    }
                    else
                    {
                        if(yng[y][x]>cst) yng[y][x]= cst;
                    }
                }
            }//'Y' ends
            else
            {
                char c1= s[4];
                char c2= s[6];
                if(mp1[c1]== 0)
                {
                    mp1[c1]= k;
                    mp2[k]= c1;
                    k++;
                }
                if(mp1[c2]== 0)
                {
                    mp1[c2]= k;
                    mp2[k]= c2;
                    k++;
                }
                if(s[2]== 'U')
                {
                    ll x= mp1[c1];
                    ll y= mp1[c2];
                    if(agd[x][y]== -1)
                    {
                        agd[x][y]= cst;
                    }
                    else
                    {
                        if(agd[x][y]>cst) agd[x][y]= cst;
                    }
                }
                else
                {
                    ll x= mp1[c1];
                    ll y= mp1[c2];
                    if(yng[x][y]== -1)
                    {
                        agd[x][y]= cst;
                    }
                    else
                    {
                        if(agd[x][y]>cst) agd[x][y]= cst;
                    }

                    if(agd[y][x]== -1)
                    {
                        agd[y][x]= cst;
                    }
                    else
                    {
                        if(agd[y][x]>cst) agd[y][x]= cst;
                    }
                }
            }//"M' ends
        }//edge taking ends

        char ss, tt;
        cin>>ss>>tt;


        ll me= mp1[ss];
        ll he= mp1[tt];

        /*cout<<"print map: \n";
        forit(it, mp1)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<"print yng: \n";
        for(i= 1; i<=5; i++)
        {
            for(j= 1; j<=5; j++) cout<<yng[i][j]<<" ";
            cout<<endl;
        }

        cout<<"\n\nprint yng: \n";
        for(i= 1; i<=5; i++)
        {
            for(j= 1; j<=5; j++) cout<<agd[i][j]<<" ";
            cout<<endl;
        }*/

        floydwarshal(yng, (k-1));
        floydwarshal(agd, (k-1));

        memz(res);
        ll mn= inf;
        for(i= 1; i<=(k-1); i++)
        {
            res[i]= add(yng[me][i], agd[he][i]);
            if(res[i]!= -1 && res[i]<mn) mn= res[i];
        }

        vector<char> ans;

        if(mn== inf) cout<<"You will never meet.\n";
        else
        {
            for(i= 1; i<=(k-1); i++)
            {
                if(res[i]== mn)
                {
                    char cc= mp2[i];
                    ans.pb(cc);
                }
            }
            sort(ans.begin(), ans.end());
            cout<<mn<<" ";
            ll sz= ans.size();
            for(i= 0; i<sz; i++)
            {
                char cc= ans[i];
                if(i!= 0) cout<<" ";
                cout<<cc;
            }
            cout<<"\n";
        }
    }

    return 0;
}







/*Sample input
4
Y U A B 4//Here A and B are node names, Y is the type of graph, and U/B indicates Unidirectional or bidirectional.
Y U C A 1
M U D B 6
M B C D 2
A D
2
Y U A B 10
M U C D 20
A D
0

Sample Output
10 B
You will never meet.

*/
