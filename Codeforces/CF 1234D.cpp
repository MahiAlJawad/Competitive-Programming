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
#define pollPos(x1, y1, x2, y2, x3, y3) ((x2-x1)*(y3-y1))-((x3-x1)*(y2-y1));/*returns NEGATIVE if the Poll P3 is on the RIGHT side of the line P1P2,
otherwise returns POSITIVE in case of LEFT and ZERO when the poll is on the line*/
#define t_areaWithPolls(x1, y1, x2, y2, x3, y3) abs(0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));//returns the area of a triangle formed by P1, p2, p3

//Base Conversions
#define toBin(bin, n) bin= bitset<8>(n).to_string()//returns a corresponding 8 bit Binary string 'bin' of lleger 'n'
#define toOct(oct, n, ch) /*char ch[100]*/sprllf(ch, "%o", n); oct= ch;//returns a string 'oct'(maximum 100 length): Octal represent of number 'n'
#define toHex(hex, n, ch) /*char ch[100]*/sprllf(ch, "%x", n); hex= ch;//returns a string 'hex'(maximum 100 length): Hexadecimal represent of number 'n'
#define llToString(s, n, itos) /*stringstream itos;*/ itos<<n; s= itos.str();//converts a number 'n' to a string 's'
#define stringToll(n, s) stringstream stoi(s); stoi>>n;//converts a string 's' to a number 'n'---ONLY ONCE USABLE---

//Others
#define substring(s1, s2) strstr(s1.c_str(), s2.c_str())//returns true if s1 contains s2 in O(n^2) complexity
#define strCharRemove(s, c) s.erase(remove(s.begin(), s.end(), c), s.end());//Removes all character 'c' from the string 's'
#define strLastCharRemove(s) s.erase(s.end()-1)//Removes last(position is given by s.end()-1) character form string 's'
#define vectorEraseSingle(v, pos) v.erase(v.begin()+pos)//Erases an element from "pos' position in zero based index from the vector 'v'
#define vectorEraseRange(v, spos, fpos) v.erase(v.begin()+spos, v.begin()+fpos)//Erases range inclusive spos' to EXCLUSIVE(without) 'fpos' from vector 'v'
#define lowerBound(v, elem) (lower_bound(v.begin(), v.end(), elem))-v.begin();/*returns the lower bound of 'elem' in lleger(ZERO BASED INDEX), where lower bound means
the LEFTMOST index where there is any lleger which is GREATER OR EQUAL to 'elem'.*/
#define upperBound(v, elem) (upper_bound(v.begin(), v.end(), elem))-v.begin();/*returns the upper bound of 'elem' in lleger(ZERO BASED INDEX), where upper bound means
the LEFTMOST index where there is any lleger which is GREATER than 'elem'.*/
#define setLowerBound(st, elem) st.lower_bound(elem);/*returns the lower bound ITERATOR of 'elem' in the stl set 'st', where lower bound means
the LEFTMOST index where there is any lleger which is GREATER OR EQUAL to 'elem'.*/
#define setUpperBound(st, elem) st.upper_bound(elem);/*returns the upper bound ITERATOR of 'elem' in the stl set 'st', where upper bound means
the LEFTMOST index where there is any lleger which is GREATER than 'elem'.*/
#define clearPQ(pq, type) pq= priority_queue<type>()/*It clears a priority queue by redeclaration*/
#define minPQ(PQ_name, type) priority_queue<type, vector<type>, greater<type> > PQ_name;/*min priority queue with built in type i.e ll or long long etc. */
#define sortArr(arr, sz) sort(arr+1, arr+(sz+1));/*Sorts an array from index 1 to index 'sz'*/
/*Macro ends here*/


using namespace std;

string s;
struct data
{
    ll cnt[30];
};

data tree[400005];
void init(ll node, ll b, ll e)//inits the segment tree with the given array
{
    ll i;
    if(b== e)
    {
        ll x= s[b]-'a';
        for(i= 0; i<26; i++)
        {
            tree[node].cnt[i]= 0;
        }
        tree[node].cnt[x]= 1;
        return;
    }
    ll left= 2*node;
    ll right= 2*node+1;
    ll mid= (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    for(i= 0; i<26; i++)
    {
        tree[node].cnt[i]= tree[left].cnt[i]+tree[right].cnt[i];
    }
}

data query(ll node, ll b, ll e, ll i, ll j)// returns the summation of the array from i to j
{
    //cout<<"b: "<<b<<" e: "<<e<<endl;
    if(i> e|| j<b)
    {
        //cout<<"not relevant\n";
        data temp;
        for(ll k= 0; k<26; k++)
        {
            temp.cnt[k]= 0;
        }

        return temp;
    }
    if(b>= i && e<=j)
    {
       // cout<<"inside query: \n";
//        for(ll k= 0; k<26; k++)
//        {
//            if(tree[node].cnt[k]>0)
//            {
//                cout<<(char)(k+'a')<<" "<<tree[node].cnt[k]<<"\n";
//            }
//        }
        return tree[node];
    }
    ll left= 2*node;
    ll right= 2*node+1;
    ll mid= (b+e)/2;
    data p1= query(left, b, mid, i, j);
    data p2= query(right, mid+1, e, i, j);
    data p;
    for(ll k= 0; k<26; k++)
    {
        p.cnt[k]= p1.cnt[k]+p2.cnt[k];
    }
    return p;
}

void update(ll node, ll b, ll e, ll i, ll newvalue)
{
    ll j;
    if(i< b || i>e) return;
    if(b== e)
    {
        for(j= 0; j<26; j++)
        {
            tree[node].cnt[j]= 0;
        }
        tree[node].cnt[newvalue]= 1;
        return;
    }
    ll left= 2*node;
    ll right= 2*node+1;
    ll mid= (b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);

    for(j= 0; j<26; j++)
    {
        tree[node].cnt[j]= tree[left].cnt[j]+ tree[right].cnt[j];
    }
}


int main()
{
    fasterInOut;
    cin>>s;
    ll len= s.size(), i;
    init(1, 0, len-1);


    ll q;
    cin>>q;
    while(q--)
    {
        ll op, l, r, pos;
        char c;
        cin>>op;
        if(op== 1)
        {
            cin>>pos>>c;
            update(1, 0, len-1, pos-1, (ll)(c-'a'));
        }
        else
        {
            cin>>l>>r;
            data ans= query(1, 0, len-1, l-1, r-1);
            ll cnt= 0;
            for(i= 0; i<26; i++)
            {
                if(ans.cnt[i]>0) cnt++;
//                if(ans.cnt[i]>0)
//                {
//                    cout<<(char)(i+'a')<<" "<<ans.cnt[i]<<"\n";
//                }
            }
            cout<<cnt<<"\n";
        }
    }


    return 0;
}


