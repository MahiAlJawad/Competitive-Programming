#include<iostream>
#include<cstdio>

using namespace std;
int main()
{
    int i, t;
    double c, d, farenheit, celcius;

    cin>> t;
    for(i= 1; i<=t; i++)
    {
        cin>> c>> d;
        farenheit= (9*c/5)+32+d;// A bit problem in calculation while the values are putted a bit different form.
        celcius= (5*(farenheit-32))/9;
        printf("Case %d: %.2lf\n",i, celcius);
    }


    return 0;
}
