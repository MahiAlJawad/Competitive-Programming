#include<iostream>
using namespace std;

int f91(int n)
{
    int x;
    if(n<=100)
        x= f91(f91(n+11));
    else
        x= n-10;
    return x;
}

int main()
{
    int num, m;
    while(cin>> num && num!= 0)
    {
        m= f91(num);
        cout<< "f91("<<num<<") = "<<m<<endl;
    }
    return 0;
}
