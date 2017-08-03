//Accepted Uva 12342(Tax Calc.)
#include<stdio.h>
#include<math.h>

int main()
{
    int t, i;
    long long  k;
    double tax;
    scanf("%d", &t);
    for(i= 1; i<=t; i++)
    {
        tax= 0;
        scanf("%lld", &k);
        if(k>180000 && k<=480000) tax= (k-180000)*0.10;
        else if(k>480000 && k<= 880000) tax= (k-480000)*0.15+30000;
        else if(k>880000 && k<= 1180000) tax= (k-880000)*0.20+30000+60000;
        else if(k>1180000) tax= (k-1180000)*0.25+30000+60000+60000;


        if(tax!=0 && tax<2000) tax= 2000;
        else tax= ceil(tax);
        printf("Case %d: %.0f\n", i, tax);

    }



    return 0;
}
