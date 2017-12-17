#include<bits/stdc++.h>
using namespace std;

string pr, lp;
map<string, set<string> > m;
map<string, int> st;

struct project
{
    string s;
    int n;
};

vector<project> v;

bool operator < (const project &a, const project &b)
{
    if(a.n== b.n) return (a.s<b.s);
    else return (a.n>b.n);
}

int main()
{
    while(getline(cin, pr) && pr!= "0")
    {
        lp= pr;

        while(pr!= "1")
        {
            if(islower(pr[0]))
            {
                m[lp].insert(pr);
            }
            else
            {
                lp= pr;
                m[lp];
            }
            getline(cin, pr);
        }

        map<string, set<string> >:: iterator it1;
        set<string> :: iterator it2;
        for(it1= m.begin(); it1!= m.end(); it1++)
        {
            for(it2= m[it1->first].begin(); it2!= m[it1->first].end(); it2++)
            {
                st[*it2]++;
            }
        }

        int cnt;
        for(it1= m.begin(); it1!= m.end(); it1++)
        {
            cnt= 0;
            for(it2= m[it1->first].begin(); it2!= m[it1->first].end(); it2++)
            {

                if(st[*it2]== 1)
                {
                    cnt++;
                }
            }

            project c;
            c.s= it1->first;
            c.n= cnt;

            v.push_back(c);
        }

        sort(v.begin(), v.end());

        vector<project> :: iterator it;
        for(it= v.begin(); it!= v.end(); it++)
        {
            project x= *it;
            cout<< x.s;
            printf(" %d\n", x.n);
        }

        v.clear();
        m.clear();
        st.clear();

    }
    return 0;
}
