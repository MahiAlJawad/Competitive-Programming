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
#define toBin(bin, n) bin= bitset<8>(n).to_string()//returns a corresponding 8 bit Binary string 'bin' of integer 'n'
#define toOct(oct, n, ch) /*char ch[100]*/sprintf(ch, "%o", n); oct= ch;//returns a string 'oct'(maximum 100 length): Octal represent of number 'n'
#define toHex(hex, n, ch) /*char ch[100]*/sprintf(ch, "%x", n); hex= ch;//returns a string 'hex'(maximum 100 length): Hexadecimal represent of number 'n'
#define negmod(ans, x, m) ll y= (-1*x)%m; if(y== 0) ans= 0; else ans= m-y;//for negative mod only i.e. when x<0. Undefined when m<0
#define intToString(s, n, itos) /*stringstream itos;*/ itos<<n; s= itos.str();//converts a number 'n' to a string 's'
#define stringToint(n, s) stringstream stoi(s); stoi>>n;//converts a string 's' to a number 'n'---ONLY ONCE USABLE---
#define substring(s1, s2) strstr(s1.c_str(), s2.c_str())//returns true if s1 contains s2 in O(n^2) complexity
using namespace std;


void bfs(ll src, ll dst, vector<ll> adj[], ll par[])
{
    queue<ll> q;
    par[src]= 0;
    q.push(src);

    while(!q.empty())
    {
        ll u= q.front();
        q.pop();
        if(u== dst) break;
        ll lim= adj[u].size(), i;

        for(i= 0; i<lim; i++)
        {
            ll v= adj[u][i];
            if(par[v]== -1)
            {
                par[v]= u;
                q.push(v);
            }
        }
    }

}



int main()
{
    ll n, tc= 1;
    //fin(in);
    //fout(out);
    while(scanf("%lld", &n)== 1)
    {
        if(tc!= 1) printf("\n");
        tc++;
        map<string, ll> mp;
        map<ll, string> m;
        vector<ll> adj[100005];
        ll par[100005];
        memset(par, -1, sizeof(par));

        ll p= 1;
        while(n--)
        {
            string s, t;
            cin>>s>>t;
            if(mp[s]== 0)
            {
                mp[s]= p;
                m[p]= s;
                p++;
            }
            if(mp[t]== 0)
            {
                mp[t]= p;
                m[p]= t;
                p++;
            }
            adj[mp[s]].pb(mp[t]);
            adj[mp[t]].pb(mp[s]);
        }

        string src, dst;
        cin>>src>>dst;
        ll a= mp[src];
        ll b= mp[dst];
        if(a== 0 && b== 0)
        {
            printf("No route\n");
            continue;
        }
        //cout<<" a: "<<a<< " b: "<<b<< " par[b]: "<<par[b]<< endl;
        bfs(a, b, adj, par);
        //cout<<" a: "<<a<< " b: "<<b<< " par[b]: "<<par[b]<< endl;
        vector<ll> ans;
        ans.pb(b);
        if(par[b]== -1)
        {
            printf("No route\n");
        }
        else
        {
            while(1)
            {
                ans.pb(par[b]);
                b= par[b];
                if(par[b]== 0) break;
            }
        }

        string_reverse(ans);
        ll lim= ans.size(), i;

        for(i= 1; i<lim; i++)
        {
            ll x= ans[i-1];
            ll y= ans[i];
            cout<<m[x]<< " "<<m[y]<<"\n";
        }
    }

    return 0;
}


