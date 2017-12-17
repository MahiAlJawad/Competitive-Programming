#include<bits/stdc++.h>
using namespace std;

int w[1005], c[1005], n, mx;

int knapsack(int v[1005][35], int i, int wt)
{
    int profit1, profit2;
    if(i== n+1) return 0;

    if(v[i][wt]== -1)
    {
         if(wt+ w[i]<= mx)
         {
             profit1= c[i]+ knapsack(v, i+1, wt+ w[i]);
         }
         else profit1= 0;

         profit2= knapsack(v, i+1, wt);

         v[i][wt]= max(profit1, profit2);
         return v[i][wt];
    }
    else return v[i][wt];
}

int main()
{
    int t, i, g, weight;

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &t);

    while(t--)
    {

        //memset(c, 0, sizeof(c));
        //memset(w, 0, sizeof(w));
        scanf("%d", &n);
        for(i= 0; i<n; i++)
        {
            scanf("%d%d", &c[i], &w[i]);
        }

        scanf("%d", &g);
        weight= 0;

        for(i= 1; i<= g; i++)
        {
            scanf("%d", &mx);
            int v[1005][35];
            memset(v, -1, sizeof(v));
            weight+= knapsack(v, 0, 0);
        }
        printf("%d\n", weight);
    }

    return 0;
}
