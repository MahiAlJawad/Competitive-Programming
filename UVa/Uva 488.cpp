#include<iostream>
using namespace std;
int main()
{
    int t, a, f, i, j, k;
    cin>> t;

    while(t--)
    {
        cin>> a>>f;
        for(i= 1; i<= f; i++)
        {
            if(i== f)
            {
                for(j= 1; j<= a; j++)
                {
                    k= j;
                    while(k)
                    {
                        cout<<j;
                        k--;
                    }
                    cout<<endl;
                }
                for(j= a-1; j>=1; j--)
                {
                    k= j;
                    while(k)
                    {
                        cout<< j;
                        k--;
                    }
                    cout<<endl;
                }
            }
            else
            {
                for(j= 1; j<= a; j++)
                {
                    k= j;
                    while(k)
                    {
                        cout<<j;
                        k--;
                    }
                    cout<<endl;
                }
                for(j= a-1; j>=1; j--)
                {
                    k= j;
                    while(k)
                    {
                        cout<< j;
                        k--;
                    }
                    cout<<endl;
                }
                cout<< endl;
            }
        }
        if(t)
            cout<< endl;
    }
    return 0;
}
