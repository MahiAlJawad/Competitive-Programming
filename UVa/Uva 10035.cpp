#include<iostream>
using namespace std;

int main()
{
    long long m, n, a, b, sum, s, c;
    while(cin>> m>> n)
    {
        if(m== 0 && n== 0)
            break;
        sum= m+n;
        c= 0;
        while(sum)
        {
            a= m%10;
            m/=10;
            b= n%10;
            n/=10;
            s= sum%10;
            sum/=10;
            if(s<(a+b))
                c++;
        }
        if(c== 0)
            cout<< "No carry operation.\n";
        else if(c== 1)
            cout<< "1 carry operation.\n";
        else
            cout<< c<<" carry operations.\n";
    }
    return 0;
}
