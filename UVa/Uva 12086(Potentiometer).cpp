#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int tree[600015];

void init(int node, int b, int e)
{
    if(b== e)
    {
        tree[node]= arr[b];
        return;
    }
    int left= 2*node;
    int right= left+1;
    int mid= (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node]= tree[left]+tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(e<i || j<b) return 0;
    if(b>= i && e<=j) return tree[node];
    int left= 2*node;
    int right= left+1;
    int mid= (b+e)/2;
    int p1= query(left, b, mid, i, j);
    int p2= query(right, mid+1, e, i, j);
    return p1+p2;
}
 void update(int node, int b, int e, int i, int newvalue)
 {
     if(i>e || i<b) return;
     if(b== e)
     {
         tree[node]= newvalue;
         return;
     }
     int left= 2*node;
     int right= left+1;
     int mid= (b+e)/2;
     update(left, b, mid, i, newvalue);
     update(right, mid+1, e, i, newvalue);
     tree[node]= tree[left]+ tree[right];
 }

int main()
{
    int n, tc= 0, i, x, y, r;
    char s[5];
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(scanf("%d", &n) && n!= 0)
    {
        tc++;
        if(tc!= 1) printf("\n");
        for(i= 1; i<= n; i++)
            scanf("%d ", &arr[i]);
        init(1, 1, n);
        printf("Case %d:\n", tc);
        while(scanf("%s", s))
        {
            if(s[0]== 'S')
            {
                scanf("%d %d ", &x, &r);
                update(1, 1, n, x, r);
            }
            else if(s[0]== 'M')
            {
                scanf("%d %d ", &x, &y);
                printf("%d\n", query(1, 1, n, x, y));
            }
            else break;
        }
    }
    return 0;
}
