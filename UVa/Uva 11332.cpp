#include<iostream>
using namespace std;

int func(long long n)
{
    long long s=0;
    while(n)
    {
        s+= n%10;
        n= n/10;
    }
    return s;
}

int main()
{
    long long sum, num;

    while(1)
    {
        cin>> num;
        if(num== 0)
            break;
        sum= num;
        while(sum/10!= 0)
        {
            sum= func(sum);
        }
        cout<< sum<< endl;
    }
    return 0;
}
