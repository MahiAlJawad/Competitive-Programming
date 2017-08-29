#include<bits/stdc++.h>
using namespace std;
int n= 12;
map <int, int> factor;
int main()
{
    //Generating prime factors of n
    int i, j, num, p;
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
    //Generating SOD & NOD from the Prime Factors
    map <int, int> :: iterator it;
    int nod= 1, sod= 1;
    for(it= factor.begin(); it!=factor.end(); it++)
    {
        nod*= (it->second+1);
        p= 0;
        for(j= 0; j<= it->second; j++)
        {
            p+= pow(it->first, j);
        }
        sod*= p;
    }

    //Showing SOD & NOD
    cout<< "NOD: "<<nod<<endl<<"SOD: "<<sod<<endl;

}
