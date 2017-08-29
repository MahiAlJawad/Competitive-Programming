#include<bits/stdc++.h>
using namespace std;
int n= 12;
int main()
{
    // Generating Phi for n
    int i, j, phi, num;
    phi= num= n;
    for(i= 2; i*i<=n; i++)
    {
        if(n%i== 0)// if  i is a prime
        {
            while(n%i== 0)
            {
                n/= i;
            }
            phi= (phi/i)*(i-1);
        }
    }
    if(n>1)
    {
        phi= (phi/n)*(n-1);
    }
    // Showing Phi
    cout<<"Phi("<<num<<")= "<<phi<<endl;
}
