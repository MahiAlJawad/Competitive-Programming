#include<stdio.h>

int main()
{
    long long a, b, i, l, x, y, temp, max, n;
    while(scanf("%lld %lld", &a, &b)== 2)
    {



        if(a== 0 && b==  0) break;


        if(a>b)
        {
            temp= a;
            a= b;
            b= temp;
        }



        max= 0;
        n= 0;
        for(i= a; i<=b; i++)
        {
            x= i;
            y= i;
            l= 0;
            while(1)
            {
                if(x%2== 0)
                {
                    x= x/2;
                    l++;
                }
                else
                {
                    x= 3*x+1;
                    l++;
                }
                if(x== 1) break;

            }
            if(l>max)
            {
                max= l;
                n= y;

            }

        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", a, b, n, max);

    }
    return 0;
}
