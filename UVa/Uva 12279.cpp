#include<iostream>
using namespace std;
int A[1005];
int main()
{
    int n,i, count= 0,  reason, given;

    while(1)
    {
        count++;
        given= 0;
        reason= 0;
        cin>> n;
        if(n== 0)
            break;

        for(i= 1; i<= n; i++)
        {
            cin>> A[i];
            if(A[i]== 0)
                given++;
            else
                reason++;
        }
        cout<< "Case "<<count<<": "<<reason-given<<endl;
    }
    return 0;
}
