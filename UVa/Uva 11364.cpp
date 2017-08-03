#include<iostream>
using namespace std;
int main()
{
    int t, i, n, x , mx, mn, a;
    cin>> t;

    while(t--)
    {
        cin>> n;
        mx= -1;
        mn= 100;
        for(i=1; i<=n; i++)
        {
            cin>> x;
            if(x>mx)
                mx= x;
            if(x<mn)
                mn= x;
        }
        a= mx-mn;
        cout<< 2*a<< endl;
    }
    return 0;
}
