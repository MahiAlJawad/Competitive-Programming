#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc= 0, t;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    char c;
    scanf("%c", &c);
    while(t--)
    {
        printf("Case %d:\n", ++tc);
        string s;
        stack<string> fw;
        stack<string> bw;
        string current= "http://www.lightoj.com/";
        while(getline(cin, s))
        {
            istringstream is(s);
            string a, b;
            is>>a;
            is>>b;
            if(a== "QUIT") break;
            else if(a== "BACK")
            {
                if(bw.empty()) printf("Ignored\n");
                else
                {
                    fw.push(current);
                    current= bw.top();
                    bw.pop();
                    cout<<current<<"\n";
                }
            }
            else if(a== "FORWARD")
            {
                if(fw.empty()) printf("Ignored\n");
                else
                {
                    bw.push(current);
                    current= fw.top();
                    fw.pop();
                    cout<<current<<"\n";
                }
            }
            else
            {
                bw.push(current);
                current= b;
                while(!fw.empty())
                {
                    fw.pop();
                }
                cout<<current<<"\n";
            }
        }
    }
    return 0;
}
