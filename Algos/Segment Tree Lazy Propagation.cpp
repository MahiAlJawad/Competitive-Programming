#include<bits/stdc++.h>
#define sz 51
using namespace std;

int a[sz]= {0, 4, 1, 2, 3, 9, 8, 7};
int tree[3*sz], prop[3*sz];
void init(int node, int b, int e)
{
    if(b== e)
    {
        tree[node]= a[b];
        return;
    }
    int left= 2*node;
    int right= left+1;
    int mid= (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node]= tree[left] + tree[right];
}
void update(int node, int b, int e, int i, int j, int x)
{
    if(b>j || e<i) return;
    if(b>= i && e<= j)
    {
        prop[node]+= x;
        tree[node]+= ((e-b+1)*x);
        return;
    }
    int left= 2*node;
    int right= left+1;
    int mid= (b+e)/2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);
    tree[node]= tree[left]+ tree[right]+ ((e-b+1)*prop[node]);
}
int query(int node, int b, int e, int i, int j, int carry)
{
    if(b> j || e<i) return 0;
    if(b>= i && e<= j)
    {
        return tree[node] + (e-b+1)*carry;
    }
    int left= 2*node;
    int right= left+1;
    int mid= (b+e)/2;
    int p1= query(left, b, mid, i, j, carry+prop[node]);
    int p2= query(right, mid+1, e, i, j, carry+prop[node]);
    return p1+p2;
}
int main()
{
    int n= 7;
    init(1, 1, n);
    cout<<"a";
    cout<<"before update: \n"<<endl;
    cout<<"summation of i= 2 to j= 4 :"<<query(1, 1, n, 2, 4, 0)<<endl;//query to get the summation from a[2] to a[4]
    cout<<"after adding x= 2 in a[3] to a[5]\n"<<endl;
    update(1, 1, n, 3, 5, 2);//adding 2 with the values of a[3] to a[5]
    cout<<"summation of i= 3 to j= 5 :"<<query(1, 1, n, 3, 5, 0)<<endl;//query to get the summation from a[3] to a[5]
    return 0;
}
