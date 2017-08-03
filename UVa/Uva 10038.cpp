#include<iostream>
#include<cstdio>
#include<cmath>

int  A[3005], B[3005];

using namespace std;

int main()
{
    int n, i, j, flag;

    while(scanf("%d", &n)!= EOF)
    {
        for(i= 1; i<=n; i++)
            scanf("%d", &A[i]);
        for(i= 1; i<n; i++)
        {
            B[i]= abs(A[i]-A[i+1]);
        }
        for(i=1; i<n; i++)
        {
            for(j= 1; j<n; j++)
            {
                if(i== B[j])
                    B[j]= 1;
            }
        }
        flag= 1;
        for(i= 1; i<n; i++)
        {
            if(B[i]!= 1)
            {
                flag= 0;
                break;
            }
        }
        if(flag== 1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");


    }


    return 0;
}
