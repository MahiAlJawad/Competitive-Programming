#include<bits/stdc++.h>
using namespace std;
vector <int> divisors[50];
int n= 50;
int main()
{
    // Generating Divisors in divisors[j]
    int i, j;
    for(i= 1; i<=n; i++)
    {
        for(j= i; j<=n; j+=i)
        {
            divisors[j].push_back(i);
        }
    }
    //Showing some divisors
    for(i= 1; i<=10; i++)
    {
        cout<<"Divisors of "<<i<<" are: ";
        for(j= 0; j<divisors[i].size(); j++)
            cout<< divisors[i][j]<< " ";
        cout<< endl;
    }
    return 0;
}
