#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i, slen;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(getline(cin, s))
    {
        slen= s.size();
        stack<string> st;
        string x= "";
        string text= "";

        for(i= 0; i<slen; i++)
        {
            if(s[i]== '[')
            {
                i++;
                while(1)
                {
                    if(i== slen || s[i]== ']')
                    {
                        if(x.size()!= 0) st.push(x);
                        x= "";
                        break;
                    }
                    else if(s[i]== '[')
                    {
                        i--;
                        if(x.size()!= 0) st.push(x);
                        x= "";
                        break;
                    }
                    else x+= s[i];
                    i++;
                }
            }
            else if(s[i]!= ']') text+= s[i];
        }
        while(!st.empty())
        {
            cout<< st.top();
            st.pop();
        }
        cout<<text<<"\n";
    }

    return 0;
}
