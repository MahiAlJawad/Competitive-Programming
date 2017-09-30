#include<bits/stdc++.h>
using namespace std;
int arr[11]= {0, 4, 5, 7, 3, 9, 2, 7, 4, -2, -4};// let's say
int tree[33];
void init(int node, int b, int e)//inits the segment tree with the given array
{
    if(b== e)
    {
        tree[node]= arr[b];
        return;
    }
    int left= 2*node;
    int right= 2*node+1;
    int mid= (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node]= tree[left]+tree[right];
}

int query(int node, int b, int e, int i, int j)// returns the summation of the array from i to j
{
    if(i> e|| j<b)
        return 0;// not relevant segment
    if(b>= i && e<=j)
        return tree[node];//relevant segment
    int left= 2*node;
    int right= 2*node+1;
    int mid= (b+e)/2;
    int p1= query(left, b, mid, i, j);
    int p2= query(right, mid+1, e, i, j);
    return p1+p2;
}

void update(int node, int b, int e, int i, int newvalue)
{
    if(i< b || i>e)
        return;
    if(b== e)
    {
        tree[node]= newvalue;
        return;
    }
    int left= 2*node;
    int right= 2*node+1;
    int mid= (b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    tree[node]= tree[left]+tree[right];
}

int main()
{
    int n= 10;
    init(1, 1, n);

    cout<< query(1, 1, n, 1, n)<<endl;
    cout << query(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 2, 2);
    cout << query(1, 1, n, 1, n) << endl;
    return 0;
}
