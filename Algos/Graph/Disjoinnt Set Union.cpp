#include<bits/stdc++.h>
#define ll long long
#define nsz 105 //max number of nodes
using namespace std;

ll parent[nsz], setsize[nsz];

void makeSet(ll v)
{
    parent[v]= v;
    setsize[v]= 1;
}

ll findSet(ll v)
{
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(ll a, ll b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (setsize[a] < setsize[b]) swap(a, b);
        parent[b] = a;
        setsize[a] += setsize[b];
    }
}

bool isSameSet(ll a, ll b)
{
    if(findSet(a)== findSet(b)) return 1;
    else return 0;
}

ll sizeofSet(ll v)
{
    return setsize[findSet(v)];
}

int main()
{
    ll i;
    for(i= 1; i<=5; i++) makeSet(i);
    unionSet(1, 2);
    cout<<"size of set with node 1 and 2: "<<sizeofSet(1)<<" "<<sizeofSet(2)<<endl;
    if(isSameSet(1, 2)) cout<<"1 and 2 are on the same set\n";
    else cout<<"They are not in the same set\n";
    if(isSameSet(1, 3)) cout<<"1 and 3 are on the same set\n";
    else cout<<"They are not in the same set\n";
    unionSet(2, 5);
    cout<<"size of set with node 1, 2 and 5: "<<sizeofSet(1)<<" "<<sizeofSet(2)<<" "<<sizeofSet(5)<<endl;

}
