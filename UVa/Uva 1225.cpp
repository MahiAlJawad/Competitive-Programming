#include<iostream>
using namespace std;
int main()
{
    int n , t, i, j, k, a[15];
    cin>> t;
    while(t--)
    {
        cin>> n;
        for(i= 0; i<10; i++)
        {
            a[i]= 0;
        }

        for(i= 1; i<=n; i++)
        {
            k= i;
            while(k>0)
            {
                j= k%10;
                a[j]++;
                k/= 10;
            }
        }
        for(i= 0; i<10; i++)
        {
            cout<< a[i]<<" ";
        }
        cout<< "\n";
    }
    return 0;
}
