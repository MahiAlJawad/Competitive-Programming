#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc= 1, t, i;
    char c;
    string s, st;

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    c= getchar();
    c= getchar();
    while(t--)
    {

        if(tc!= 1) printf("\n");
        tc++;
        st= "";
        while(getline(cin, s) && s.size()!= 0)
        {
            st+= s;
        }
        st+= ')';

        stack<char> k;
        k.push('(');
        int stsize= st.size();
        for(i= 0; i<stsize; i++)
        {
            if(st[i]>= 48 && st[i]<=57) cout<< st[i];
            else
            {
                if(st[i]== ')')
                {
                    while(1)
                    {
                        if(k.top()== '(')
                        {
                            k.pop();
                            break;
                        }
                        cout<<k.top();
                        k.pop();
                    }
                }
                else if(st[i]== '+' || st[i]== '-')
                {
                    if(k.top()== '(')
                    {
                        k.push(st[i]);
                    }
                    else
                    {
                        while(1)
                        {
                            if(k.top()== '(')
                            {
                                break;
                            }
                            else
                            {
                                cout<<k.top();
                                k.pop();
                            }
                        }
                        k.push(st[i]);
                    }
                }
                else if(st[i]== '*' || st[i]== '/')
                {
                    if(k.top()== '*' || k.top()== '/')
                    {
                        while(1)
                        {
                            if(k.top()== '+' || k.top()== '-' || k.top()== '(') break;
                            else
                            {
                                cout<<k.top();
                                k.pop();
                            }
                        }
                    }
                    k.push(st[i]);
                }
                else k.push(st[i]);
            }
        }
        cout<<"\n";
    }

    return 0;
}
