#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t, i, x[1005], sum;
    double mean, count, n, abovemean;
    cin>> t;
    while(t--)
    {
        cin>> n;
        sum= 0;
        for(i= 1; i<= n; i++)
        {
            cin>> x[i];
            sum+= x[i];
        }
        mean= (sum/n);

        count= 0;
        for(i= 1; i<=n; i++)
        {
            if(x[i]>mean)
                count++;
        }

        abovemean= (count/n)*100;

        printf("%0.3lf%%\n", abovemean);
    }
    return 0;
}
