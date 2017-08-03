#include<iostream>
using namespace std;

int main()
{
    int k, n, m, x, y;
    while(1)
    {
        cin>> k;
        if(k== 0)
            break;
        cin>> m>> n;
        while(k--)
        {
            cin>> x>> y;
            x= x-m;
            y= y-n;
            if(x>0 && y>0)
                cout<< "NE\n";
            else if(x>0 && y<0)
                cout<< "SE\n";
            else if(x<0 && y>0)
                cout<< "NO\n";
            else if(x<0 && y<0)
                cout<< "SO\n";
            else
                cout<< "divisa\n";
        }
    }
    return 0;
}
