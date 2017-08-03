#include<bits/stdc++.h>
using namespace std;
vector <int> prime;
vector <int> mark(1000005, 0);
int n= 1000000;
int main()
{
    //Generating primes
    int num, i, j;
    int limit= sqrt(n+1);
    mark[1]= 1;
    prime.push_back(2);
    for(i= 4; i<=n; i+= 2)
        mark[i]= 1;

    for(i= 3; i<=n; i+= 2)
    {
        if(!mark[i])
        {
            prime.push_back(i);
            if(i<= limit)
            {
                for(j= i*i; j<= n; j+= 2*i)
                mark[j]= 1;
            }
        }
    }
    //Showing primes;
    for(i= 0; i<10; i++)
        cout<< prime[i]<< " ";


    return 0;
}
