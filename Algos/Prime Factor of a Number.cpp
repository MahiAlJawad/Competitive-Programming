#include<bits/stdc++.h>
using namespace std;
int n= 20;
map <int, int> factor;
int main()
{
    //Generating prime factors of n
    int i, j, num;
    num= n;// saving n, so that it doesn't manipulate
    for(i= 2; i*i<=n; i++)
    {
        if(n%i== 0)// n is firstly divisible by a number which is a prime, hence here i is prime if the condition is true
        {
            while(n%i== 0)
            {
                factor[i]++;
                n/= i;
            }
        }
    }
    if(n>1)
    {
        factor[n]++;
    }


    //Showing
    map <int, int> :: iterator it;
    cout<< num<<"= ";
    for(it= factor.begin(); it!= factor.end(); it++)
    {
        cout<<it->first<<"^"<<it->second<<" ";
    }
}
