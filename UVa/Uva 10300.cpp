#include<iostream>
using namespace std;
int main()
{
    int n, f, i, j, a, b, c, budget;

    while(cin>> n)
    {
        for(i= 1; i<=n; i++)
        {
            cin>> f;
            budget= 0;
            for(j= 1; j<=f; j++)
            {
                cin>> a>>b>> c;
                budget+= a*c;
            }
            cout<< budget<<endl;
        }
    }
    return 0;
}
