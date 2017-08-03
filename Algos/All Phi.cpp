#include<bits/stdc++.h>
using namespace std;
int phi[102];
vector <int> mark(102, 0);
int n= 20;
int main()
{
    //Co-prime or Phi generating
    int i, j;
    for(i= 1; i<=n; i++)
        phi[i]= i;
    mark[1]= 1;// 1 is not prime
    for(i= 2; i<=n; i++)// don't worry about i<=n , cause we must need to run the loop till n to generate phi, hence the loop for the prime need not to be optimized.
    {
        if(!mark[i])// if i is prime
        {
            for(j= i; j<=n; j+= i)// cause, in j where i reaches , there i is a prime factor of j
            {
                mark[j]= 1;
                phi[j]= (phi[j]/i)*(i-1);
            }
        }
    }

    // Showing
    for(i= 1; i<=20; i++)
        cout<<"Phi("<<i<<")="<<phi[i]<<endl;
}
