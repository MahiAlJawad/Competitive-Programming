#include<bits/stdc++.h>
#define mx 100005
using namespace std;
int arr[mx];
int tree[3*mx];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]= arr[b];
        return;
    }
    int left= 2*node;
    int right= left+1;
    int mid= (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node]= min(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j)
{
    if(b>j || e<i) return 200000;
    if(b>= i && e<=j) return tree[node];
    int left= 2*node;
    int right= left+1;
    int mid= (b+e)/2;
    int p1= query(left, b, mid, i, j);
    int p2= query(right, mid+1, e, i, j);
    return min(p1, p2);
}

int main()
{
    int t, n, q, i, x, y, tc= 0;
    scanf("%d", &t);
    while(t--)
    {
        tc++;
        scanf("%d%d", &n, &q);
        for(i= 1; i<=n; i++)
            scanf("%d", &arr[i]);

        printf("Case %d:\n", tc);
        init(1, 1, n);
        for(i= 1; i<=q; i++)
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", query(1, 1, n, x, y));
        }
    }
    return 0;
}
