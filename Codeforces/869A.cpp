#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, c= 0, m, a, b;
    vector<int> x, y;
    vector<int> v;
    scanf("%d", &n);
    for(i= 1; i<=n; i++)
    {
        scanf("%d", &a);
        x.push_back(a);
        v.push_back(a);
    }
    for(i= 1; i<=n; i++)
    {
        scanf("%d", &b);
        y.push_back(b);
        v.push_back(b);
    }

    for(i= 0; i<n; i++)
    {
        for(j= 0; j<n; j++)
        {
            m= x[i]^y[i];
            if(binary_search(v.begin(), v.end(), m))
                c++;
        }
    }
    if(c%2== 0)
        printf("Karen\n");
    else
        printf("Koyomi\n");

    return 0;

}
