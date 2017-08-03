#include<iostream>//Here the comparison can be done with loop also;
#include<cstdio>
using namespace std;

int main()
{
    int t, i, a[15], flag;
    cout<< "Lumberjacks:\n";
    cin>> t;
    while(t--)
    {
        for(i=1; i<=10; i++)
        {
            cin>> a[i];
        }
        if(a[1]>=a[2] && a[2]>=a[3] && a[3]>=a[4] &&a[4]>=a[5] && a[5]>=a[6] && a[6]>=a[7] && a[7]>=a[8] && a[8]>=a[9] && a[9]>=a[10])
            flag= 1;
        else if(a[1]<=a[2] && a[2]<=a[3] && a[3]<=a[4] &&a[4]<=a[5] && a[5]<=a[6] && a[6]<=a[7] && a[7]<=a[8] && a[8]<=a[9] && a[9]<=a[10])
            flag= 1;
        else
            flag= 0;
        if(flag== 1)
            cout<< "Ordered\n";
        else
            cout<< "Unordered\n";
    }
    return 0;
}
