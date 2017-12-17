#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,  i, flag;
    char c;
    string s;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt",  "w", stdout);

    scanf("%d ", &n);
    while(n--)
    {
        getline(cin, s);
        stack<char> st;
        int slen= s.size();
        flag= 1;
        for(i= 0; i<slen; i++)
        {
            if(s[i]== '(' || s[i]== '[') st.push(s[i]);
            else if(!st.empty())
            {
                c=st.top();
                if(s[i]== ')' && c== '(') st.pop();
                else if(s[i]== ']' && c== '[') st.pop();
                else
                {
                    flag= 0;
                    break;
                }
            }
            else if(st.empty())
            {
                flag= 0;
                break;
            }
        }
        if(!st.empty()) flag= 0;

        if(flag) printf("Yes\n");
        else printf("No\n");
    }

    return  0;
}
