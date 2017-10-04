#include<bits/stdc++.h>
#define mx 100005
using namespace std;
int arr[mx];
int tree[3*mx];
int oldvalue= 0;

void  init(int n, int b, int e)
{
    if(b== e)
    {
        tree[n]= arr[b];
        return;
    }
    int l= 2*n;
    int r= l+1;
    int m= (b+e)/2;
    init(l, b, m);
    init(r, m+1, e);
    tree[n]= tree[l]+tree[r];
}

int query(int n, int b, int e, int i, int j)
{
    if(b>j || e<i) return 0;
    if(b>= i && e<= j) return tree[n];
    int l= 2*n;
    int r= l+1;
    int m= (b+e)/2;
    int p1= query(l, b, m, i, j);
    int p2= query(r, m+1, e, i, j);
    return p1+p2;
}

void update(int n, int b, int e, int i, int newvalue, bool f)
{
    if(i>e || i<b) return;
    if(b==e)
    {
        oldvalue= tree[n];
        if(f) tree[n]+= newvalue;
        else tree[n]= newvalue;
        return;
    }
    int l= 2*n;
    int r= l+1;
    int m= (b+e)/2;
    update(l, b, m, i, newvalue, f);
    update(r, m+1, e, i, newvalue, f);
    tree[n]= tree[l]+tree[r];
}

int main()
{
    int n, q, t, c, tc= 0, i, x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &q);
        for(i= 1; i<=n; i++)
            scanf("%d", &arr[i]);
        init(1, 1, n);
        printf("Case %d:\n", ++tc);
        for(i= 1; i<=q; i++)
        {
            scanf("%d", &c);
            if(c== 1)
            {
                scanf("%d", &x);
                update(1, 1, n, x+1, 0, 0);
                printf("%d\n", oldvalue);
            }
            else if(c== 2)
            {
                scanf("%d%d", &x, &y);
                update(1, 1, n, x+1, y, 1);
            }
            else
            {
                scanf("%d%d", &x, &y);
                printf("%d\n", query(1, 1, n, x+1, y+1));
            }
        }
    }
    return 0;
}
