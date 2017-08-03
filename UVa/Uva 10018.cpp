#include<iostream>
using namespace std;

long long rev(long long n)
{
    long long r= 0, a;
    while(n)
    {
        a= n%10;
        r= r*10+a;
        n/=10;
    }
    return r;
}

int main()
{
    int t, num, rv, sum, c;
    cin>> t;



    while(t--)
    {
        cin>> num;
        c= 0;
        rv= rev(num);
        sum= rv+num;
        num= sum;

        while(1)
        {
            c++;
            rv= rev(num);
            if(rv== num)
                break;
            sum= rv+num;
            num= sum;

        }
        cout<<c<<" "<<rv<<endl;
    }

    return 0;
}
